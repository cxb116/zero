#pragma once
#include <netinet/in.h>

namespace zero {
class InetAddress;
class Socket {
public:
    explicit Socket(int sockfd)
        :sockfd_(sockfd){

    }
    ~Socket();
    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;

    int fd() const { return sockfd_;}
    void bindAddress(const InetAddress& localaddr);
    void listen();
    int accept(InetAddress* peeraddr);

    void shutdownWrite();
    /* 直接发送 */
    void setTcpNoDelay(bool on);
    void setReuseAddr(bool on);
    void setReusePort(bool on);
    void setKeepAlive(bool on);

private:
    const int sockfd_;


};

}