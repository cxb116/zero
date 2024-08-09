#include <net/EventLoopThread.h>
#include <stdint.h>
#include <string>

namespace zero {

EventLoopThread::EventLoopThread(const ThreadInitCallback& cb,const std::string& name )
        : loop_(nullptr)
        , exiting_(false)
        , thread_(std::bind(&EventLoopThread::threadFunc,this),name)
        , mutex_()
        , cond_()
        , callback_(cb){

        }

 EventLoopThread::~EventLoopThread(){
        exiting_ = true;
        if(loop_ !=nullptr) {
            loop_->quit();
            thread_.join();
        }
 }

EventLoop* EventLoopThread::startLoop(){
    thread_.start();   /* 启动线程 */
    EventLoop* loop = nullptr;
    {
        std::unique_lock<std::mutex> lock(mutex_);
        while(loop_== nullptr) {
            cond_.wait(lock); /* if looo_ == nullptr,就一直等待在这把互斥锁上*/
        }
        loop = loop_;
    }
    return loop;
}
/* 在新线程中单独执行 */
void EventLoopThread::threadFunc(){
    EventLoop loop; /* 创建一个独立的eventloop,和上面的线程事一一对应的 */
    if(callback_) {
        callback_(&loop);
    }

    {
        std::unique_lock<std::mutex> lock(mutex_);
        loop_ = &loop;
        cond_.notify_one();
    }
    loop.loop(); /* eventLoop loop==> poller.poll */
    /* loop 循环停止了 */
    {
    std::unique_lock<std::mutex> lock(mutex_);
    loop_ = nullptr;
    }
}

}