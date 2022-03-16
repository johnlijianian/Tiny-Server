#pragma once
#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>

#define  THREADPOOL_MAX_NUM 8

// std::shared_ptr<Widget> spw(new Widget);
// auto spw = std::make_shared<Widget>();

class threadPool{
    private:
        typedef std::function<void()> Task;
        std::mutex mutex_;
        std::vector<std::thread> _pool; 
        std::queue<Task> _tasks;
        std::condition_variable cv;
        std::atomic<int> _idlThrNum{ 0 };  //空闲线程数量
        std::atomic<bool> _run{ true };
    public:
        threadPool(int size = 4) {addThread(size);} 
        ~threadPool(){
            _run = false;
            cv.notify_all(); // 唤醒所有线程执行
            for (std::thread& thread : _pool) {
                //thread.detach(); // 让线程“自生自灭”
                if(thread.joinable())
                    thread.join(); // 等待任务结束， 前提：线程一定会执行完
            }
        }
        // 线程数量
        int thrCount() { return _pool.size(); }
        // 空闲线程数量
        int idlCount() { return _idlThrNum; }
        // 提交任务
        template<class F, class... Args>
            auto commit(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type> {
            using return_type = typename std::result_of<F(Args...)>::type;  //返回值类型

            auto task = std::make_shared< std::packaged_task<return_type()> >(  //使用智能指针
                    std::bind(std::forward<F>(f), std::forward<Args>(args)...)  //完美转发参数
                );  

            
            std::future<return_type> future = task->get_future();
            {    // 添加任务到队列
                std::unique_lock<std::mutex> lock(mutex_);//对当前块的语句加锁  lock_guard 是 mutex 的 stack 封装类，构造的时候 lock()，析构的时候 unlock()
                _tasks.emplace([task]{ // 1. {}可以理解为定义函数 2. 函数中调用(*task)()函数
                    (*task)();
                });
                // _tasks.emplace(*task);
            }
            cv.notify_one(); // 唤醒一个线程执行

            return future;
        }
    private:
        void addThread(int size){
            for (; _pool.size() < THREADPOOL_MAX_NUM && size > 0; --size){
                std::cout << "Thread " << size << " start!" <<std::endl;
                _pool.emplace_back([this]{
                    while(_run){
                        Task task;
                        {
                            std::unique_lock<std::mutex> lock(mutex_);
                            // wait不断
                            cv.wait(lock, [this]{ // 唤醒后仍在争抢锁资源
                                return !_tasks.empty(); // true为执行 ｜ false为继续睡眠
                            });
                            if (_tasks.empty())
                                return;
                            task = move(_tasks.front());
                            _tasks.pop();
                        }
                        _idlThrNum--;
                        task();//执行任务
                        _idlThrNum++;
                    }
                });
                _idlThrNum++;
            }
        }
};



#endif