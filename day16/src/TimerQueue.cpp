#include "TimerQueue.h"
#include "EventLoop.h"
#include "Timer.h"
#include "TimerId.h"
#include "Channel.h"
#include <cassert>
#include <sys/timerfd.h>
#include <unistd.h>
#include <stdio.h>
#include <cstring>


int createTimerfd(){
    // int timerfd_create(int clockid, int flags);

    // 第一个参数：clockid指定时间类型，有两个值：
    // CLOCK_REALTIME :Systemwide realtime clock. 系统范围内的实时时钟
    // CLOCK_MONOTONIC:以固定的速率运行，从不进行调整和复位 ,它不受任何系统time-of-day时钟修改的影响

    // 第二个参数
    // NONBLOCK 读时非阻塞
    // CLOEXEC 运行时关闭标志
    int timerfd = ::timerfd_create(CLOCK_MONOTONIC,
                                 TFD_NONBLOCK | TFD_CLOEXEC);
    if (timerfd < 0) {
        std::cout << "Failed in timerfd_create";
    }
    return timerfd;                        
}

// 计算超时时刻与当前时间的时间差
struct timespec howMuchTimeFromNow(Timestamp when)
{
  int64_t microseconds = when.microSecondsSinceEpoch()
                         - Timestamp::now().microSecondsSinceEpoch();
  if (microseconds < 100)
  {
    microseconds = 100;
  }
  struct timespec ts;
  ts.tv_sec = static_cast<time_t>(
      microseconds / Timestamp::kMicroSecondsPerSecond);
  ts.tv_nsec = static_cast<long>(
      (microseconds % Timestamp::kMicroSecondsPerSecond) * 1000);
  return ts;
}

// 清除定时器，避免一直触发
void readTimerfd(int timerfd, Timestamp now)
{
  uint64_t howmany;
  ssize_t n = ::read(timerfd, &howmany, sizeof howmany);
  std::cout << "TimerQueue::handleRead() " << howmany << " at " << now.toString();
  if (n != sizeof howmany)
  {
    std::cout << "TimerQueue::handleRead() reads " << n << " bytes instead of 8";
  }
}

// 重置定时器的超时时间
void resetTimerfd(int timerfd, Timestamp expiration)
{
  // wake up loop by timerfd_settime()
  struct itimerspec newValue;
  struct itimerspec oldValue;
  memset(&newValue, 0, sizeof(newValue));
  memset(&oldValue, 0, sizeof(oldValue));
  newValue.it_value = howMuchTimeFromNow(expiration);
  int ret = ::timerfd_settime(timerfd, 0, &newValue, &oldValue);
  if (ret)
  {
    std::cout << "timerfd_settime()";
  }
}

TimerQueue::TimerQueue(EventLoop* loop)
  : loop_(loop),
    timerfd_(createTimerfd()),
    timerfdChannel_(nullptr),
    timers_(),
    callingExpiredTimers_(false){
        timerfdChannel_ = new Channel(loop, timerfd_);
        std::function<void()> cb = std::bind(&TimerQueue::handleRead, this);
        // we are always reading the timerfd, we disarm it with timerfd_settime.
        timerfdChannel_->setReadCallback(cb);
        timerfdChannel_->enableRead();
    }

TimerQueue::~TimerQueue(){
    ::close(timerfd_);
    for (TimerList::iterator it = timers_.begin();
      it != timers_.end(); ++it) {
    delete it->second;
  }
}

TimerId TimerQueue::addTimer(std::function<void()>& cb,
                            Timestamp when, double interval) {
    Timer *timer = new Timer(cb, when, interval);

    loop_->runInLoop(
        std::bind(&TimerQueue::addTimerInLoop, this, timer)
    );
    return TimerId(timer, timer->sequence());
}

// 未实现
void TimerQueue::cancel(TimerId timerId){
    loop_->runInLoop(
      std::bind(&TimerQueue::cancelInLoop, this, timerId));
}   

