#pragma once
#include <sys/timerfd.h>
#include <time.h>
#include<sys/time.h>

class Timer{

public:
    TimerCallback;
    Timer(std::function<void()> cb, Timestamp when, double interval) :
    timerCallback(cb),
    expiration(when),
    interval(interval),
    repeat_(interval > 0.0),
    sequence_(s_numCreated++){
        
    }

    void run(){
        timerCallback();
    }

    Timestamp getExpiration() const { return expiration_; }
    bool getRepeat() const { return repeat_; }
    int getIdx() const { return idx; }

    void restart(Timestamp now);

    static int64_t numCreated() { return s_numCreated; }
private:
    const std::function<void()> timerCallback;  //要执行的任务
	Timestamp expiration; // 下一次的超时时刻
	const double interval; // 超时时间间隔，如果是一次性定时器，该值为0
	const bool repect;  //是否需要重复
	const int idx //序号
	
	static int s_numCreated; //(非原子性)定时器数目统计
};