#pragma once
#include <base/Atomic.h>
#include <base/Types.h>
#include <net/TcpConnection.h>
#include <net/Callbacks.h>
#include <map>
#include <string>
#include <memory>
#include <net/EventLoopThreadPool.h>
#include <net/EventLoop.h>
#include <net/InetAddress.h>
namespace zero {
class Acceptor;
class EventLoop;
class EventLoopThreadPool;

class TcpServer {
public:
    /* 线程初始化回调 */
    using ThreadInitCallback = std::function<void(EventLoop*)>;
    enum Option {
        kNoReusePort,
        kReusePort,
    };

    TcpServer(EventLoop* loop, const InetAddress& listenAddr, const std::string& nameArg, Option option = kNoReusePort);
    ~TcpServer();
    /* 开启服务器监听 */
    void start();
   
    void setThreadNum(int numThreads) { threadPool_->setThreadNum(numThreads);}
    
    void setThreadInitCallback(const ThreadInitCallback& cb) {threadInitCallback_ = cb;}
    void setConnectionCallback(const ConnectionCallback& cb) { connectionCallback_ = cb; }
    void setMessageCallback(const MessageCallback& cb) { messageCallback_ = cb; };
    void setWriteCompleteCallback(const WriteCompleteCallback& cb) { writeCompleteCallback_ = cb; }



private:
    /* mainloop调用newConection 新连接回调 */
    void newConnection(int sockfd, const InetAddress& peerAddr);
    /* 不要这条连接 */
    void removeConnection(const TcpConnectionPtr& conn);
    void removeConnectionInLoop(const TcpConnectionPtr& conn);
    using ConnectionMap = std::map<std::string, TcpConnectionPtr>;
    ConnectionMap connections_;


    /* mainloop 用户定义loop */
    EventLoop* loop_;
    const std::string name_;
    const std::string ipPort_;
    /* 线程池 one loop per thread */
    std::shared_ptr<EventLoopThreadPool> threadPool_;
    std::unique_ptr<Acceptor> acceptor_;
    /* 线程初始化回调 */
    ThreadInitCallback threadInitCallback_;

    /* 连接回调*/
    ConnectionCallback connectionCallback_;
    MessageCallback messageCallback_;
    /* 连接断开回调 */
    CloseCallback closeCallback_;
    /* 写完成回调 */
    WriteCompleteCallback writeCompleteCallback_;
    /* 高水位回调 */
    HighWaterMarkCallback highWaterMarkCallback_;
    /* 连接id */
    int nextConnId_;


    /* 是否启用线程池 */
    bool startThreadPool_;
    /* 是否启用线程池 */
    AtomicInt32 started_;

};



}