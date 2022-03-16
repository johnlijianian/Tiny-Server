#include <iostream>
#include <map>
#include "HttpServer.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

// 实际的请求处理
void onRequest(const HttpRequest& req, HttpResponse* resp) {
    std::cout << "Headers " << req.methodString() << " " << req.path() << std::endl;
    if (!benchmark) {
        const std::map<string, string>& headers = req.headers();
        for (std::map<string, string>::const_iterator it = headers.begin();
            it != headers.end();
            ++it)
        {
        std::cout << it->first << ": " << it->second << std::endl;
        }
    }

  if (req.path() == "/") {
    resp->setStatusCode(HttpResponse::k200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType("text/html");
    resp->addHeader("Server", "Muduo");
    string now = Timestamp::now().toFormattedString();
    resp->setBody("<html><head><title>This is title</title></head>"
        "<body><h1>Hello</h1>Now is " + now +
        "</body></html>");
  } else if (req.path() == "/favicon.ico") {
    resp->setStatusCode(HttpResponse::k200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType("image/png");
    resp->setBody(string(favicon, sizeof favicon));
  } else if (req.path() == "/hello") {
    resp->setStatusCode(HttpResponse::k200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType("text/plain");
    resp->addHeader("Server", "Muduo");
    resp->setBody("hello, world!\n");
  } else {
    resp->setStatusCode(HttpResponse::k404NotFound);
    resp->setStatusMessage("Not Found");
    resp->setCloseConnection(true);
  }
}

int main(int argc, char* argv[])
{
  int numThreads = 0;
  if (argc > 1)
  {
    benchmark = true;
    Logger::setLogLevel(Logger::WARN);
    numThreads = atoi(argv[1]);
  }
  EventLoop loop;
  HttpServer server(&loop, InetAddress(8000), "dummy");
  server.setHttpCallback(onRequest);
  server.setThreadNum(numThreads);
  server.start();
  loop.loop();
}