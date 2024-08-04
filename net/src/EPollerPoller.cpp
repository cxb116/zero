#include <net/EPollPoller.h>
#include <assert.h>
#include <iostream>
#include <base/Timestamp.h>

namespace zero {
const int kNew = -1;   /* channel 的成员变量 index_ = -1  */
const int kAdded = 1;
const int kDelete = 2;
/**
 * 1 epoll_create 在EPollerPoller()初始化中完成
**/
EPollerPoller::EPollerPoller(EventLoop* loop) 
        : Poller(loop)
        , epollfd_(::epoll_create(EPOLL_CLOEXEC)) 
        , events_(kInitEventListSize) {
            if(epollfd_ < 0) {
                assert(epollfd_ > 0); 
                printf("epoll create failed \n");
            }  
        }

EPollerPoller::~EPollerPoller() { 
    ::close(epollfd_);
}
/* epoll_wait  timeoutMs epoll_wait 的超时时间 */ 
Timestamp EPollerPoller::poll(int timeoutMs,ChannelList* activeChannels) {
    int numEvents = ::epoll_wait(epollfd_, &*events_.begin(), static_cast<int>(events_.size()),timeoutMs);
    int saveErrno = errno;
    Timestamp now(Timestamp::now());
    /* 有事件 */
    if(numEvents > 0) {
        std::cout<<"numEvents: "<< numEvents <<"\n";
        fillActiveChannels(numEvents,activeChannels);
        if(numEvents == events_.size()) {       /* 如果numEvents的数量等于events_size() 就要进行扩容了 */
            events_.reserve(events_.size() * 2);
        }
    /* epoll_wait 超时 */
    } else if (numEvents == 0) {
        std::cout <<"epoll_wait: timeout !\n";
    }
    /* epoll_wait 有错误 */
    else {
        if(saveErrno != EINTR) {
            std::cout<<"epoll_wait failed\n";
        }
    }
    return now; 
}

void EPollerPoller::fillActiveChannels(int numEvents,ChannelList* activeChannels) const {
    assert(numEvents <= events_.size());
    for(int i = 0; i < numEvents; ++i) {
        Channel* channel = static_cast<Channel*>(events_[i].data.ptr);
        channel->set_revents(events_[i].events);
        activeChannels->emplace_back(channel);
    } 
}

/**
 * 2 epoll_ctl 在添加channel中的读写事件  add/mod/del 
**/
/* 跟新channels_,让传入的channel,看他是新的事件，还是读事件，写事件 */
void EPollerPoller::updateChannel(Channel* channel) {
    const int index = channel->index();
    if(index == kNew || index == kDelete) {
        int fd = channel->fd();
        if(index == kNew) {           /* 有新的事件 */
            channels_[fd] = channel; 
        } else {
            assert(channels_.find(fd) != channels_.end());
            assert(channels_[fd] == channel);
        }
        channel->set_index(kAdded);   /* index_ setting kAdded */
        update(EPOLL_CTL_ADD,channel);
    }else { /* update existing one with EPOLL_CTL_MOD/DEL */
            int fd = channel->fd();
            // (void) fd;
        /* assert(channels_.find(fd) != cahnnels_.end()); */
            assert(index == kAdded);    /* 保证已经在channels_ 中添加了这个事件 */
            assert(channels_[fd] == channel);
            assert(channels_.find(fd) != channels_.end());
            if(channel->isNoneEvent()) {   /* 检测events == 0 是不是成立 */
                update(EPOLL_CTL_DEL,channel);
                channel->set_index(kDelete);
            } else {  
                update(EPOLL_CTL_MOD,channel);
            }
    }
}
/* 要移除首先要判断他存在于map */
void EPollerPoller::removeChannel(Channel* channel) {
    int fd = channel->fd();
    assert(channels_.find(fd) != channels_.end());
    assert(channels_[fd] == channel);
    assert(channel->isNoneEvent());
    int index = channel->index();
    assert(index == kAdded || index== kDelete);
    size_t n = channels_.erase(fd);       /* 在map中删 */
    assert(n == 1);

    if(index == kAdded) {
        update(EPOLL_CTL_DEL, channel);
    }
    channel->set_index(kNew);
}

/* epoll_ctl的具体操作 */
void EPollerPoller::update(int operation, Channel* channel) {
    struct epoll_event event;
    memset(&event,0,sizeof(event));
    int fd = channel->fd();
    event.events = channel->events(); 
    event.data.ptr = channel;
    event.data.fd = fd;
    
    if(::epoll_ctl(epollfd_, operation, fd, &event) < 0) {
        if(operation == EPOLL_CTL_DEL) {
            printf("EPollerPoller::update epoll_ctl() failed\n");
        }
    } 
}

}