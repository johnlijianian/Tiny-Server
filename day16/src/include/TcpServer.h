#pragma once
class EventLoop;
class Acceptor;
class ThreadPool;
class Connection;
class Buffer;
class TcpServer{
private:
    EventLoop *mainReactor;     //只负责接受连接，然后分发给一个subReactor
    Acceptor *acceptor; //用于接受TCP连接
    std::map<int, Connection*> connections; //所有TCP连接
    std::vector<EventLoop*> subReactors;    //负责处理事件循环
    ThreadPool *thpool;     //线程池

    std::function<void (Connection*)> connectionCallback_;
    // boost::function<void (const TcpConnectionPtr&,
    //                           Buffer*,
    //                           Timestamp)> MessageCallback;
    std::function<void (Connection*, Buffer*)> messageCallback_;

    void defaultConnectionCallback(Connection* conn);
    void defaultMessageCallback(Connection* conn, Buffer* buffer);

public:
    TcpServer(EventLoop* loop);
    ~TcpServer();

    set


};
