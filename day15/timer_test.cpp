#include <iostream>
#include <functional>
#include "EventLoop.h"
#include "TimerId.h"
#include "Timer.h"

using namespace std;
class TimerId;
class Timer;
class Printer{
    public:
        Printer(EventLoop* loop)
        : loop_(loop),
          count_(0){
              loop_->runAfter(1, bind(&Printer::print, this));
          }

        ~Printer(){
            std::cout << "Final count is " << count_ << endl;
        }
        
        void print(){
            if(count_ < 5){
                cout << count_ << endl;
                ++count_;

                loop_->runAfter(1, bind(&Printer::print, this));
            } else {
                cout << "exit" << endl;
                exit(1);
            }
        }
    private:
        EventLoop* loop_;
        int count_;
};

int main(){
    EventLoop loop;
    Printer printer(&loop);
    loop.loop();
}
