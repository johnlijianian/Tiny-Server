

#pragma once
class HttpResponse;
class HttpRequest;
class EventLoop;
class Connection;
class HttpServer{

    public:
        typedef std::function<void(const HttpRequest&, HttpResponse*)> HttpCallback;
        typedef Connection* ConnectionPtr;

        HttpServer(EventLoop* loop,
            // const InetAddress& listenAddr,
            // const string& name
            );

        ~HttpServer();

        void setHttpCallback(const HttpCallback& cb) {
            httpCallback_ = cb;
        }

        void defaultHttpCallback(const HttpRequest&, HttpResponse* resp) {
            resp->setStatusCode(HttpResponse::k404NotFound);
            resp->setStatusMessage("Not Found");
            resp->setCloseConnection(true);
        }

        // void setThreadNum(int numThreads) {
        //     server_.setThreadNum(numThreads);
        // }

        // void start();

    private:
        void onConnection(const ConnectionPtr &conn);
        void onMessage(const ConnectionPtr &conn, Buffer* buf, Timestamp recvTime);
        void onRequest(const ConnectionPtr& , const HttpCallback&); 

        Server server_;
        HttpCallback httpCallback_;
};