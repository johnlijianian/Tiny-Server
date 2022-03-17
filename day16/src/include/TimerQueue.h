#pragma once
#include <set>
#include <functional>
#include <vector>
class EventLoop;
class Timestamp;
class TimerId;
class Timer;
class Channel;
class TimerQueue{
public:
    TimerQueue(EventLoop* loop);
    ~TimerQueue();

    TimerId addTimer(std::function<void()>& cb,
                   Timestamp when,
                   double interval);

    void cancel(TimerId timerId);

    typedef std::pair<Timestamp, Timer*> Entry; // 按照时间寻找
    typedef std::set<Entry> TimerList; // 根据Entry(时间戳)进行排序
    typedef std::pair<Timer*, int64_t> ActiveTimer; // 按照对象寻找(删除的时候会根据TimerID进行删除)
    typedef std::set<ActiveTimer> ActiveTimerSet;

private:
    EventLoop* loop_; // 所属于的循环
    const int timerfd_;
    Channel* timerfdChannel_;

    void addTimerInLoop(Timer* timer);
    void cancelInLoop(TimerId timerId);

    void handleRead();
    void reset(const std::vector<Entry>& expired, Timestamp now);

    std::vector<Entry> getExpired(Timestamp now); // 取出到时的定时器

    TimerList timers_;
    // timers_与activeTimers_保存的是相同的数据
    // timers_是按到期时间排序，activeTimers_是按对象地址排序
    ActiveTimerSet activeTimers_; 
    ActiveTimerSet cancelingTimers_;	// 保存的是被取消的定时器

    bool callingExpiredTimers_; /* atomic */
    bool insert(Timer* timer);
};