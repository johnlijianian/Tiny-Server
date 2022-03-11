#include "EventLoop.h"
#include "Epoll.h"
#include "Channel.h"
#include <vector>

EventLoop::EventLoop() : 
    ep(nullptr),
    quit(false)
    threadId(std::this_thread::get_id()){
    ep = new Epoll();
}

EventLoop::~EventLoop() {
    delete ep;
}

void EventLoop::loop(){
    assertInLoopThread();
    while(!quit){
        std::vector<Channel*> chs;
        chs = ep->poll();
        for(auto it = chs.begin(); it != chs.end(); ++it){
            (*it)->handleEvent();
        }
    }
}

void EventLoop::updateChannel(Channel *ch){
    ep->updateChannel(ch);
}

void EventLoop::runInLoop(std::function<void()> cb){
    if(isInLoopThread()){
        // 当前线程，同步执行
        cb();
    } else { // 不是当前线程，所属线程在执行别的任务，所以（加入到队列中 & 唤醒）-> queueInLoop执行
        queueInLoop(cb);
    }
}

void EventLoop::queueInLoop(std::function<void()> cb){
    {
        std::unique_lock<std::mutex> lock(tasks_mtx);   //加锁
        pendingTasks.emplace_back(cb);
    }
}