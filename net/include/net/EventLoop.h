#pragma once
#include <iostream>
#include <functional>
#include <memory>
#include <atomic>
#include <vector>
#include <base/Timestamp.h>
#include <mutex>
#include <base/CurrentThread.h>

namespace zero {
class Channel; 
class Poller;
class EventLoop {
public:
    using Function = std::function<void()>;
    using poller_  = std::unique_ptr<Poller>;
    EventLoop();
    ~EventLoop();
    /* 开启事件循环 */
    void loop();
    /* 退出事件循环 */
    void quit();

    Timestamp lollReturnTime() const { return pollReturnTime_; }
    /* 在当前loop中执行cb */
    void runInLoop(Function cb);
    /* 把cb放入队列中，唤醒loop所在的线程执行cb */
    void queueInLoop(Function cb);
    /* 用来唤醒loop 所在的线程 */
    void weakup();
    /* */
    void updateChannel(Channel* channel);
    void removeChannel(Channel* channel);
    bool hasChannel(Channel* channel);
    /* 断言是否threadId是否相同 */
    bool isInLoopThread() {
        return threadId_ == CurrentThread::tid();
    }

private:

    void handleRead();
    void doPendingFunctions();

    using ChannelList = std::vector<Channel*>;

    std::atomic_bool looping_;  /* 当前looping是否开启 */ 
    std::atomic_bool quit_;     /* 表示退出loop 循环 */
    std::atomic_bool callingPendingFunctions_; /* 当前loop 是否需要执行回调 */

    const pid_t threadId_;      /* 记录当前loop 所在线程id* */
    Timestamp pollReturnTime_;  /* poller 返回发生时间的channels 的时间点 */
    poller_ Poller_ptr_;         /* poller 的智能指针 */

    int wakeupFd_;              /* 主要的作用，当mainLoop 获取一个新用户的channel ，通过一个轮询算法选择一个subloop,通过该成员唤醒subloop 处理channel*/
    std::unique_ptr<Channel> wakeupChannel_;
    
    ChannelList activeChannels_;
    Channel* currentActiveChannel_;
    std::vector<Function> pendingFunctions_; //存储loop需要执行的所有回调操作 
    std::mutex mutex_; // 保护vector的线程安全 
    bool eventHandling_;
};
}