#include <base/Atomic.h>
#include <base/Types.h>
#include <thread>
#include <functional>
#include <string>
#include <memory>
#include <unistd.h>
#include <atomic>

namespace zero { 
class Thread {
public:
    using ThreadFunc = std::function<void()>;
 
    explicit Thread(ThreadFunc func,const std::string &name = std::string());
    ~Thread();

    void start();
    void join();

    bool started() const { return started_; }
    pid_t tid() const { return tid_; }
    const std::string& name() const { return name_; }
    static int numCreated() { return numCreated_; }
private:
    void setDefaultName();
    bool started_;
    bool joined_;
    pid_t tid_;
    std::shared_ptr<std::thread> thread_;
    std::string name_;
    ThreadFunc func_;  /* 存储线程函数 */
    static std::atomic_int numCreated_;

};
}