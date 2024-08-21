#include <net/Acceptor.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/InetAddress.h> 
namespace zero {
static int createNonlocking() {
    int sockfd = ::socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, IPPROTO_TCP);
    return sockfd;
}

/* 创建一个非阻塞的socket文件描述符 */
Acceptor::Acceptor(EventLoop* loop, const InetAddress& listenAddr, bool reusePort) 
    : loop_(loop)
    , acceptSocket_(createNonlocking())
    , acceptChannel_(loop, acceptSocket_.fd())
    , listening_(false) {

    acceptSocket_.setReuseAddr(true);
    acceptSocket_.setReusePort(reusePort);
    acceptSocket_.bindAddress(listenAddr);
    /*TcpServer::start() Accept.listen 有新用户的连接
    要执行一个回调，(connfd ==> channel => subloop ) */
    /* 有新用户连接，要执行一个回调 */
    acceptChannel_.setReadCallback(std::bind(&Acceptor::handleRead, this));
}

Acceptor::~Acceptor() {
    acceptChannel_.disableAll();
    acceptChannel_.remove();

}
/* 监听描述符有事件发生了，需要执行回调 */
void Acceptor::listen() {
    /* 有新用户连接 */
    listening_ = true;
    acceptSocket_.listen();
    acceptChannel_.enableReading();
}
/* 当有新用户连接时，要执行一个回调 */
void Acceptor::handleRead() {
    InetAddress peerAddr;
    int connfd = acceptSocket_.accept(&peerAddr);
    if (connfd >= 0) {
        if (newConnectionCallback_) {
            newConnectionCallback_(connfd, peerAddr);
        } else {
            ::close(connfd);
        }
    } else {
        printf("Acceptor::handleRead \n");
    }
} 


}