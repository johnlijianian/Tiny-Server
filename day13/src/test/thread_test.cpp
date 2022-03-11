// g++ -std=c++0x -pthread  thread_test.cpp -o hello
#include <iostream>
#include <functional>
#include <vector>
#include <thread>
#include <numeric>
#include <algorithm>
using namespace std;

void fun0(){
    cout<<"hello0"<<endl;
    return ;
}

void fun1(){
    cout<<"hello1"<<endl;
}

// struct func
// {
//   int& i;
//   func(int& i_) : i(i_) {}
//   void operator() ()
//   {
//     for (unsigned j=0 ; j<1000000 ; ++j)
//     {
//       do_something(i);           // 1. 潜在访问隐患：悬空引用
//     }
//   }
// };

// class thread_guard
// {
//   std::thread& t;
// public:
//   explicit thread_guard(std::thread& t_):
//     t(t_)
//   {}
//   ~thread_guard()
//   {
//     if(t.joinable()) // 1
//     {
//       t.join();      // 2
//     }
//   }

//   // 因为thread中的拷贝复制 & 拷贝构造被禁止
//   thread_guard(thread_guard const&)=delete;   // 3
//   thread_guard& operator=(thread_guard const&)=delete;
// };

// int main(){
//     thread th([]{
//         fun0();
//         fun1();
//     });
//     th.join();
//     return 0;
// }

template <typename Iterator, typename T>
class accumulate_block{
  public:
  void operator() (Iterator first,Iterator last,T& result) {
    result = std::accumulate(first, last, result);
  }
};

template <typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init){
  unsigned long const length=std::distance(first,last);

  if (!length)
    return init;

  unsigned long const min_per_thread=25;
  unsigned long const max_threads=
      (length+min_per_thread-1)/min_per_thread; // 2

  unsigned long const hardware_threads=
      std::thread::hardware_concurrency(); // 机器可以支持的线程最大数量

  unsigned long const num_threads=  // 3
      std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

  unsigned long const block_size=length/num_threads; // 4

  std::vector<T> results(num_threads);
  std::vector<std::thread> threads(num_threads-1);  // 5 (必须少一个，因为主线程的存在)

  Iterator block_start=first;

  for(unsigned long i = 0; i < (num_threads - 1); ++i){
    Iterator block_end=block_start;
    std::advance(block_end,block_size);  // 6
    threads[i]=std::thread(
      accumulate_block<Iterator, T>(),
      block_start,block_end,std::ref(results[i]));
    block_start=block_end;  // 8
  }

  accumulate_block<Iterator,T>()(
      block_start,last,results[num_threads-1]); // 9
  std::for_each(threads.begin(),threads.end(),
       std::mem_fn(&std::thread::join));  // 10

  return std::accumulate(results.begin(),results.end(),init); // 11
}

int main() {
  vector<int> v(1000, 1);
  int val = 0;
  cout << parallel_accumulate(v.begin(), v.end(), val) << endl;
}