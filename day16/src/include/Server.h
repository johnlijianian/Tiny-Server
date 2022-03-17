#pragma once

#include <map>
#include <vector>
#include <functional>

class EventLoop;
class Socket;
class Acceptor;
class Connection;
class ThreadPool;
class Buffer;
class Server {
private:
    EventLoop *mainReactor;     //只负责接受连接，然后分发给一个subReactor
    Acceptor *acceptor; //用于接受TCP连接
    std::map<int, Connection*> connections; //所有TCP连接
    std::vector<EventLoop*> subReactors;    //负责处理事件循环
    ThreadPool *thpool;     //线程池

    std::function<void(Connection*)> connectionCallback_;
    std::function<void(Connection*, Buffer*)> messageCallback_;

public:
    Server(EventLoop*);
    ~Server();

    void setConnectionCallback(std::function<void(Connection*)> cb){
        connectionCallback_ = cb;
    }

    void setMessageCallback(std::function<void(Connection*, Buffer*)> cb){
        messageCallback_ = cb;
    }

    // void onMessage(Connection *fn);  //Connection连接，首发消息
    void newConnection(Socket *sock);   //新建TCP连接，Acceptor传输消息
    void deleteConnection(Socket *sock);   //断开TCP连接
};