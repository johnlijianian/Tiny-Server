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

    void SetDeleteConnectionCallback(std::function<void(Socket *)> const &callback);
    void SetOnConnectCallback(std::function<void(Connection *)> const &callback);

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

private:
    EventLoop *loop_;
    Socket *sock_;
    Channel *channel_;
    std::function<void(int)> deleteConnectionCallback;
    std::string *inBuffer;
    Buffer *read_buffer_{nullptr};
    Buffer *send_buffer_{nullptr};
    State state_{State::Invalid};

    std::function<void(Socket *)> delete_connectioin_callback_;
    std::function<void(Connection *)> on_connect_callback_;

    std::any context_;

    void ReadNonBlocking();
    void WriteNonBlocking();
    void ReadBlocking();
    void WriteBlocking();

    
    // void echo(int sockfd);
    // void send(int sockfd);
};