void TimerQueue::cancelInLoop(TimerId timerId){
    loop_->assertInLoopThread();
    assert(timers_.size() == activeTimers_.size());
    // typedef std::pair<Timer*, int64_t> ActiveTimer; <Timer*, idx>
    ActiveTimer timer(timerId.timer_, timerId.sequence_);
    // 查找该定时器
    ActiveTimerSet::iterator it = activeTimers_.find(timer);
    if(it != activeTimers_.end()) {
      size_t n = timers_.erase(Entry(it->first->expiration(), it->first));
      assert(n == 1); (void)n;
      delete it->first; // FIXME: no delete please,如果用了unique_ptr,这里就不需要手动删除了
      activeTimers_.erase(it);
    } else if (callingExpiredTimers_) {
      // 已经到期，并且正在调用回调函数的定时器
      cancelingTimers_.insert(timer);
    }
    assert(timers_.size() == activeTimers_.size());
}

void TimerQueue::handleRead(){
  loop_->assertInLoopThread();
  Timestamp now(Timestamp::now());

  readTimerfd(timerfd_, now);		// 清除该事件，避免一直触发

  // 获取该时刻之前所有的定时器列表(即超时定时器列表)
  std::vector<Entry> expired = getExpired(now);

  callingExpiredTimers_ = true;
  cancelingTimers_.clear();

  for (std::vector<Entry>::iterator it = expired.begin();
      it != expired.end(); ++it)
  {
    // 这里回调定时器处理函数
    it->second->run();
  }

  callingExpiredTimers_ = false;

  // 不是一次性定时器，需要重启
  reset(expired, now);
}

void TimerQueue::reset(const std::vector<Entry>& expired, Timestamp now){
  Timestamp nextExpire;

  for (std::vector<Entry>::const_iterator it = expired.begin();
      it != expired.end(); ++it){
        ActiveTimer timer(it->second, it->second->sequence());
        if (it->second->repeat() && cancelingTimers_.find(timer) == cancelingTimers_.end()) {
      it->second->restart(now);
      insert(it->second);
    } else {
      // 一次性定时器或者已被取消的定时器是不能重置的，因此删除该定时器
      // FIXME move to a free list
      delete it->second; // FIXME: no delete please
    }
  }
}

void TimerQueue::addTimerInLoop(Timer* timer){
    loop_->assertInLoopThread();

    // 插入一个定时器，有可能会使得最早到期的定时器发生改变
    bool earliestChanged = insert(timer);

    if (earliestChanged){
        // 重置定时器的超时时刻(timerfd_settime)
        resetTimerfd(timerfd_, timer->expiration());
    }
}

std::vector<TimerQueue::Entry> TimerQueue::getExpired(Timestamp now) {
    // assert(timers.size() == activeTimers.size());
    std::vector<Entry> expired; // <timestamp, Timer*>
    Entry sentry(now, reinterpret_cast<Timer*>(UINTPTR_MAX));
    // 返回第一个未到期的Timer的迭代器
    // lower_bound的含义是返回第一个值>=sentry的元素的iterator
    // 即*end >= sentry，从而end->first > now
    TimerList::iterator end = timers_.lower_bound(sentry);

    // 将到期的定时器插入到expired中
    std::copy(timers_.begin(), end, back_inserter(expired));
    // 从timers_中移除到期的定时器
    timers_.erase(timers_.begin(), end);

    for(std::vector<Entry>::iterator it = expired.begin();
      it != expired.end(); ++it){
        ActiveTimer timer(it->second, it->second->sequence());
        size_t n = activeTimers_.erase(timer);
    }

    assert(timers_.size() == activeTimers_.size());
    return expired;
}

bool TimerQueue::insert(Timer* timer){
    Timestamp when = timer->expiration(); // 下一次的超时时刻

    TimerList::iterator it = timers_.begin(); // 定时器列表头
    bool earliestChanged = false;
    if(it == timers_.end() || when < it->first) {
        earliestChanged = true;
    }
    // 插入到timers_中
    std::pair<TimerList::iterator, bool> result
      = timers_.insert(Entry(when, timer));
    // 插入到activeTimers_中
    // std::pair<ActiveTimerSet::iterator, bool> result
    //   = activeTimers_.insert(ActiveTimer(timer, timer->sequence()));

    return earliestChanged;
}