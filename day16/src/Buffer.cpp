#include "Buffer.h"
#include <string>
#include <iostream>
#include <cstring>
Buffer::Buffer()
{
}

Buffer::~Buffer()
{
}

const std::string Buffer::kCRLF = "\r\n";


void Buffer::append(const char* _str, int _size){
    for(int i = 0; i < _size; ++i){
        if(_str[i] == '\0') break;
        buf.push_back(_str[i]);
    }
}

void Buffer::append(const char* _str){
    int size = strlen(_str);
    append(_str, size);
}

void Buffer::append(const std::string _str){
    buf.append(_str);
}

ssize_t Buffer::size(){
    return buf.size();
}

const char* Buffer::ToStr(){
    std::cout << buf <<std::endl;
    return buf.c_str();
}

void Buffer::clear(){
    buf.clear();
}

void Buffer::getline(){
    buf.clear();
    std::getline(std::cin, buf);
}

void Buffer::setBuf(const char* _buf){
    buf.clear();
    buf.append(_buf);
}