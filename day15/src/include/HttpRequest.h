// request line + header + body （header分为普通报头，请求报头与实体报头）

// header与body之间有一空行（CRLF）

// 请求方法有：
// Get, Post, Head, Put, Delete等

// 协议版本1.0、1.1

// 常用请求头
// Accept：浏览器可接受的媒体（MIME）类型；
// Accept-Language：浏览器所希望的语言种类
// Accept-Encoding：浏览器能够解码的编码方法，如gzip，deflate等
// User-Agent：告诉HTTP服务器， 客户端使用的操作系统和浏览器的名称和版本
// Connection：表示是否需要持久连接，Keep-Alive表示长连接，close表示短连接

// GET / HTTP/1.1 
// Accept: image/jpeg, application/x-ms-application, image/gif, application/xaml+xml, image/pjpeg, application/x-ms-xbap, application/vnd.ms-excel, application/vnd.ms-powerpoint, application/msword, */*
// Accept-Language: zh-CN
// User-Agent: Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.1; Trident/4.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; Media Center PC 6.0; Tablet PC 2.0)
// Accept-Encoding: gzip, deflate
// Host: 192.168.159.188:8000
// Connection: Keep-Alive
#pragma once
#include <vector>

class HttpRequest{
public:
    enum Method {
        kInvalid, kGet, kPost, kHead, kPut, kDelete
    };
    enum Version {
        kUnknown, kHttp10, kHttp11
    };

    HttpRequest()
    : method_(kInvalid),
      version_(kUnknown) { }

    void setVersion(Version v)
    { version_ = v; }

    void getVersion() const
    { return version_;}

    bool setMethod(const char* start, const char* end) {
        assert(method_ == kInvalid);
        string m(start, end);
        if (m == "GET")
        {
        method_ = kGet;
        }
        else if (m == "POST")
        {
        method_ = kPost;
        }
        else if (m == "HEAD")
        {
        method_ = kHead;
        }
        else if (m == "PUT")
        {
        method_ = kPut;
        }
        else if (m == "DELETE")
        {
        method_ = kDelete;
        }
        else
        {
        method_ = kInvalid;
        }
        return method_ != kInvalid;
    }

    Method method() const
    { return method_; }

    const char* methodString() const {
        const char* result = "UNKNOWN";
        switch(method_)
        {
        case kGet:
            result = "GET";
            break;
        case kPost:
            result = "POST";
            break;
        case kHead:
            result = "HEAD";
            break;
        case kPut:
            result = "PUT";
            break;
        case kDelete:
            result = "DELETE";
            break;
        default:
            break;
        }
        return result;
    }

    void setPath(const char* start, const char* end) {
        path_.assign(start, end);
    }

    const string& path() const
    { return path_; }

    void setReceiveTime(Timestamp t)
    { receiveTime_ = t; }

    Timestamp receiveTime() const
    { return receiveTime_; }

    void addHeader(const char* start, const char* colon, const char* end){
        string field(start, colon);		// header域
        ++colon;
        // 去除左空格
        while (colon < end && isspace(*colon)) {
            ++colon;
        }
        string value(colon, end);		// header值
        // 去除右空格
        while (!value.empty() && isspace(value[value.size()-1])) {
            value.resize(value.size()-1);
        }
        headers_[field] = value;
    }

    string getHeader(const string& field) const {
        string result;
        std::map<string, string>::const_iterator it = headers_.find(field);
        if (it != headers_.end()){
            result = it->second;
        }
        return result;
    }

    const std::map<string, string>& headers() const
    { return headers_; }

    void swap(HttpRequest& that) {
        std::swap(method_, that.method_);
        path_.swap(that.path_);
        receiveTime_.swap(that.receiveTime_);
        headers_.swap(that.headers_);
    }

private:
    Method method_;     // 请求方法
    Version version_;	// 协议版本1.0/1.1
    string path_;		// 请求路径
    Timestamp receiveTime_;	// 请求时间
    std::map<string, string> headers_;	// header列表
};