#include <iostream>
#include <net/Channel.h>
#include <net/EventLoop.h>
#include <sstream>
#include <sys/epoll.h>
#include <assert.h>

using namespace zero;
const int Channel::kNoneEvent = 0;
const int Channel::kReadEvent = EPOLLIN | EPOLLPRI;
const int Channel::kWriteEvent = EPOLLOUT;

Channel::Channel(EventLoop* loop,int fd)
    : loop_(loop)
    , fd_(fd)
    , events_(0)
    , revents_(0)
    , index_(-1) 
    , tied_(false)
    , eventHanding_(false) 
    , addedToLoop_(false) {

    }

Channel::~Channel() {
    /* 断言事件发生了*/
    assert(eventHanding_);
    /* 跟新update 以后才能析构channel */
    assert(addedToLoop_); 
    /* 当前这个loop 是否在当前的线程中析构 */
    if(loop_->isInLoopThread()) {
        assert(!loop_->hasChannel(this));
    }
}

void Channel::tie(const std::shared_ptr<void>& obj) {
    /* weak_ptr 弱指针 */
    tie_ = obj;
    tied_ = true;
}
/* 当channel所表示fd的events事件后，update 负责poller里面更爱fd相应的事件epoll_ctl */
void Channel::update() {
    addedToLoop_ = true;
    loop_->updateChannel(this); 
}
 
/* 在channel 所属的eveltLoop中,把当前的channel删除掉 */
void Channel::remove() {
   assert(isNoneEvent());
   addedToLoop_ = false;
   loop_->removeChannel(this);
}
/* fd 得到poller 通知以后,处理事件 */
void Channel::handleEvent(Timestamp receiveTime) {
    std::shared_ptr<void> shared;
    if(tied_) {
        shared = tie_.lock();
        if(shared) {
            handleEventWithGuard(receiveTime);
        }
    } else {
        handleEventWithGuard(receiveTime);
    }
}

void Channel::handleEventWithGuard(Timestamp receiveTime) {
    eventHanding_ = true;
    /*  EPOLLHUP fd 挂断 */
    if((revents_ & EPOLLHUP) && !(revents_ & EPOLLIN)) {
        if(closeCallback_) {
            closeCallback_();
        }
    }
    /* 发生错误 */
    if(revents_ & EPOLLERR) {
        if(errorCallback_) errorCallback_();
    }
    /* 发生了读事件 */
    if(revents_ & (EPOLLIN | EPOLLPRI | EPOLLRDHUP)) {
        if(readCallback_) {
            readCallback_(receiveTime);
        }
    } 
    /* 发生了读事件 */
    if(revents_ & EPOLLOUT) {
        if(writeCallback_) {
            writeCallback_();
        }
    }
}