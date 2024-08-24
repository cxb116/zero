#include <net/TcpConnection.h>
#include <string>
#include <net/Socket.h>
#include <net/Channel.h>
#include <net/EventLoop.h>
#include <functional>
#include <memory>

namespace zero {
TcpConnection::TcpConnection(EventLoop* loop, const std::string& name,
            int sockfd, const InetAddress& localAddr,const InetAddress& peerAddr) 
    : loop_(loop),
      name_(name),
      state_(kConnecting),
      reading_(true),
      socket_(new Socket(sockfd)),
      channel_(new Channel(loop,sockfd)),
      localAddr_(localAddr),
      peerAddr_(peerAddr),
      higWaterMark_(64*1024*1024) //64M
      {
        channel_->setReadCallback(std::bind(&TcpConnection::handleRead,this,_1));
        channel_->setWriteCallback(std::bind(&TcpConnection::headleWrite,this));
        channel_->setCloseCallback(std::bind(&TcpConnection::handleClose,this));
        channel_->setErrorCallback(std::bind(&TcpConnection::handleError,this)); 
        socket_->setKeepAlive(true);
}

TcpConnection::~TcpConnection() {
    printf("~TcpConnection \n");
}

void TcpConnection::shutdown(){

 }

void TcpConnection::handleRead(Timestamp receiveTime) {
    int saveErrno = 0;
    ssize_t n = inputBuffer_.readFd(channel_->fd(),&saveErrno);
    if(n > 0) {
        /* 已建立连接的用户，有可读书事件发生了，调用用户传入的回调操作 */
        messageCallback_(std::shared_from_this(),&inputBuffer_,receiveTime);
    } else if(n == 0) {  /* 断开 */
        handleClose();
    } else {            /* 出错了*/
        handleError(); 
    }
}
void TcpConnection::handleWrite() {
    if(channel_->isWriting()) {
        ssize_t n = outputBuffer_.writeFd(channel_->fd());
        if(n > 0) {
            outputBuffer_.retrieve(n);
            if(outputBuffer_.readableBytes() == 0) {
                channel_->disableWriteing();
                if(writeCompleteCallback_) {
                    loop_->queueInLoop(
                        /* 唤醒loop_ 对应的thread 线程执行回调 */
                        std::bind(writeCompleteCallback_,std::shared_from_this()));
                } 
                if(state_ == kDisconnecting) {
                    shutdownInLoop();
                }
            }
        }
    } else {
        printf("TcpConnection not  write data \n");
    }
}
void TcpConnection::handleClose() {
    printf("handleClose start  /n");
    setState(kDisconnected);
    channel_->disableAll();

    TcpConnectionPtr connptr(std::shared_from_this());
    connectionCallback_(connptr);  //执行连接关闭的回调
    closeCallback_(connptr);         // 关闭连接的回调
}
void TcpConnection::handleError() {
    int optval;
    socklen_t optlen = sizeof optval;
    if(::getsockopt(channel_->fd(),SOL_SOCKET, SO_ERROR, &optval, &optlen) {
        printf("TcpConection erron /n");
     }
}

void TcpConnection::sendInLoop(const void* message, size_t len) {

}
void TcpConnection::shutdownInLoop(){

}
/* 连接建立 */
void TcpConnection::connectEstablished() {

}

/* 连接销毁 */
void TcpConnection::connectDestroyed() {

}

}
