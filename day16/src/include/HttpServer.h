

#pragma once
#include <functional>
#include "HttpResponse.h"
#include "HttpRequest.h"
#include "Server.h"
class EventLoop;
class Connection;
class Buffer;
class Timestamp;
class HttpServer{

    public:
        typedef std::function<void(const HttpRequest&, HttpResponse*)> HttpCallback;

        HttpServer(EventLoop* loop
            // const InetAddress& listenAddr,
            // const string& name
            );

        ~HttpServer();

        void setHttpCallback(const HttpCallback& cb) {
            httpCallback_ = cb;
        }

        // void setThreadNum(int numThreads) {
        //     server_.setThreadNum(numThreads);
        // }

        // void start();

    private:
        void onConnection(Connection* conn);
        void onMessage(Connection* conn, Buffer* buf);
        void onRequest(Connection* conn, HttpRequest& req);

        Server *server_;
        HttpCallback httpCallback_;
};