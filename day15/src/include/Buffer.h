#pragma once
#include <string>

class Buffer
{
private:
    std::string buf;
public:
    Buffer();
    ~Buffer();
    
    void append(const char* _str, int _size);
    void append(const char* _str);
    void append(const std::string _str);
    ssize_t size();
    const char* ToStr();
    void clear();
    void getline();
    void setBuf(const char*);
    const char* ToStrm();
};
