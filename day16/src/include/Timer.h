#pragma once
#include <sys/timerfd.h>
#include <time.h>
#include <sys/time.h>
#include <functional>
#include "TimeStamp.h"


class Timer{

public:
    Timer(std::function<void()> cb, Timestamp when, double interval) :
    timerCallback(cb),
    expiration_(when),
    interval_(interval),
    repeat_(interval > 0.0),
    sequence_(1){
        
    }

    void run(){
        timerCallback();
    }

    Timestamp expiration() const  { return expiration_; }
    bool getRepeat() const { return repeat_; }
    int sequence() const { return sequence_; }

    void restart(Timestamp now);

    bool repeat(){return repeat_;}

    // static int64_t numCreated() { return s_numCreated; }

	// static int s_numCreated; //(非原子性)定时器数目统计
private:
    const std::function<void()> timerCallback;  //要执行的任务
	Timestamp expiration_; // 下一次的超时时刻
	const double interval_; // 超时时间间隔，如果是一次性定时器，该值为0
	const bool repeat_;  //是否需要重复
	const int sequence_; //序号
	
};