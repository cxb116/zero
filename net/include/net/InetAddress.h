#pragma once
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
namespace zero {

class InetAddress {
public:
    explicit InetAddress(uint16_t port = 8888, std::string ip = "127.0.0.1");

    explicit InetAddress(const struct sockaddr_in& addr)
        :addr_(addr){

    }
    std::string toIp() const;
    std::string toIpPort() const;
    uint16_t toPort() const ;

    const sockaddr_in getSockAddr_in() const { return addr_;}
    const sockaddr* getSockaddr() const { return reinterpret_cast<const sockaddr*>(&addr_);}
    void setSockedAddr(const sockaddr_in& addr) { addr_ = addr; }
private:
    sockaddr_in addr_;

};

}