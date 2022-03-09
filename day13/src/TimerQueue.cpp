#include "TimerQueue.h"
#include "EventLoop.h"
#include "Timer.h"
#include "TimerId.h"

#include <sys/timerfd.h>

int createTimerfd(){
    // int timerfd_create(int clockid, int flags);

    // 第一个参数：clockid指定时间类型，有两个值：
    // CLOCK_REALTIME :Systemwide realtime clock. 系统范围内的实时时钟
    // CLOCK_MONOTONIC:以固定的速率运行，从不进行调整和复位 ,它不受任何系统time-of-day时钟修改的影响

    // 第二个参数
    // NONBLOCK 读时非阻塞
    // CLOEXEC 运行时关闭标志
    int timerfd = ::createTimerfd(CLOCK_MONOTONIC,
                                  TFD_NONBLOCK | TFD_CLOEXEC);
    if (timerfd < 0) {
        LOG_SYSFATAL << "Failed in timerfd_create";
    }
    return timerfd;                        
}

TimerQueue::TimerQueue(EventLoop* loop)
  : loop_(loop),
    timerfd_(createTimerfd()),
    timerfdChannel_(loop, timerfd_),
    timers_(),
    callingExpiredTimers_(false){
        std::function<void()> cb = std::bind(&TimerQueue::handleRead, this);
        // we are always reading the timerfd, we disarm it with timerfd_settime.
        timerfdChannel->setReadCallback(cb);
        timerfdChannel->enableRead();
    }

TimerQueue::~TimerQueue(){
    ::close(timerfd_);
    for (TimerList::iterator it = timers_.begin();
      it != timers_.end(); ++it) {
    delete it->second;
  }
}
// 未实现
TimerId TimerQueue::addTimer(std::function<void()> cb,
                            Timestamp when, double interval) {
    Timer *timer = new Timer(cb, when, interval);

    // loop_->runInLoop(
    //   boost::bind(&TimerQueue::addTimerInLoop, this, timer));
    //addTimerInLoop(timer);
    return TimerId(timer, timer->sequence());
}

// 未实现
void TimerQueue::cancel(TimerId timerId){

}

void TimerQueue::addTimerInLoop(Timer* timer){
    loop
}

std::vector<TimerQueue::Entry> TimerQueue::getExpired(Timestamp now) {
    // assert(timers.size() == activeTimers.size());
    std::vector<Entry> expired; // <timestamp, Timer*>
    Entry sentry(now, reinterpret_cast<Timer*>(UINTPTR_MAX));
    // 返回第一个未到期的Timer的迭代器
    // lower_bound的含义是返回第一个值>=sentry的元素的iterator
    // 即*end >= sentry，从而end->first > now
    TimerList::iterator end = timers.lower_bound(sentry);

    // 将到期的定时器插入到expired中
    std::copy(timers.begin(), end, back_inserter(expired))
    // 从timers_中移除到期的定时器
    timers.erase(timers.begin(), end);

    // for(auto iterator : expired){
    //     ActiveTimer timer(it->second, it->second->getIdx());
    //     size_t n = activeTimers.erase(timer);
    // }

    // assert(timers_.size() == activeTimers_.size());
    return expired;
}

bool TimerQueue::insert(Timer* timer){
    Timestamp when = timer->expiration();

    TimerList::iterator it = timers.begin();
    bool earliestChanged = false;
    if(it == timers.end() || when < it->first) {
        earliestChanged = true;
    }

    std::pair<TimerList::iterator, bool> result
      = timers_.insert(Entry(when, timer));
}