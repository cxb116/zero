#pragma once
#include <net/Buffer.h>
#include <net/InetAddress.h>
#include <net/Callbacks.h>
#include <net/EventLoop.h>
#include <string>
#include <atomic>
#include <memory>
namespace zero {
class Socket;
class Channel;
class Timestamp;
/*
    TcpConnection => Acceptor => 有一个新用户连接，通过accept 函数集体的回调操作拿到connfd
*/
class TcpConnection {
public:
    TcpConnection(EventLoop* loop,const std::string& name,int sockfd,const InetAddress& localAddr,
               const InetAddress& peerAddr);
    ~TcpConnection();

    EventLoop* getLoop() const { return loop_; }
    const std::string& name() const { return name_; }
    const InetAddress& localAddress() const { return localAddr_; }
    const InetAddress& peerAddr() const { return peerAddr_; }
    const int connected() const { return state_ == kConnected; }
    void send(const void* message, int len);
    void setConnectionCallback(const ConnectionCallback& cb) {
        connectionCallback_ = cb;
    }

    void setMessageCallback(const MessageCallback& cb) {
        messageCallback_ = cb;
    }

    void setWriteCompleteCallback(const WriteCompleteCallback& cb) {
        writeCompleteCallback_ = cb;
    }

    void setHighWaterMarkCallback(const HighWaterMarkCallback& cb,size_t highWaterMark) {
        highwaterMarkCallback_ = cb;
        higWaterMark_ = highWaterMark;
    }

    void setCloseCallback(const CloseCallback& cb) {
        closeCallback_ = cb;
    }

    /* 连接建立 */
    void connectEstablished();
    /* 连接销毁 */
    void connectDestroyed(); 
    /* 关闭当前连接 */
    void shutdown();
    
private:
    enum StateE {
        kDisconnected,
        kConnected,
        kConnecting,
        kDisconnecting
    }
    
    void setStateE(StateE state) {
        state_ = state;
    }
    void handleRead(Timestamp receiveTime);
    void handleWrite();
    void handleClose();
    void handleError();

    void sendInLoop(const void* message, size_t len);
    void shutdownInLoop();

    /* TcpConnection 是在subloop */
    EventLoop* loop_;
    const std::string name_;
    std::atomic_int state_;
    bool reading_;
    /* Accept==>mainloop    TcpConnect==>subloop */
    std::unique_ptr<Socket> socket_;
    std::unique_ptr<Channel> channel_;
    
    const InetAddress localAddr_;
    const InetAddress peerAddr_;

    ConnectionCallback connectionCallback_;
    MessageCallback messageCallback_;
    WriteCompleteCallback writeCompleteCallback_;
    HighWaterMarkCallback highwaterMarkCallback_;
    CloseCallback closeCallback_;
    /* 水位线 */
    size_t higWaterMark_;
    Buffer inputBuffer_;
    Buffer outputBuffer_;  /* 输出信息 */

};

}
