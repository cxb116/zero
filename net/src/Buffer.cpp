#include <net/Buffer.h>
#include <sys/uio.h>
#include <unistd.h>

namespace zero {
/**
 *   从fd 上去读数据，poller 工作在LT模式
    struct iovec {
        void* iov_base;     缓冲区的起始地址
        size_t iov_len;     缓冲区到长度
    }
**/
ssize_t Buffer::readFd(int fd,int* saveErrno) {
    char extrabuf[65536] ={0};  /*栈上的内存空间 */
    struct iovec vec[2];
    const size_t writable = writableBytes(); //buff 的缓冲区剩余可写空间
    /*首先写入vec[0],如果数据很大写满vec[0],会在vec[i]写入， */
   vec[0].iov_base = begin() + writerIndex_;
    vec[0].iov_len = writable;

    vec[1].iov_base = extrabuf;
    vec[1].iov_len = sizeof(extrabuf);

    const int iovcnt = (writable < sizeof(extrabuf) ? 2 : 1);

    const ssize_t n = ::readv(fd,vec,iovcnt);
    if(n < 0) {
        printf("error failed \n");
    } else if(n <= writable) {//writable 够存储写入的数据
        writerIndex_  += n;
    } else {// extrabuf 也写入了数据
        writerIndex_ = buffer_.size();
        append(extrabuf,n - writable);
    }
    return n;
}

ssize_t Buffer::writeFd(int fd) {
    ssize_t n = ::write(fd,peek(),readableBytes());
    if(n < 0) {
        printf("write error \n");
    } else if(n >= 0) {
        
    }
    return n;
}

}