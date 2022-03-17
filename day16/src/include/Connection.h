#pragma once
#include <functional>
#include <any>

class EventLoop;
class Socket;
class Channel;
class Buffer;
class Connection
{
public:
    enum State {
        Invalid = 1,
        Handshaking,
        Connected,
        Closed,
        Failed,
    };
    Connection(EventLoop *_loop, Socket *_sock);
    ~Connection();

    void Read();
    void Write();
    State GetState();

    void SetDeleteConnectionCallback(std::function<void(Socket *)> &callback);
    void SetOnConnectCallback(std::function<void(Connection *)> &callback);
    void SetOnMessageCallback(std::function<void(Connection *, Buffer*)>&callback);

    void Close();
    void SetSendBuffer(const char *str);
    Buffer *GetReadBuffer();
    const char *ReadBuffer();
    Buffer *GetSendBuffer();
    const char *SendBuffer();
    void GetlineSendBuffer();
    Socket *GetSocket();

    void setContext(const std::any& context)
    { context_ = context; }

    std::any* getMutableContext()
    { return &context_; }

    const std::any& getContext() const
    { return context_; }

    void handleRead();
    void connectEstablished();

private:
    EventLoop *loop_; // 所属EventLoop
    Socket *sock_; 	// Connector所对应的Channel
    Channel *channel_;
    std::function<void(int)> deleteConnectionCallback;
    std::string *inBuffer;
    Buffer *read_buffer_{nullptr};
    Buffer *send_buffer_{nullptr};
    State state_{State::Invalid};

    std::function<void(Socket *)> deleteConnectionCallback_; // 删除成功回调函数，
    std::function<void(Connection*)> onConnectionCallback_; // 连接成功回调函数，
    std::function<void(Connection*, Buffer*)> onMessageCallback_; // 收到消息函数回调

    std::any context_;

    void ReadNonBlocking();
    void WriteNonBlocking();
    void ReadBlocking();
    void WriteBlocking();


    
    // void echo(int sockfd);
    // void send(int sockfd);
};
