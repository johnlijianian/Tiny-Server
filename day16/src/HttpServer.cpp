#include <iostream>
#include <functional>
#include <any>
#include "Server.h"
#include "HttpServer.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "HttpContext.h"
#include "Connection.h"
#include "Buffer.h"

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
        std::cout << "(GET/POST)" << std::endl;
        start = space+1;
        space = std::find(start, end, ' ');
        if (space != end) {
            request.setPath(start, space);	// 解析PATH
            std::cout << start << std::endl;
            std::cout << space << std::endl;
            start = space+1;
            succeed = (end-start == 8) && std::equal(start, end-1, "HTTP/1.");
            std::cout << "succeed:" << succeed << std::endl;
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
    std::cout << "succeed:" << succeed << std::endl;
    std::cout << "processRequestLine finish" <<std::endl;
    return succeed;
}

bool parseRequest(Buffer* buf, HttpContext* context){
    bool ok = true;
    bool hasMore = true;
    std::cout << "paraseRequest" << std::endl;
    buf->ToStr();
    while (hasMore){
        if(context->expectRequestLine()) { // 请求行
            int crlf = buf->findCRLF(); //请求行和请求头中间有CRLF
            std::cout << "crlf:" << crlf << std::endl;
            if (crlf > 0) {
                ok = processRequestLine(buf->peek(), buf->peek()+crlf, context);	// 解析请求行
                if (ok){
                    std::cout << "ok" << std::endl;
                    context->request().setReceiveTime(Timestamp::now());		// 设置请求时间
                    buf->clear();
                    buf->ToStr() ;
                    buf->append(buf->peek()+crlf + 2);		// 将请求行从buf中取回，包括\r\n
                    context->receiveRequestLine();	// 将HttpContext状态改为kExpectHeaders
                } else {
                    hasMore = false;
                }
            } else {
                hasMore = false;
            }
        } else if(context->expectHeaders()) { // 请求头
            // std::cout << "request header" << std::endl;
            const char* crlf = buf->peek()+buf->findCRLF();

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

void defaultHttpCallback(const HttpRequest&, HttpResponse* resp) {
  resp->setStatusCode(HttpResponse::k404NotFound);
  resp->setStatusMessage("Not Found");
  resp->setCloseConnection(true);
}

HttpServer::HttpServer(EventLoop* loop
            // const InetAddress& listenAddr,
            // const string& name
):
    server_(new Server(loop)), 
    httpCallback_(defaultHttpCallback) 
{
    server_->setConnectionCallback(std::bind(&HttpServer::onConnection, this, std::placeholders::_1));
    server_->setMessageCallback(std::bind(&HttpServer::onMessage, this, std::placeholders::_1, std::placeholders::_2));
}

HttpServer::~HttpServer() {}

void HttpServer::onConnection(Connection* conn){
    std::cout << "HttpServer::onConnection" << std::endl;
    conn->setContext(HttpContext()); // TcpConnection与一个HttpContext绑定
}

void HttpServer::onMessage(Connection* conn, Buffer* buf){
    std::cout << "HttpServer::onMessage" << std::endl;

    HttpContext *context = std::any_cast<HttpContext>(conn->getMutableContext());
    if(!parseRequest(buf, context)) {
        conn->SetSendBuffer(std::string("HTTP/1.1 400 Bad request\r\n\r\n").c_str());
        conn->Write();
        std::cout<<"无法访问"<<std::endl;
        exit(1);
    }

    // 请求消息解析完毕
    if (context->gotAll()){
        onRequest(conn, context->request());
        context->reset();		// 本次请求处理完毕，重置HttpContext，适用于长连接
    }
}

void HttpServer::onRequest(Connection* conn, HttpRequest& req){
    const std::string& connection = req.getHeader("Connection");
    bool close = (connection == "close" ||
        (req.getVersion() == HttpRequest::kHttp10 && connection != "Keep-Alive")); //判断是否是长连接
    HttpResponse response(close);
    httpCallback_(req, &response);
    Buffer buf;
    response.appendToBuffer(&buf);
    conn->SetSendBuffer(buf.ToStr());
    conn->Write();
    // if (response.closeConnection()) {
    //     conn->shutdown();
    // }
}
