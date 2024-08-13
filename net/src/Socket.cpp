#include <net/Socket.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/InetAddress.h>
namespace zero
{
Socket::~Socket() {
    close(sockfd_);
}

void Socket::bindAddress(const InetAddress& localaddr) {
    if (bind(sockfd_, localaddr.getSockaddr(),
               static_cast<socklen_t>(sizeof(struct sockaddr_in))) < 0) {
       printf("socket bind failed \n ");
    }
}

void Socket::listen() {
    if(::listen(sockfd_, 1024) < 0) {
        printf("socket listen failed \n");
    }
}
 
int Socket::accept(InetAddress* peeraddr) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    socklen_t len = static_cast<socklen_t>(sizeof(addr));
    int connfd = ::accept(sockfd_, (struct sockaddr*)&addr, &len); 
    if (connfd >= 0) {
        peeraddr->setSockedAddr(addr);
    }
    return connfd; 
}
/*关闭之前发送给所有登录用户的墙上消息。*/
void Socket::shutdownWrite() {
    if(::shutdown(sockfd_, SHUT_WR) < 0) {
        printf("socket shutdown write failed \n");
    }
}

void Socket::setTcpNoDelay(bool on) {
    // int optval = on ? 1 : 0;
    // ::setsockopt(sockfd_, IPPROTO_TCP, TCP_NODELAY,
    //              &optval, static_cast<socklen_t>(sizeof optval));
}
/* 重复使用Addr */
void Socket::setReuseAddr(bool on) { 
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_, SOL_SOCKET, SO_REUSEADDR,
                 &optval, static_cast<socklen_t>(sizeof optval));
}
/* 重复使用port */
void Socket::setReusePort(bool on) {
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_, SOL_SOCKET, SO_REUSEPORT,
                 &optval, static_cast<socklen_t>(sizeof optval));
}
/* 保持连接 */
void Socket::setKeepAlive(bool on) {
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_, SOL_SOCKET, SO_KEEPALIVE,
                 &optval, static_cast<socklen_t>(sizeof optval));
 }

}