#include <net/EventLoop.h>
#include <net/EventLoopThreadPool.h>
#include <memory>
#include <iostream>
namespace zero
{
EventLoopThreadPoll::EventLoopThreadPoll(EventLoop* baseLoop,const std::string &nameArg) 
    : mainLoop_(baseLoop)
    , name_(nameArg) 
    , started_(false)
    , numThreads_(0)
    , next_(0) {

}
EventLoopThreadPoll::~EventLoopThreadPoll() {

}

void EventLoopThreadPoll::start(const ThreadInitCallback& cb) {
    started_ = true;
    /* numThreads_ 初始化为0 */
    for(int i = 0; i < numThreads_; ++i) {
        char buf[name_.size() + 32];
        snprintf(buf,sizeof(buf),"%s%d",name_.c_str(),i); 
        std::cout<<"buf: "<<buf<<"/n";
        EventLoopThread *t = new EventLoopThread(cb,buf);
        threads_.push_back(std::unique_ptr<EventLoopThread>(t)); /*new 出来这个对象，交给智能指针托管 */
        loops_.push_back(t->startLoop()); /*底层创先线程绑定一个新的Eventloop 并返回该loop地址*/
    }
    if(numThreads_ == 0 && cb) {
        cb(mainLoop_);
    }
}
/* mainLoop 默认以轮询的方式分配channel给subloop */
EventLoop* EventLoopThreadPoll::getNextLoop() {
    assert(started_);
    /* */
    EventLoop* loop = mainLoop_;
    if(!loops_.empty()) {
        loop = loops_[next_];
        ++next_;
        if(next_ >= loops_.size()) {
            next_ = 0;
        }
    }
    return loop;
}
/* 返回全部subloop 和 mainloop */
std::vector<EventLoop*> EventLoopThreadPoll::getAllLoops() {
    if(loops_.empty()) { /* 如果loops_ 为空*/
        return std::vector<EventLoop*>(1,mainLoop_);
    } else {
        return loops_;
    }
};

} // namespace zero