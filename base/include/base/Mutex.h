#pragma once
#include <base/CurrentThread.h>
#include <base/copyable.h>
#include <assert.h>
#include <pthread.h>

namespace zero {
class MutexLock  {
public:
    MutexLock() :holder_(0) {
        pthread_mutex_init(&mutex_, NULL);
    }

    ~MutexLock() {
        assert(holder_ == 0);
        pthread_mutex_destroy(&mutex_);
    }

    bool isLockedByThisThread() const {
        return holder_ == CurrentThread::tid();
    }

    void lock() {
        pthread_mutex_lock(&mutex_);
        assignHolder(); /* 获取真实的线程tid*/
    }
    void unlock() {
        unassignHolder();
        pthread_mutex_unlock(&mutex_);
    }

    pthread_mutex_t* getPthreadMutex() {
        return &mutex_;
    }

private:
    friend class condition;
    class UnassignGuard {
    public:
        explicit UnassignGuard(MutexLock& owner) : owner_(owner) {
            owner_.unassignHolder();
        }
    private:
        MutexLock& owner_;

    };
    void unassignHolder() {
        holder_ = 0;
    }

    void assignHolder() {
        holder_ = CurrentThread::tid();
    }

    pthread_mutex_t mutex_;
    pid_t holder_;
};

class MutexLockGuard {
public:
    explicit MutexLockGuard(MutexLock& mutex) :mutex_(mutex) {
        mutex_.lock();
    }
    ~MutexLockGuard() {
        mutex_.unlock();
    }

private:
    MutexLock& mutex_;
};

}