#include "Server.h"
#include "Socket.h"
#include "Acceptor.h"
#include "Connection.h"
#include "ThreadPool.h"
#include "EventLoop.h"
#include <unistd.h>
#include <functional>

Server::Server(EventLoop *_loop) : mainReactor(_loop), acceptor(nullptr){ 
    acceptor = new Acceptor(mainReactor);   //Acceptor由且只由mainReactor负责
    std::function<void(Socket*)> cb = std::bind(&Server::newConnection, this, std::placeholders::_1);
    acceptor->setNewConnectionCallback(cb);

    int size = std::thread::hardware_concurrency();     //线程数量，也是subReactor数量
    thpool = new ThreadPool(size);      //新建线程池
    for(int i = 0; i < size; ++i){
        subReactors.push_back(new EventLoop());     //每一个线程是一个EventLoop
    }

    for(int i = 0; i < size; ++i){
        // 定义subReactor[i] -> [Eventloop]的loop函数为 sub_loop
        std::function<void()> sub_loop = std::bind(&EventLoop::loop, subReactors[i]); 
        thpool->add(sub_loop);      //开启所有线程的事件循环
    }
}

Server::~Server(){
    delete acceptor;
    delete thpool;
}


void Server::newConnection(Socket *sock){
    std::cout<<"new Connection..."<<std::endl;

    if(sock->getFd() != -1){
        int random = sock->getFd() % subReactors.size();
        EventLoop* ioLoop = subReactors[random];
        Connection *conn = new Connection(ioLoop, sock);
        std::function<void(Socket*)> cb = std::bind(&Server::deleteConnection, this, std::placeholders::_1);
        
        conn->SetDeleteConnectionCallback(cb);
        conn->SetOnConnectCallback(connectionCallback_);
        connections[sock->getFd()] = conn;

        ioLoop->runInLoop(std::bind(&Connection::connectEstablished, conn));
    }
}

void Server::deleteConnection(Socket *sock){
    int sockfd = sock->getFd();
    if(sockfd != -1){
        auto it = connections.find(sockfd);
        if(it != connections.end()){
            Connection *conn = connections[sockfd];
            connections.erase(sockfd);
            // close(sockfd);       //正常
            delete conn;         //会Segmant fault
            conn = nullptr;
        }
    }
}

// void Server::onMessage(std::function<void(Connection *)> fn) {
//     on_connect_callback_ = std::move(fn); 
// }
