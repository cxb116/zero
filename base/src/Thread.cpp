#include <base/Thread.h>
#include <base/CurrentThread.h>
#include <semaphore.h>
namespace zero {

static std::atomic_int numCreate_ = {0};
Thread::Thread(ThreadFunc func,const std::string& name) 
    :started_(false),
    joined_(false),
    tid_(0),
    func_(std::move(func)),
    name_(name)
{
    setDefaultName(); 
} 

Thread::~Thread() {
    if(started_ && !joined_) {
        /*将执行线程从线程对象中分离出来，允许独立地继续执行。一旦线程退出，
        任何分配的资源都将被释放。调用detach *后，this不再拥有任何线程。*/
        thread_->detach(); 
    }
}

void Thread::start() {
    started_ = true;
    sem_t sem;
    sem_init(&sem,false,0); /* 初始化为0，表示没信号获取 */
    thread_ = std::shared_ptr<std::thread>(new std::thread([&]() { /* 子线程 */
        tid_ = CurrentThread::tid();    /* 获取线程的tid */
        sem_post(&sem);                 /* post 给线程+1 */
        func_();  /* 这个线程专门执行改线程函数 */
    }));
    /* 这里必须等待获取上面新创建的线程tid值 */    
    sem_wait(&sem);
}

void Thread::join() {
    if(started_ && !joined_) {
        joined_ = true;
        thread_->join();
    }
}
/* 设置一个默认的名字 */
void Thread::setDefaultName() {
    int num = ++numCreate_;
    if(name_.empty()) {
        char buf[32] = {0};
        snprintf(buf,sizeof(buf), "thread%d",num);
        name_ = buf;
    }
};

}