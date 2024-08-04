#pragma once 
#include <net/EventLoop.h>
#include <net/Channel.h>
#include <vector>
#include <functional>
#include <unordered_map>
namespace zero {

class Poller {
public:
    using ChannelList = std::vector<Channel*>;
    /* map 的key: sockfd, value: 所属的channel的通道类型 */
    using ChannelMap = std::unordered_map<int,Channel*>;

    Poller(EventLoop* loop);
    virtual ~Poller();
    virtual Timestamp poll(int timeoutMs,ChannelList* activeChannels) = 0;
    virtual void updateChannel(Channel* channel) = 0;
    virtual void removeChannel(Channel* channel) = 0;
    virtual bool hasChannel(Channel* channel) const;
    /* eventloop 可以通过该接口获取默认IO复用的具体实现 */
    static Poller* newDefauoltPoller(EventLoop* loop);

protected:
    ChannelMap channels_;
private:
    EventLoop* ownerLoop_;
};



}