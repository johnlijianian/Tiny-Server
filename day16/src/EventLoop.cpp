#include "EventLoop.h"
#include "Epoll.h"
#include "Channel.h"
#include "TimeStamp.h"
#include "TimerId.h"
#include "TimerQueue.h"
#include <vector>
#include <iostream>

#include <sys/eventfd.h>

int createEventfd()
{
  int evtfd = ::eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
  if (evtfd < 0)
  {
    std::cout << "Failed in eventfd";
    abort();
  }
  return evtfd;
}

EventLoop::EventLoop() : 
    quit(false),
    ep(new Epoll),
    timerQueue_(new TimerQueue(this)),
    threadId_(std::this_thread::get_id()),
    wakeupFd_(createEventfd()),
    wakeupChannel_(new Channel(this, wakeupFd_))
{
    wakeupChannel_->setReadCallback(
        std::bind(&EventLoop::handleRead, this)
    );
    // we are always reading the wakeupfd
    wakeupChannel_->enableRead();
}

EventLoop::~EventLoop() {
    delete ep;
}

void EventLoop::loop(){
    // assertInLoopThread();
    while(!quit){
        std::vector<Channel*> chs;
        chs = ep->poll();
        for(auto it = chs.begin(); it != chs.end(); ++it){
            (*it)->handleEvent();
        }
        // 执行pending Functors_中的任务回调
        // 这种设计使得IO线程也能执行一些计算任务，避免了IO线程在不忙时长期阻塞在IO multiplexing调用中
        doPendingFunctors();
    }
}

void EventLoop::updateChannel(Channel *ch){
    ep->updateChannel(ch);
}

void EventLoop::runInLoop(std::function<void()> cb){
    std::cout << "runInLoop..."<<std::endl;
    if(isInLoopThread()){
        // 当前线程，同步执行
        std::cout << "runInLoop...InLoopThread()"<<std::endl;
        cb();
    } else { // 不是当前线程，所属线程在执行别的任务，所以（加入到队列中 & 唤醒）-> queueInLoop执行
        std::cout << "runInLoop...NotInLoopThread()"<<std::endl;
        queueInLoop(cb);
    }
}

void EventLoop::queueInLoop(std::function<void()> cb){
    {
        std::unique_lock<std::mutex> lock(pendingTasksMutex);   //加锁
        pendingFunctors_.emplace_back(cb);
    }
    if(!isInLoopThread() || callingPendingFunctors_) {
        wakeup();
    }
}

void EventLoop::doPendingFunctors(){
    std::vector<std::function<void()>> functors;
    callingPendingFunctors_ = true;
    {
        std::unique_lock<std::mutex> lock(pendingTasksMutex);
        functors.swap(pendingFunctors_);
    }

    for(int i = 0; i < functors.size(); i++){
        functors[i]();
    }
    callingPendingFunctors_ = false;
}

TimerId EventLoop::runAt(const Timestamp& time, std::function<void()> cb){
    return timerQueue_->addTimer(cb, time, 0.0);
}

TimerId EventLoop::runAfter(double delay, std::function<void()> cb){
    Timestamp time(addTime(Timestamp::now(), delay));
    return runAt(time, cb);
}

TimerId EventLoop::runEvery(double interval, std::function<void()> cb){
    Timestamp time(addTime(Timestamp::now(), interval));
    return timerQueue_->addTimer(cb, time, interval);
}

void EventLoop::cancel(TimerId timerId) {
  return timerQueue_->cancel(timerId);
}

void EventLoop::handleRead()
{
  int one = 1;
  //ssize_t n = sockets::read(wakeupFd_, &one, sizeof one);
  ssize_t n = ::read(wakeupFd_, &one, sizeof one);

  std::cout << "EventLoop::handleRead() reads " << std::endl;
}
