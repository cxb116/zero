#include <net/TcpServer.h>
#include <net/Acceptor.h>
#include <net/EventLoop.h>
#include <net/EventLoopThreadPool.h>
#include <net/SocketsOps.h>
#include <string>
#include <stdio.h>
#include <memory>
namespace zero {
TcpServer::TcpServer(EventLoop* loop, const InetAddress& listenAddr, const std::string& nameArg, Option option)
    : loop_(loop)
    , ipPort_(listenAddr.toIpPort())
    , name_(nameArg)
    , acceptor_(new Acceptor(loop,listenAddr,option==kReusePort))
    , threadPool_(new EventLoopThreadPool(loop,name_))
    , connectionCallback_(defaultConnectionCallback)
    , nextConnId_(1) {
    acceptor_->setNewConnectionCallback(
        std::bind(&TcpServer::newConnection, this, _1, _2));
    }
TcpServer::~TcpServer() {

}

void TcpServer::newConnection(int sockfd, const InetAddress& peerAddr) {

}

//TODO  重点

void TcpServer::start() {
    if(started_.getAndAdd(1) == 0){  // 第一次调用start 开启线程池,防止一个tcpserver 多次调用start被多次
        threadPool_->start(threadInitCallback_);
        /* 仿函数绑定成员函数  */
        loop_->runInLoop(std::bind(&Acceptor::listen,acceptor_.get()));
    }

}

void TcpServer::removeConnection(const TcpConnectionPtr& conn){

}
void TcpServer::removeConnectionInLoop(const TcpConnectionPtr& conn) {

}

}
