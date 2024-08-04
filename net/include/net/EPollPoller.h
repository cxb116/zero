#pragma once
#include <net/Poller.h>
#include <vector>
#include <sys/epoll.h>
#include <assert.h>
#include <base/Timestamp.h>

namespace zero {
class Channel;

class EPollerPoller : public Poller {
public:
    using EventList = std::vector<epoll_event>;
    EPollerPoller(EventLoop* loop);
    virtual ~EPollerPoller() override; 

    Timestamp poll(int timeoutMs,ChannelList* activeChannels) override ;
    void updateChannel(Channel* channel) override;
    void removeChannel(Channel* channel) override;
private:
    static const int kInitEventListSize = 20;   /* vector 初始化长度 */
    void fillActiveChannels(int numEvents,ChannelList* activeChannel) const;   /* 填写活跃的channel */
    void update(int operation, Channel* channel);    /* 跟新update 通道 */
   
    int epollfd_;

    EventList events_;                          /** 事件总和 **/
};
}