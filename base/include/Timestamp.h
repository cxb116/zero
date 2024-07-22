#pragma once 
#include "Types.h"
#include "copyable.h"
#include <string>
#include <boost/operators.hpp>

namespace zero {

class Timestamp : public zero::copyable,
                  public boost::equality_comparable1<Timestamp>,
                  public boost::less_than_comparable<Timestamp>
{
public: 
    Timestamp()
        : microSecondsSinceEpoch_(0) {

    } 

explicit Timestamp(int64_t microSecondsSinceEpochArg) 
        : microSecondsSinceEpoch_(microSecondsSinceEpochArg) 
{

}
void swap(Timestamp& that) {
    std::swap(microSecondsSinceEpoch_,that.microSecondsSinceEpoch_);
}

std::string toString() const;

std::string toFormattedString(bool showMicroseconds = true) const;
/* 有效的时间戳 */
bool valid() const{ return microSecondsSinceEpoch_>0; }

int64_t microSecondsSinceEpoch() const { return microSecondsSinceEpoch_;}

time_t microSecondsSinceEpoch() const {
    return static_cast<time_t>(microSecondsSinceEpoch_/KMicroSecondsPerSecond);
}
static Timestamp now();
static Timestamp invalid() {
    return Timestamp();
}

static Timestamp fromUnixTime(time_t t) {
    return fromUnixTime(t,0);
}

static Timestamp fromUnixTime(time_t t,int microseconds) {
    return Timestamp(static_cast<int16_t>(t)* KMicroSecondsPerSecond + microseconds);
}
static const int KMicroSecondsPerSecond = 1000 * 1000;
private:
    int64_t microSecondsSinceEpoch_;    
};

inline bool operator<(Timestamp lhs,Timestamp rhs) {
    return lhs.microSecondsSinceEpoch() < rhs.microSecondsSinceEpoch();
}

inline bool operator==(Timestamp lhs,Timestamp rhs) {
 return lhs.microSecondsSinceEpoch()== rhs.microSecondsSinceEpoch();
}

inline double timeDifference(Timestamp high,Timestamp low) {
    int64_t diff = high.microSecondsSinceEpoch() - low.microSecondsSinceEpoch();
    return static_cast<double>(diff) / Timestamp::KMicroSecondsPerSecond;
}

inline Timestamp addTime(Timestamp timestamp,double seconds) {
    int64_t delta = static_cast<int64_t>(seconds * Timestamp::KMicroSecondsPerSecond);
    return Timestamp(timestamp.microSecondsSinceEpoch() + delta);
}

}