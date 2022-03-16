#include "threadPool.h"
#include <iostream>
#include <future>

using namespace std;

void fun1(int slp)
{
    printf("  hello, fun1 !  %d\n" ,std::this_thread::get_id());
    if (slp>0) {
        printf(" ======= fun1 sleep %d  =========  %d\n",slp, std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::milliseconds(slp));
    }
}

int fun2(int slp)
{
    printf("  hello, fun2 !  %d\n" ,std::this_thread::get_id());
    if (slp>0) {
        printf(" ======= fun1 sleep %d  =========  %d\n",slp, std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::milliseconds(slp));
    }
    return 1;
}

struct gfun {
    int operator()(int n) {
        printf("%d  hello, gfun !  %d\n" ,n, std::this_thread::get_id() );
        return 42;
    }
};

int main(){
    threadPool executor(8);
    future<void> f1 = executor.commit(fun1, 3000);
    future<int> f2 = executor.commit(fun2, 4000);
    future<int> f3 = executor.commit(fun2, 5000);
    // future<int> fg = executor.commit(gfun(), 2);

    f1.get();
    std::cout<<f2.get()<<endl;
    std::cout<<f3.get()<<endl;

    std::cout << " =======  sleep ========= " << std::this_thread::get_id() << std::endl;
    return 0;
}