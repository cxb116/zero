#include <net/Poller.h>

namespace zero {
Poller ::Poller (EventLoop* loop) 
    :ownerLoop_(loop) {

    }

bool Poller::hasChannel(Channel* channel) const {
    auto item = channels_.find(channel->fd());
    return item != channels_.end() && item->second == channel;
}

Poller::~Poller() {
    
}


}