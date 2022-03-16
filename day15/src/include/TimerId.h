#pragma once
class Timer;
class TimerId{
    public:
    TimerId()
		:	timer_(NULL),
			sequence_(0)
	{
	}
	
	TimerId(Timer* timer,int idx)
		:	timer_(timer),
			sequence_(idx)
	{
	}

    friend class TimerQueue;

    private:
        int sequence_;
        Timer* timer_;
};