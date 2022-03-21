#include "Connection.h"
#include "Socket.h"
#include "Channel.h"
#include "util.h"
#include "Buffer.h"
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <cassert>
#include <utility>
#include <sys/socket.h> 
#include <iostream>


Connection::Connection(EventLoop *_loop, Socket *_sock) 
: loop_(_loop),
  sock_(_sock), 
  channel_(nullptr)
{
    if(_loop != nullptr) {
        channel_ = new Channel(loop_, sock_->getFd());
        // channel_->enableRead();
        // 

        // channel_->setReadCallback(std::bind(&Connection::handleRead, this));
    }
    read_buffer_ = new Buffer();
    send_buffer_ = new Buffer();

    channel_->setReadCallback(std::bind(&Connection::handleRead, this));
}

Connection::~Connection() {
  if (loop_ != nullptr) {
    delete channel_;
  }
  delete sock_;
  delete read_buffer_;
  delete send_buffer_;
}

void Connection::handleRead() {
  std::cout<<"handle Read"<<std::endl;
  Read();
  if(read_buffer_->size() > 0){
    onMessageCallback_(this, read_buffer_);
  } else if(read_buffer_->size() == 0) {
    std::cout<<"read buffer 0"<<std::endl;
  } else {
    std::cout<<"read error!"<<std::endl;
    exit(1);
  }
} 

void Connection::connectEstablished() {
  std::cout << "Connection::connectEstablished()" << std::endl;
  state_ = State::Connected;
  channel_->enableRead();
  channel_->useET();
  onConnectionCallback_(this);
}

void Connection::Read() {
    assert(state_ == State::Connected);
    read_buffer_->clear();
    if (sock_->isnonblocking()) {
        ReadNonBlocking();
    } else {
        ReadBlocking();
    }
}

void Connection::ReadNonBlocking() {
    int sockfd = sock_->getFd();
    char buf[1024];  // 这个buf大小无所谓
    while (true) {   // 使用非阻塞IO，读取客户端buffer，一次读取buf大小数据，直到全部读取完毕
        memset(buf, 0, sizeof(buf));
        ssize_t bytes_read = read(sockfd, buf, sizeof(buf));
        if (bytes_read > 0) {
            read_buffer_->append(buf, bytes_read);
        } else if (bytes_read == -1 && errno == EINTR) {  // 程序正常中断、继续读取
            printf("continue reading\n");
            continue;
        } else if (bytes_read == -1 &&
                ((errno == EAGAIN) || (errno == EWOULDBLOCK))) {  // 非阻塞IO，这个条件表示数据全部读取完毕
            break;
        } else if (bytes_read == 0) {  // EOF，客户端断开连接
            printf("read EOF, client fd %d disconnected\n", sockfd);
            state_ = State::Closed;
            break;
        } else {
            printf("Other error on client fd %d\n", sockfd);
            state_ = State::Closed;
            break;
        }
    }
}

void Connection::ReadBlocking(){
    int sockfd = sock_->getFd();
    unsigned int rcv_size = 0;
    socklen_t len = sizeof(rcv_size);
    getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &rcv_size, &len);
    char buf[rcv_size];
    ssize_t bytes_read = read(sockfd, buf, sizeof(buf));
    if (bytes_read > 0) {
        read_buffer_->append(buf, bytes_read);
    } else if (bytes_read == 0) {
        printf("read EOF, blocking client fd %d disconnected\n", sockfd);
        state_ = State::Closed;
    } else if (bytes_read == -1) {
        printf("Other error on blocking client fd %d\n", sockfd);
        state_ = State::Closed;
    }
}

void Connection::Write(){
    assert(state_ == State::Connected);
    if (sock_->isnonblocking()) {
        WriteNonBlocking();
    } else {
        WriteBlocking();
    }
    send_buffer_->clear();
}

void Connection::WriteNonBlocking() {
  int sockfd = sock_->getFd();
  char buf[send_buffer_->size()];
  memcpy(buf, send_buffer_->ToStr(), send_buffer_->size());
  int data_size = send_buffer_->size();
  int data_left = data_size;
  while (data_left > 0) {
    ssize_t bytes_write = write(sockfd, buf + data_size - data_left, data_left);
    if (bytes_write == -1 && errno == EINTR) {
      printf("continue writing\n");
      continue;
    }
    if (bytes_write == -1 && errno == EAGAIN) {
      break;
    }
    if (bytes_write == -1) {
      printf("Other error on client fd %d\n", sockfd);
      state_ = State::Closed;
      break;
    }
    data_left -= bytes_write;
  }
}

void Connection::WriteBlocking() {
  // 没有处理send_buffer_数据大于TCP写缓冲区，的情况，可能会有bug
  int sockfd = sock_->getFd();
  ssize_t bytes_write = write(sockfd, send_buffer_->ToStr(), send_buffer_->size());
  if (bytes_write == -1) {
    printf("Other error on blocking client fd %d\n", sockfd);
    state_ = State::Closed;
  }
}


void Connection::Close() { deleteConnectionCallback_(sock_); }

Connection::State Connection::GetState() { return state_; }
void Connection::SetSendBuffer(const char *str) { send_buffer_->setBuf(str); }
Buffer *Connection::GetReadBuffer() { return read_buffer_; }
const char *Connection::ReadBuffer() { return read_buffer_->ToStr(); }
Buffer *Connection::GetSendBuffer() { return send_buffer_; }
const char *Connection::SendBuffer() { return send_buffer_->ToStr(); }

void Connection::SetDeleteConnectionCallback(std::function<void(Socket *)> &cb) {
  deleteConnectionCallback_ = cb;
}
void Connection::SetOnMessageCallback(std::function<void(Connection *, Buffer*)> &cb) {
  onMessageCallback_ = cb;
}

void Connection::SetOnConnectCallback(std::function<void(Connection *)> &cb) {
  onConnectionCallback_ = cb;
  // channel_->setReadCallback(std::bind(&Connection::onConnectionCallback_, this));
}

void Connection::GetlineSendBuffer() { send_buffer_->getline(); }


Socket *Connection::GetSocket() { return sock_; }
