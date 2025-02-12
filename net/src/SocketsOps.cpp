#include <base/Types.h>

#include <base/Endian.h>
#include <net/SocketsOps.h>
#include <boost/implicit_cast.hpp>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>

using namespace zero;
using namespace zero::net;

void setNonBlockAndCloseOnExec(int sockfd) {
    int flags = ::fcntl(sockfd,F_GETFL,0);
    flags |= O_NONBLOCK;
    int ret = ::fcntl(sockfd, F_SETFL,flags);

    /* close-on-exec */
    flags = ::fcntl(sockfd,F_GETFD,0);
    flags |= FD_CLOEXEC;
    ret = ::fcntl(sockfd,F_SETFD,flags);
    (void) ret;
}


/* ipv6 implicit transition */
const struct sockaddr*  sockets::sockaddr_cast(const struct sockaddr_in6* addr){
    return static_cast<const struct sockaddr*>(boost::implicit_cast<const void*>(addr)); 
}

struct sockaddr* sockets::sockaddr_cast(struct sockaddr_in6* addr){
    return static_cast<struct sockaddr*>(boost::implicit_cast<void*>(addr));
}

// const struct sockaddr* sockets::sockaddr_cast(const struct sockaddr_in* addr){
//     return static_cast<const struct sockaddr*>(boost::implicit_cast<void*>(addr));
// }

// struct sockaddr* sockets::sockaddr_cast(struct sockaddr_in* addr){
//     return static_cast<struct sockaddr*>(implicit_cast<void*>(addr));
// }

// const struct sockaddr_in6* sockets::sockaddr_in6_cast(const struct sockaddr_in* addr) {
//     return static_cast<const struct sockaddr_in6*> (implicit_cast<void*>(addr));
// }

// const struct sockaddr_in* sockets::sockaddr_in_cast(const struct sockaddr_in6* addr) {
//     return static_cast<const struct sockaddr_in*>(implicit_cast<void*>(addr));
// }

int sockets::createNonblockingOrDie(sa_family_t family) {
    int sockfd = ::socket(family, SOCK_STREAM | SOCK_NONBLOCK |SOCK_CLOEXEC, IPPROTO_TCP);
    if(sockfd < 0) {
        printf("sockets::createNonblockingOrDie\n");
    }
    return sockfd;
}

void sockets::listenOrDie(int sockfd) {
    int ret = ::listen(sockfd,SOMAXCONN);
    if(ret < 0) {
        printf("sockets::listenOrDie");
    }
}

int sockets::accept(int sockfd,struct sockaddr_in6* addr) {
    socklen_t addrlen = static_cast<socklen_t>(sizeof *addr);
    int connfd = ::accept(sockfd,sockaddr_cast(addr),&addrlen);
    setNonBlockAndCloseOnExec(connfd);
    if(connfd < 0) {
       // LOG_SYSERR<"socket::accept";
        printf("socket::accept failed\n");
    }
    return connfd;
}

int sockets::connect(int sockfd,const struct sockaddr* addr) {
    return ::connect(sockfd,addr,static_cast<socklen_t>(sizeof(struct sockaddr_in6)));
}

ssize_t sockets::read(int sockfd,void* buf, size_t count) {
    return ::read(sockfd,buf,count);
}

ssize_t sockets::readv(int sockfd,const struct iovec* iov,int iovcnt) {
    return ::readv(sockfd,iov,iovcnt);
}

void sockets::close(int sockfd){
    if(::close(sockfd) < 0) {
         printf("sockets::close");
    }
    printf("sockets close success \n");
}

void sockets::shutdownWrite(int sockfd) {
    if(::shutdown(sockfd,SHUT_WR) < 0) {
        printf("sockets::shutdownWrite");
    } 
}

void sockets::fromIpPort(const char* ip,uint16_t port,struct sockaddr_in* addr) {
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    if(::inet_pton(AF_INET,ip,&addr->sin_port)<=0) {
        printf("sockets:: fromIpPort");
    }
}

int sockets::getSocketError(int sockfd) {
    int optval;
    socklen_t optlen = static_cast<socklen_t>(sizeof(optval));
    if(::getsockopt(sockfd,SOL_SOCKET,SO_ERROR,&optval,&optlen)<0) {
        return errno;
    } else {
        return optval;
    }
}

struct sockaddr_in6 sockets::getLocalAddr(int sockfd) {
    struct sockaddr_in6 localaddr;
    memset(&localaddr,0,sizeof(localaddr));
    socklen_t addrlen = static_cast<socklen_t>(sizeof(localaddr));
    if(::getsockname(sockfd,sockaddr_cast(&localaddr),&addrlen)<0) {
         printf("sockets::getLocalAddr");
    }
    return localaddr;
}

struct sockaddr_in6 sockets::getPeerAddr(int sockfd) {
    struct sockaddr_in6 peeraddr;
    memset(&peeraddr,0,sizeof(peeraddr));
    socklen_t addrlen = static_cast<socklen_t>(sizeof(peeraddr));
    if(::getpeername(sockfd,sockaddr_cast(&peeraddr),&addrlen) < 0) {
         printf("sockets::getPeerAddr");
    }
    return peeraddr;
}

bool sockets::isSelfConnect(int sockfd) 
{
    struct sockaddr_in6 localaddr = getLocalAddr(sockfd);
    struct sockaddr_in6 peeraddr = getPeerAddr(sockfd);
    if(localaddr.sin6_family == AF_INET) {
        const struct sockaddr_in* laddr4 = reinterpret_cast<struct sockaddr_in*>(&localaddr);
        const struct sockaddr_in* raddr4 = reinterpret_cast<struct sockaddr_in*>(&peeraddr);
        return laddr4->sin_port == raddr4->sin_port &&
               laddr4->sin_addr.s_addr == raddr4->sin_addr.s_addr;    
    } else {
        return false;
    }
}



