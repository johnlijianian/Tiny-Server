#pragma once
class EventLoop;
class TimerId;
class TimerQueue{
public:
    TimerQueue(EventLoop* loop);
    ~TimerQueue();

    TimerId addTimer(const TimerCallback& cb,
                   Timestamp when,
                   double interval);

    void cancel(TimerId timerId);

    typedef std::pair<Timestamp, Timer*> Entry; // 按照时间寻找
    typedef std::set<Entry> TimerList; // 根据Entry(时间戳)进行排序
    // typedef std::pair<Timer*, int64_t> ActiveTimer; // 按照对象寻找
    // typedef std::set<ActiveTimer> ActiveTimerSet;

private:
    EventLoop* loop;
    const int timerfd;
    Channel* timerfdChannel;
    TimerList timers;

    ActiveTimerSet activeTimers_;
    bool callingExpiredTimers_; /* atomic */
    ActiveTimerSet cancelingTimers_;	// 保存的是被取消的定时器
};