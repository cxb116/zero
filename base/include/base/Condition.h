#pragma once

#include <base/Mutex.h>
#include <pthread.h>

namespace zero {

class Condition {
public:
    explicit Condition(MutexLock& mutex): mutex_(mutex) {
        
    }

private:
    MutexLock mutex_;

}



}