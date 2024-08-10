#pragma once

#include <net/EventLoop.h>
#include <net/EventLoopThread.h>
#include <functional>
#include <memory>
#include <vector>

namespace zero {
class EventLoop;
class EventLoopThread;

class EventLoopThreadPoll  {
public:
    using ThreadInitCallback = std::function<void(EventLoop*)>;

    EventLoopThreadPoll(EventLoop* baseLoop,const std::string &nameArg);
    ~EventLoopThreadPoll();
    void setThreadNum(uint32_t numThreads) {
        numThreads_ = numThreads;
    } 

    void start(const ThreadInitCallback& cb = ThreadInitCallback());

    /* 如果工作在多线程中，baseLoop_默认以轮询的防止分派channel给subloop */
    EventLoop* getNextLoop();
    /* 返回了池里的所有线程 */
    std::vector<EventLoop*> getAllLoops();
    bool started() const { return started_; }
    const std::string name() const { return name_; }

private:
    /* 用户创建的loop */
    EventLoop* mainLoop_; 
    std::string name_;
    bool started_;
    int next_;
    uint32_t numThreads_;
    std::vector<std::unique_ptr<EventLoopThread>> threads_;
    std::vector<EventLoop*> loops_;
};

}