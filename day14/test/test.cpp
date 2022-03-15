#include <iostream>
#include <thread>
using namespace std;

// 隐式构造函数
// class A{
//     public:
//     explcit A(int a_) : a(a_) {}
//     int a;
// };

void fun(const int &a){
    cout << "fun" << endl;
    cout << &a <<endl;
}

int main(){
    int a = 1;
    cout << &a <<endl;
    thread t1(fun, std::ref(a));
    t1.detach();
    // int b = new A;
    // A a(b);
    // A a(12);
    return 0;
    // fun("abc");
}