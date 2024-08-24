#pragma once
#include <vector>
#include <algorithm>
#include <stddef.h>
#include <vector>
#include <string>

 /* 
    A buffer 
    + ———————————————————— + ———————————————————————————————————————
    |   prependable bytes  |   readable bytes  |   writable bytes  |
    |                      |                   |                   |
    + ———————————————————— + ————————————————— + ———————————————————
    |                      |                   |                   |
    0         <=        readerIndex   <=   writerIndex    <=      size
 */
namespace zero {

class Buffer {
public:
    static const size_t kCheapPrepend = 8;
    static const size_t kInitialSize = 1024;

    explicit Buffer(size_t initialSize = kInitialSize)
        : buffer_(kCheapPrepend + initialSize),
          readerIndex_(kCheapPrepend),
          writerIndex_(kCheapPrepend) {
    }
    
    /* 可读缓冲区大小 */
    size_t readableBytes() const { return writerIndex_ - readerIndex_; }
    /* 可写缓冲区大小 */
    size_t writableBytes() const { return buffer_.size() - writerIndex_; }
    
    size_t prependableBytes() const { return readerIndex_; }
    /* 缓冲区到可读数据的起始地址 */
    const char* peek() const {
        return begin() + readerIndex_;
    }
    /* onMessage string <- Buffer */
    void retrieve(size_t len) {
        if(len < readableBytes()) {
            readerIndex_ += len;
        } else { 
            /* 可读缓存区 */
            size_t readable = readableBytes();
            std::copy(begin() + readerIndex_,
                     begin() + writerIndex_,
                     begin() + kCheapPrepend);
            readerIndex_ = kCheapPrepend;
            writerIndex_ = readerIndex_ + readable;
        }
    }

    void retrieveAll() {
        readerIndex_  = writerIndex_ = kCheapPrepend;  
    }

    /* 把onMessage函数上报的buffer数据转成string类型的数据返回 */
    std::string retrieveAllString() {
        return retrieveAsString(readableBytes());
    }

    std::string retrieveAsString(size_t len) {
        std::string result(peek(),len);
        retrieve(len);
        return result;  
    } 
    // buffer_.size - writerIndex_ len  可写区域 
    void ensureWriteableBytes(size_t len) {
        if(writableBytes() < len) {
            makeSpace(len);  /* 扩容函数 */
        }
    }

    void makeSpace(size_t len) {
        /**
         * 可写缓冲区+首部长度  <  len + 8 那就要扩容了
        */
        if(writableBytes() + prependableBytes() < len + kCheapPrepend) {
            buffer_.resize(writerIndex_ + len);
        }
    } 
    /* 写入拼接 */
    void append(const char* data,size_t  len) {
        ensureWriteableBytes(len);
        std::copy(data,data+len,beginWrite());
        writerIndex_ += len;
    }

    char* beginWrite() {
        return begin() + writerIndex_;
    }
    const char* beginWrite() const {
        return begin() + writerIndex_;
    }

    /* 从fd 上读取数据 */
    ssize_t readFd(int fd,int* saveErrno);
    ssize_t writeFd(int fd);
private:
    /* 获取首地址*/
    char* begin() {
        return &*buffer_.begin();
    }
    /* 获取首地址*/
    const char* begin() const {
        return &*buffer_.begin();
    }

    char beigin_index() {
        return *buffer_.begin();
    }



    std::vector<char> buffer_;
    size_t readerIndex_;
    size_t writerIndex_;

};
}