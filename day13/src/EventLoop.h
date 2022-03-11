#pragma once
#include <functional>
#include <mutex>
class Epoll;
class Channel;
class ThreadPool;
class TimeQueue;
class EventLoop
{
private:
    Epoll *ep;
    TimeQueue *tq;
    std::queue<std::function<void()>> pendingTasks; // 任务容器，存放异步存入的函数。
    bool quit;

    const pid_t threadId_;		// 当前对象所属线程ID
    const std::thread::id threadId;

    int wakeupFd_;				// 由于Loop中常常阻塞于Epoll::poll()，需要让其及时退出。
    Channel *wakeupChannel;     // wakeupFd对应的wakeupChannel

    std::mutex pendingTasksMutex;

    bool isInLoopThread() const { return threadId == std::this_thread::get_id(); }

    void assertInLoopThread() {
        if(!isInLoopThread){
            std::cout<< "Not In Loop" << endl;
            exit();
        }
    }
    
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
};