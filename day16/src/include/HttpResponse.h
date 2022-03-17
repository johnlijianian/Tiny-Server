
// status line + header + body （header分为普通报头，响应报头与实体报头）

// header与body之间有一空行（CRLF）

// 状态响应码
// 1XX  提示信息 - 表示请求已被成功接收，继续处理
// 2XX  成功 - 表示请求已被成功接收，理解，接受
// 3XX  重定向 - 要完成请求必须进行更进一步的处理
// 4XX  客户端错误 -  请求有语法错误或请求无法实现
// 5XX  服务器端错误 -   服务器执行一个有效请求失败

// HTTP/1.1 200 OK
// Content-Length: 112
// Connection: Keep-Alive
// Content-Type: text/html
// Server: Muduo
// (CRLF)
// <html><head><title>This is title</title></head><body><h1>Hello</h1>Now is 20130611 02:14:31.518462</body></html>

#pragma once
#include <string>
#include <map>
class Buffer;
class HttpResponse{
    public:
        enum HttpStatusCode {
            kUnknown,
            k200Ok = 200,		// 成功
            k301MovedPermanently = 301,		// 301重定向，请求的页面永久性移至另一个地址
            k400BadRequest = 400,			// 错误的请求，语法格式有错，服务器无法处理此请求
            k404NotFound = 404,		// 请求的网页不存在
        };

        explicit HttpResponse(bool close): statusCode_(kUnknown), closeConnection_(close){}

        void setStatusCode(HttpStatusCode code) { statusCode_ = code; }

        void setStatusMessage(const std::string& message) { statusMessage_ = message; }

        void setCloseConnection(bool on) { closeConnection_ = on; }

        bool closeConnection() const { return closeConnection_; }

        // 设置文档媒体类型（MIME）
        void setContentType(const std::string& contentType) { addHeader("Content-Type", contentType); }

        void addHeader(const std::string& key, const std::string& value) { headers_[key] = value; }

        void setBody(const std::string& body) { body_ = body; }

        void appendToBuffer(Buffer* output) const;	// 将HttpResponse添加到Buffer

    private:
        std::map<std::string, std::string> headers_;	// header列表
        HttpStatusCode statusCode_;			// 状态响应码
        std::string statusMessage_;				// 状态响应码对应的文本信息
        bool closeConnection_;				// 是否关闭连接
        std::string body_;							// 实体
};