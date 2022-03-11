#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

using namespace std;
std::mutex some_mutex;

int s = 0;

void fun0(){
    {
        lock_guard<std::mutex> guard(some_mutex);
        usleep(1000000);
        s = 20;
    }
    
}

void fun1(){
    s = 30;
}

int main(){
    int *ptr = &s;
    thread t1(fun0);
    thread t2(fun1);
}