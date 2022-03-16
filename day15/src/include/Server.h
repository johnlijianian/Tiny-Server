#pragma once

#include <map>
#include <vector>

class EventLoop;
class Socket;
class Acceptor;
class Connection;
class ThreadPool;
class Server {
private:
    EventLoop *mainReactor;     //只负责接受连接，然后分发给一个subReactor
    Acceptor *acceptor; //用于接受TCP连接
    std::map<int, Connection*> connections; //所有TCP连接
    std::vector<EventLoop*> subReactors;    //负责处理事件循环
    ThreadPool *thpool;     //线程池
public:
    Server(EventLoop*);
    ~Server();

    void onMessage(std::function<void(Connection *)> fn);  //处理客户端请求
    void newConnection(Socket *sock);   //新建TCP连接
    void deleteConnection(Socket *sock);   //断开TCP连接
};