#pragma once

#include <base/Thread.h>
#include <functional>
#include <memory>
#include <stdint.h>
#include <mutex>
#include <condition_variable>
#include <string>
#include <net/EventLoop.h>

namespace zero {
class EventLoop;
class EventLoopThread {
public:
    /* 开启one loop per thread 时调用 */
    using ThreadInitCallback = std::function<void(EventLoop*)>;
    using EventLoopThread_ptr = std::shared_ptr<EventLoopThread>;

    EventLoopThread(const ThreadInitCallback &cb= ThreadInitCallback(),
        const std::string &name = std::string());

    ~EventLoopThread();

    EventLoop* startLoop();
private:
    void threadFunc();

    EventLoop* loop_;
    bool exiting_;           /* 是否退出  */
    Thread thread_;   
    std::mutex mutex_;
    std::condition_variable cond_;
    ThreadInitCallback callback_;

};


}