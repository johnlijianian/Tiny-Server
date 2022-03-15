#pragma once
#include <unistd.h>
#include <functional>
#include <mutex>
#include <atomic>
#include <queue>
#include <thread>
#include <iostream>

class Epoll;
class Channel;
class ThreadPool;
class Timestamp;
class TimerId;
class TimerQueue;
class EventLoop
{
private:
    Epoll *ep;
    TimerQueue *tq;
    std::vector<std::function<void()>> pendingFunctors_; // 任务容器，存放异步存入的函数。
    bool quit;
    
    const std::thread::id threadId_;		// 当前对象所属线程ID

    bool callingPendingFunctors_;

    TimerQueue *timerQueue_;

    int wakeupFd_;				// 由于Loop中常常阻塞于Epoll::poll()，需要让其及时退出。
    Channel *wakeupChannel_;     // wakeupFd对应的wakeupChannel
    void handleRead();

    void wakeup(){
        uint64_t one = 1;
        ssize_t n = ::write(wakeupFd_, &one, sizeof(one));
        // 写入消息进行唤醒
    }

    std::mutex pendingTasksMutex;

    void doPendingFunctors();
    
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

    void runInLoop(std::function<void()> cb);
    void queueInLoop(std::function<void()> cb);

    bool isInLoopThread() { return threadId_ == std::this_thread::get_id(); }


    void assertInLoopThread() {
        if(!isInLoopThread()){
            std::cout<< "Not In Loop" << std::endl;
            exit(1);
        }
    }
};