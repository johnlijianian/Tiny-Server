#include <iostream>
#include <functional>
#include <future>
#include <queue>
using namespace std;

int func(int a){
    cout << "func running" << endl;
    return 5;
}

int func2(int a, int b){
    cout << "a+b"<<endl;
    cout << a + b << endl;
    return 1;
}

typedef int(*funPtr)(int);
typedef std::function<int(int)> funPtr1;

// template<class F, class... Args>
// auto fun(F&& f, Args&& ...args) -> decltype(f(args...)){

// }


int main(){
    // funPtr ptr;
    // ptr = func;
    // cout << (*ptr)(1) << endl;
    // funPtr1 ptr1 = func;
    // cout << ptr1(1) << endl;
    using fun_ret = decltype(func(1)); // int
    using Task = function<void()>; // 函数指针

    // std::packaged_task<返回值(形参1,形参2,...)> 变量名(函数指针);
    // std::future<int> fu1 = pt.get_future();
    // std::thread th1(std::move(pt), 1);

    // packaged_task<fun_ret(int)> 变量名(函数指针);
    // fun2Ptr pptr = func2;
    // int a = 2;
    // int b = 5;
    // auto _ptr = bind(pptr, forward<int>(a), forward<int>(b));
    // packaged_task<fun_ret()> pt(_ptr);
    // future<fun_ret> fu1 = pt.get_future();
    // thread th1(std::move(pt));
    // th1.join();
    // cout << fu1.get() << endl;

    queue<Task> tasks;

    packaged_task<int()> pt(
        bind(func2, forward<int>(1), forward<int>(3))
    );

    // auto task = make_shared<packaged_task<int()>> (
    //     bind(func2, forward<int>(1), forward<int>(3))
    // );

    auto task = make_shared<function<int()>>(
        bind(func2, forward<int>(1), forward<int>(3))
    );

    // pt();
    *task();
    // cout << *task() << endl;
    
    // tasks.emplace((*ptr));

    // for(int i = 0; i < tasks.size(); i++){
    //     auto runT = tasks.front();
    //     tasks.pop();
    //     runT();
    // }

    return 0;
}