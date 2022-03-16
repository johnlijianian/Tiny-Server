#include <iostream>
#include <thread>
#include <future>
// #include <package_task>

using namespace std;

int threadEntrace(int a){
    cout << "start thread_id=" << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);
    cout << "end thread_id=" << std::this_thread::get_id() << endl;
    return 5;
}

void promise_test(std::promise<int> &pr, int val){
    int result = val * 10;
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);

    pr.set_value(result);
    return ;
}

// std::lunnch::defer类型（枚举）：推迟到get 或 wait调用时再执行 （如果不掉用）
//  std::package_task: 打包任务；
int main(){
    // cout << "main thread_id=" << std::this_thread::get_id() << endl;

    // std::packaged_task<int(int)> pt(threadEntrace);
    // std::future<int> fu1 = pt.get_future();

    // std::thread th1(std::move(pt), 1);
    // th1.join();
    // int result = fu1.get();

    

    // // （1）
    // // pt(12);
    // cout << result << endl;
    // cout << "I Love "<<endl;

    // std::promise<int> pr;
    // std::thread
    return 0;
}