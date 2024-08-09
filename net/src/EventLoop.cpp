#include <net/EventLoop.h>
#include <functional>
#include <sys/eventfd.h>
#include <fcntl.h>
#include <unistd.h>
#include <net/Poller.h>
#include <net/EPollPoller.h>
#include <net/Channel.h>
#include <mutex>
namespace zero {
     /* 防止一个线程创建多个EventLoop thread_local */
    __thread EventLoop* t_loopInThisThread = nullptr;
    /* 定义默认的Poller IO 复用的超时时间 */
    const int kEpollTimeMs = 10000;
    /* 创建wakeupfd, 用来notify唤醒subReactor处理新来的channel  */
    int createEventfd() {
        int eventfd =::eventfd(0,EFD_NONBLOCK | EFD_CLOEXEC);
        if(eventfd < 0) {
            printf("eventfd in failed \n");
        }
        return eventfd;
    } 

EventLoop::EventLoop() 
    : looping_(false)
    , quit_(false)
    , callingPendingFunctions_(false)
    , threadId_(CurrentThread::tid())
    , Poller_ptr_(Poller::newDefauoltPoller(this))
    , wakeupFd_(createEventfd())
    , wakeupChannel_(new Channel(this, wakeupFd_))  /* 初始化wakeupFd_ 但没有事件*/
    , currentActiveChannel_ (nullptr) {
        printf("EventLoop::EventLoop() create in thread ");
        if(t_loopInThisThread) {
            printf("t_loopInThisThread not nullptr \n");
         } else {
            t_loopInThisThread = this;
        }
        /* 设置wakeup的事件类型以及发生事件后的回调操作 （唤醒poll subReater ）*/
        /* wakeupfd 发送数据触发 subReator*/
        wakeupChannel_->setReadCallback(std::bind(&EventLoop::handleRead,this));
        /* 每一个eventloop 都将监听wakeupchannel的EPOLLIN读事件 */
        wakeupChannel_->enableReading();
}

 
EventLoop::~EventLoop() {
        /* 对所有的事件都不感兴趣 */
        wakeupChannel_->disableAll();
        wakeupChannel_->remove();
        ::close(wakeupFd_);
        t_loopInThisThread = nullptr;
}

void EventLoop::loop() {
        looping_ = true;
        quit_ = false;

        printf("EventLoop start loop \n");
        while(!quit_) {
            activeChannels_.clear();
            /* 触发 epoll_wait  subloop 
        将epollfd 中所有的channel 拿出来，放入activeChannels_ 中
             */
            pollReturnTime_ = Poller_ptr_->poll(kEpollTimeMs,&activeChannels_);

            eventHandling_ = true;
            for(Channel* channel : activeChannels_) {
                currentActiveChannel_ = channel; 
                /* 当前activeChannel_ 设置为EPOLLIN或者EPOLLOUT */
                currentActiveChannel_ ->handleEvent(pollReturnTime_);
            }
            currentActiveChannel_ = nullptr;
            eventHandling_ = false;
            /* 执行当前eventLoop 事件循环需要处理的回调操作
              IO 线程 mainLoop accept fd <<= channel subloop
              mainLoop 事件先注册一个回调cb,需要subloop来执行
              wakeup subloop后，执行下面的方法，执行之前，执行mainloop
              注册的cb  
            */
    /*queueloop -> runInloop 当前执行的loop中的执行cb  */       
            doPendingFunctions();
    }
}
/* 回调 */
void EventLoop::doPendingFunctions() {
     std::vector <Function> functions;
     callingPendingFunctions_ = true;

     {
        std::unique_lock<std::mutex> lock(mutex_);
        functions.swap(pendingFunctions_);    
     }
     for(const Function& function: functions) {
        function();
     }
     callingPendingFunctions_ = false;
}

// 退出事件循环， 1 loop在自己的线程中调用quit
/*有可能loop()只是执行while(!quit_)并退出，
如果EventLoop被破坏，那么我们正在访问一个无效的对象。
可以在两个位置使用mutex_来修复。*/
void EventLoop::quit() {
    quit_ = true;
    if(!isInLoopThread()) {   /* 如果是在其他线程中调用 quit，比如实在subloop中，
        调用了mainLoop的quit */
        weakup();
    }
}

    /* 在当前loop中执行cb */
void EventLoop::runInLoop(Function cb) {
    if(isInLoopThread()) {
        cb(); 
    } else {
        queueInLoop(std::move(cb));
    }
}

/* 把cb放入队列中，唤醒loop所在的线程执行cb */
void EventLoop::queueInLoop(Function cb) {
    {
        std::unique_lock<std::mutex> lock(mutex_);
        pendingFunctions_.emplace_back(cb);
    }

    if(!isInLoopThread() || callingPendingFunctions_) {
        weakup();
    } 
}
/* 用来唤醒loop 所在的线程的， 向weakupfd_ 发送一个数据，
    wakeupChannel 就发生读事件，当前loop线程程就会被唤醒 */
void EventLoop::weakup() {
    uint64_t one = 1;
    /* write 写入文件描述符 然后才能读出来*/
    ssize_t n = ::write(wakeupFd_ ,&one,sizeof(one));
    if(n != sizeof(one)) {
        printf("EventLoop::wakeup() writes data \n");
    }
}
/* 读出wakeupFd 中的数据 */
void EventLoop::handleRead() {
    uint64_t one = 1;
    ssize_t n = read(wakeupFd_, &one,sizeof(one));
    if(n != sizeof(one)) {
        printf("EventLoop::handleRead() read data != 8 \n");
    }
} 

/* */
void EventLoop::updateChannel(Channel* channel) {
    assert(channel->ownerLoop() == this);
    Poller_ptr_->updateChannel(channel);
}
void EventLoop::removeChannel(Channel* channel) {
    assert(channel->ownerLoop() == this) ;
    if(eventHandling_) {
        
    }
    Poller_ptr_->removeChannel(channel);
}
bool EventLoop::hasChannel(Channel* channel) {
    
    return Poller_ptr_->hasChannel(channel);
}
}