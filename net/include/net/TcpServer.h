#pragma once

#include <base/Atomic.h>
#include <base/Types.h>
//#include <net/TcpConnection.h>
#include <net/Callbacks.h>
#include <map>
#include <string>
#include <memory>
#include <net/EventLoopThreadPool.h>

namespace zero {
class Acceptor;
class EventLoop;
class EventLoopThreadPool;

class TcpServer {
public:
    /* 线程初始化回调 */
   using ThreadInitCallback = std::function<void(EventLoop*)>;
    

   
private:
    /* mainloop 用户定义loop */
    EventLoop* loop_;
    const std::string name_;
    const std::string ipPort_;
    /* 线程池 one loop per thread */
    std::shared_ptr<EventLoopThreadPool> threadPool_;
    std::unique_ptr<Acceptor> acceptor_;
    /* 线程初始化回调 */
    ThreadInitCallback threadInitCallback_;
    /* 是否启用线程池 */
    bool startThreadPool_;
    /* 是否启用线程池 */
    bool started_;

};



}