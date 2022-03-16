#include <functional>
#include "HttpServer.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

HttpServer::HttpServer(){}

// void onConnection(const ConnectionPtr &conn);
// void onMessage(const ConnectionPtr &conn, Buffer* buf, Timestamp recvTime);
// void onRequest(const ConnectionPtr& , const HttpCallback&); 

// FIXME: move to HttpContext class
bool processRequestLine(const char* begin, const char* end, HttpContext* context) {
    bool succeed = false;
    const char* start = begin;
    const char* space = std::find(start, end, ' ');
    HttpRequest& request = context->request();
    if (space != end && request.setMethod(start, space)) { // 解析请求方法(GET/POST)
        start = space+1;
        space = std::find(start, end, ' ');
        if (space != end) {
            request.setPath(start, space);	// 解析PATH
            start = space+1;
            succeed = end-start == 8 && std::equal(start, end-1, "HTTP/1.");
            if (succeed)
            {
                if (*(end-1) == '1')
                {
                request.setVersion(HttpRequest::kHttp11);		// HTTP/1.1
                }
                else if (*(end-1) == '0')
                {
                request.setVersion(HttpRequest::kHttp10);		// HTTP/1.0
                }
                else
                {
                succeed = false;
                }
            }
        }
    }
    return succeed;
}

bool parseRequest(Buffer* buf, HttpContext* context, Timestamp receiveTime){
    bool ok = true;
    bool hasMore = true;

    while (hasMore){
        if(context->expectRequestLine()) { // 请求行
            const char* crlf = buf->findCRLF(); //请求行和请求头中间有CRLF
            if (crlf) {
                ok = processRequestLine(buf->peek(), crlf, context);	// 解析请求行
                if (ok){
                    context->request().setReceiveTime(receiveTime);		// 设置请求时间
                    buf->retrieveUntil(crlf + 2);		// 将请求行从buf中取回，包括\r\n
                    context->receiveRequestLine();	// 将HttpContext状态改为kExpectHeaders
                } else {
                    hasMore = false;
                }
            } else {
                hasMore = false;
            }
        } else if(context->expectHeaders()) { // 请求头
            const char* crlf = buf->findCRLF();

            if (crlf) {
                const char* colon = std::find(buf->peek(), crlf, ':');		//冒号所在位置
                if (colon != crlf) {
                    context->request().addHeader(buf->peek(), colon, crlf);
                } else {
                    // empty line, end of header
                    context->receiveHeaders();		// HttpContext将状态改为kGotAll
                    hasMore = !context->gotAll();
                }
            } else {
                hasMore = false;
            }
        } else if(context->expectBody()) { // 请求体，暂未实现 [一般存放请求的数据]

        }
    }

    return ok;
}

HttpServer::HttpServer(EventLoop* loop,
            // const InetAddress& listenAddr,
            // const string& name
):
    server_(loop), 
    httpCallback_(std::bind(&HttpServer::defaultHttpCallback, this)) {
    // [Server_]void OnConnect(std::function<void(Connection *)> fn);  //处理客户端请求
    server_.newConnection(std::bind(&HttpServer::onConnection, this, std::placeholders::_1));
    server_.onMessage(std::bind(&HttpServer::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

HttpServer::~HttpServer() {}

void HttpServer::onConnection(const ConnectionPtr &conn){
    conn->setContext(HttpContext()); // TcpConnection与一个HttpContext绑定
}

void HttpServer::onMessage(const ConnectionPtr& conn, Buffer* buf, Timestamp receiveTime){
    HttpContext *context = std::any_cast<HttpContext>(conn->getMutableContext());
    if(!parseRequest(buf, context, receiveTime)) {
        conn->send("HTTP/1.1 400 Bad Request\r\n\r\n");
        conn->shutdown();
    }

    // 请求消息解析完毕
    if (context->gotAll()){
        onRequest(conn, context->request());
        context->reset();		// 本次请求处理完毕，重置HttpContext，适用于长连接
    }
}

void HttpServer::onRequest(const ConnectionPtr& conn, const HttpRequest& req){
    const string& connection = req.getHeader("Connection");
    bool close = connection == "close" ||
        (req.getVersion() == HttpRequest::kHttp10 && connection != "Keep-Alive"); //判断是否是长连接
    HttpResponse response(close);
    httpCallback_(req, &response);
    Buffer buf;
    response.appendToBuffer(&buf);
    conn->send(&buf);
    if (response.closeConnection()) {
        conn->shutdown();
    }
}
