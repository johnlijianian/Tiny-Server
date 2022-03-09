#pragma once
#include <functional>
class Epoll;
class Channel;
class ThreadPool;
class EventLoop
{
private:
    Epoll *ep;
    bool quit;
public:
    EventLoop();
    ~EventLoop();

    void loop();
    void updateChannel(Channel*);

    // 定时器相关
    TimerId runAt(const Timestamp& time, std::function<void()> cb);
    TimerId runAfter(double delay, std::function<void()> cb);
    TimerId runEvery(double interval, std::function<void()> cb);
    void cancel(TimerId timerId);

    // 所属线程
    // const pid_t threadId_;		// 当前对象所属线程ID
};