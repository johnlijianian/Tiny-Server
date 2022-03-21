#include "include/Acceptor.h"
#include "Socket.h"
#include "InetAddress.h"
#include "Channel.h"

Acceptor::Acceptor(EventLoop *_loop) : loop(_loop)
{
    sock = new Socket();
    InetAddress *addr = new InetAddress("0.0.0.0", 8080);
    sock->bind(addr);
    sock->listen(); 
    // sock->setnonblocking();
    acceptChannel = new Channel(loop, sock->getFd());
    std::function<void()> cb = std::bind(&Acceptor::acceptConnection, this);
    acceptChannel->setReadCallback(cb);
    acceptChannel->enableRead();
    delete addr;
}


Acceptor::~Acceptor(){
    delete sock;
    delete acceptChannel;
}

void Acceptor::acceptConnection(){
    InetAddress *clnt_addr = new InetAddress();      
    Socket *clnt_sock = new Socket(sock->accept(clnt_addr));      
    printf("new client fd %d! IP: %s Port: %d\n", clnt_sock->getFd(), inet_ntoa(clnt_addr->getAddr().sin_addr), ntohs(clnt_addr->getAddr().sin_port));
    clnt_sock->setnonblocking(); //新接受到的连接设置为非阻塞式
    newConnectionCallback(clnt_sock);
    delete clnt_addr;
}

void Acceptor::setNewConnectionCallback(std::function<void(Socket*)> _cb){
    newConnectionCallback = _cb;
}