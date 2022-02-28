#pragma once
#include <sys/epoll.h>
#include <functional>

class EventLoop;
class Channel{
private:
    EventLoop *loop;
    int fd;
    uint32_t events;
    uint32_t revents; // revents表示在epoll返回该Channel时文件描述符正在发生的事件。
    bool inEpoll; // inEpoll表示当前Channel是否已经在epoll红黑树中，为了注册Channel的时候方便区分使用EPOLL_CTL_ADD还是EPOLL_CTL_MOD
    std::function<void()> callback;
public:
    Channel(EventLoop *_loop, int _fd);
    ~Channel();

    void handleEvent();
    void enableReading();

    int getFd();
    uint32_t getEvents();
    uint32_t getRevents();
    bool getInEpoll();
    void setInEpoll();

    // void setEvents(uint32_t);
    void setRevents(uint32_t);
    void setCallback(std::function<void()>);
};