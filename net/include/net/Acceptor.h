#pragma once
#include <net/EventLoop.h>
#include <net/InetAddress.h>
#include <net/Channel.h>
#include <net/Socket.h>
#include <string.h>
#include <stdio.h>
#include <functional>
#include <memory>
namespace zero {
class EventLoop;
class InetAddress;
class Acceptor {
public:
    using NewConnectionCallback = std::function<void(int sockfd, const InetAddress&)>;
    using accept_ptr = std::shared_ptr<Acceptor>;
    Acceptor(EventLoop* loop,const InetAddress& listenAddr,bool reusePort = false);
    ~Acceptor();
    void setNewConnectionCallback(const NewConnectionCallback& cb) {
        newConnectionCallback_ = cb;
    }
    bool listenning() const { return listening_; }
    void listen();

private:
    void handleRead();
    EventLoop* loop_;
    Socket acceptSocket_;
    Channel acceptChannel_;
    NewConnectionCallback newConnectionCallback_;
    bool listening_;
    accept_ptr accept_ptr_;

};


}