#pragma once
class Timer;
class TimerId{
    public:
    TimerId()
		:	timer(NULL),
			timerIdx(0)
	{
	}
	
	TimerId(Timer* timer,int idx)
		:	timer_(timer),
			timerIdx(idx)
	{
	}

    friend class TimerQueue;

    private:
        int TimerIdx;
        Timer* timer;
};