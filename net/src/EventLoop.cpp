#include <net/EventLoop.h>
#include <functional>

namespace zero {

    /* 在当前loop中执行cb */
    void EventLoop::runInLoop(Function cb){

    }
    /* 把cb放入队列中，唤醒loop所在的线程执行cb */
    void EventLoop::queueInLoop(Function cb){

    }
    /* 用来唤醒loop 所在的线程 */
    void EventLoop::weakup(){

    }
    /* */
    void EventLoop::updateChannel(Channel* channel){

    }
    void EventLoop::removeChannel(Channel* channel) {

    }
    bool EventLoop::hasChannel(Channel* channel){
        return true;
    }




}