#include "Buffer.h"
#include "HttpResponse.h"
#include <map>
#include <string>
// status line + header + body （header分为普通报头，响应报头与实体报头）

// header与body之间有一空行（CRLF）

// 状态响应码
// 1XX  提示信息 - 表示请求已被成功接收，继续处理
// 2XX  成功 - 表示请求已被成功接收，理解，接受
// 3XX  重定向 - 要完成请求必须进行更进一步的处理
// 4XX  客户端错误 -  请求有语法错误或请求无法实现
// 5XX  服务器端错误 -   服务器执行一个有效请求失败

// HTTP/1.1 200 OK
// Content-Length: 112 (长连接才有)
// Connection: Keep-Alive (长连接才有)
// Content-Type: text/html
// Server: Muduo
// (CRLF)
// <html><head><title>This is title</title></head><body><h1>Hello</h1>Now is 20130611 02:14:31.518462</body></html>

void HttpResponse::appendToBuffer(Buffer* output) const{
    char buf[32];

    // 添加响应头
    snprintf(buf, sizeof(buf), "HTTP/1.1 %d ", statusCode_);

    output->append(buf, sizeof(buf));
    output->append(statusMessage_);
    output->append("\r\n", sizeof("\r\n"));

    if (closeConnection_){
        // 如果是短连接，不需要告诉浏览器Content-Length，浏览器也能正确处理
        output->append("Connection: close\r\n", sizeof("Connection: close\r\n"));
    } else {
        snprintf(buf, sizeof buf, "Content-Length: %zd\r\n", body_.size());	// 实体长度
        output->append(buf);
        output->append("Connection: Keep-Alive\r\n");
    }

    // header列表
    for (std::map<std::string, std::string>::const_iterator it = headers_.begin(); it != headers_.end(); ++it) {
        output->append(it->first);
        output->append(": ");
        output->append(it->second);
        output->append("\r\n");
    }

    output->append("\r\n");	// header与body之间的空行
    output->append(body_);
}