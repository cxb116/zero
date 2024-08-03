 #pragma once 
#include "string.h"
#include <functional>
#include <memory>
#include <base/Timestamp.h>

namespace zero {
class EventLoop;
class Timestamp;

class Channel {
public:
    using EventCallback = std::function<void()>;
    using ReadEventCallback = std::function<void(Timestamp)>;

    Channel(EventLoop *loop,int fd);
    ~Channel();
    /* 处理事件 */
    void handleEvent(Timestamp receiveTime);
    /* 设置回调操作 */
    void setReadCallback(ReadEventCallback cb) {
        readCallback_ = std::move(cb);
    }
    void setWriteCallback(EventCallback cb) {
        writeCallback_ = std::move(cb);
    }
    void setCloseCallback(EventCallback cb) {
        closeCallback_ = std::move(cb);
    }
    void setErrorCallback(EventCallback cb) {
        errorCallback_ = std::move(cb);
    }
    /* 防止当channel被手动remove掉，channel还在执行回调操作 */
    void tie(const std::shared_ptr<void>&);

    int fd() const {
        return fd_;
    }

    int events() const { return events_; }
    void set_revents(int revents) { revents_ = revents;}
    /* 设置fd 相应的事件状态 */
    void enableReading() {   
     /**
      * & 两个1 且为1
      * | 一个1 且为1
      * ^ 相同为0，不同为1
      * ~ 去反 0 为 1,1 为 0
      * << 左移 
      **/  

        /**
         * 0 |= 1  》》1 = 0 | 1
        */
        events_ |= kReadEvent; update(); 
    }
    void disableReading() {
        /*
            events_ = events & ~kReadEvent
            kReadEvent = 1110
            events_ =    0001
        */
        events_ &= ~kReadEvent; update();
    }
    void enableWriting() {
        events_ |= kWriteEvent; update();
    }
    void disableWriteing() {
        events_ &= ~kWriteEvent; update();
    }
    void disableAll() {
        events_ = kNoneEvent; update();
    }
    /* 检测epoll有没有感兴趣的事件 */
    bool isNoneEvent() const { return events_ == kNoneEvent; }
    /* 返回fd 当前的事件转态 */
    bool isWriting() const { return events_ & kWriteEvent;}
    bool isReading() const { return events_ & kReadEvent; }

    int index() { return index_;}

    void set_index(int index) { index_ = index; }
    /* one loop per thread */
    EventLoop* ownerLoop() { return loop_; }
    /* delete channel */
    void remove();

private:
    void update();
    /**/
    void handleEventWithGuard(Timestamp receiveTime);

    static const int kNoneEvent;    /* 没有对事件感兴趣 */
    static const int kReadEvent;    /* 对读事件感兴趣 */
    static const int kWriteEvent;   /* 对写事件感兴趣 */

    EventLoop* loop_ ;   /* 循环事件*/
    const int fd_ ;      /* fd poll监听的对象 */
    int events_ ;        /* 注册fd 感兴的事件 */
    int revents_ ;       /* 返回的具体发生的事件 */
    int index_;           
    /* weak_ptr 监视 shared_ptr 提升成功过访问，提升失败就不访问，就说明已经释放掉了 */
    std::weak_ptr<void> tie_; /* 防止手动调removeChannle */
    bool tied_;            /* 判断弱智能指针是否绑定 */
    bool eventHanding_;    /* assert 事件处理中*/
    bool addedToLoop_;     /* assert 跟新channel后才能~channel */

    /* 因为channel通道里面能够获取fd最终发生的具体事件revents,所以他负责调用具体事件的回调操作*/
    ReadEventCallback  readCallback_;    /* 读回调 */
    EventCallback writeCallback_;       /* 写回调 */
    EventCallback closeCallback_;       /*  关闭回调 */
    EventCallback errorCallback_;        /* 错误回调 */


};
}