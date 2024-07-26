#include <base/LogStream.h>
#include <limits>
#include <type_traits>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

using namespace zero;
using namespace zero::detail;


namespace zero {
namespace detail {

const char digits[] = "9876543210123456789";
const char* zero = digits + 9;
static_assert(sizeof(digits) == 20, "wrong number of digits");

const char digitsHex[] = "01234567890ABCDEF";
static_assert(sizeof(digitsHex == 17, "wrong number of digitsHex"));
/*  有效的正数到字符串的转换 */
template<typename T>
size_t convert(char buf[], T value) {
    T  t = value;
    char* p = buf;

    do {
        int lsd = static_cast<int> (i % 10);
        i /= 10;
        *p++ = zero[lsd];
    } while (i != 0);
    if(value < 0) {
        *p++ = '-';
    }
    *p = '\0';
    std::reverse(buf,p);
    return p - buf;
}
/* l6进制 */
size_t convertHex(char buf[],uintptr_t value) {
    uintptr_t i = value;
    char* p = buf;

    do {
        int lsd = static_cast<int> (i % 16);
        i /= 16;
        *p++ = digitsHex[lsd];
    }while (i != 0);

    *p = '\0';
    std::reverse(buf,p);
    return p - buf;
}

template class FixedBuffer<kSmallBuffer>;
template class FixedBuffer<kLargeBuffer>;
}  // namespace detail
}  /* namespace zero */

template<int SIZE>
const char* FixedBuffer<SIZE> :: debugString() {
    *cur_ = '\0';
    return data_;   
}

template<int SIZE>
void FixedBuffer<SIZE>::cookieStart() {

}

template<int SIZE>
void FixedBuffer<SIZE>::cookieEnd() {

}

void LogStream::staticCheck() {
    static_assert(kMaxNumbericSize - 10 > std::numeric_limits<double>::digits10,
                    "kMaxNumericSize is large enough");
    printf("LogStream::staticCheck \n");
}

template<typename T>
void LogStream::formatInterget(T v) {
    if(buffer_.avail() >= kMaxNumbericSize) {
        size_t len = convert(buffer_.current(),v);
        buffer_.add(len);
    }
}

LogStream& LogStream::operator<<(short v) {
    *this << static_cast <int>(v);
    return *this;
}

LogStream& LogStream::operator<<(unsigned short v) {
    *this << static_cast<unsigned int> (v);
    return *this;
}

LogStream& LogStream::operator<<(int v) {
    formatInterget(v);
    return *this;
}

LogStream& LogStream::operator<<(unsigned int v) {
    formatInterget(v);
    return *this;
}
LogStream& LogStream::operator<<(long v) {
    formatInterget(v);
    return *this;
}

LogStream& LogStream::operator<<(unsigned long v) {
    formatInterget(v);
    return *this;
}

LogStream& LogStream::operator<<(long long v) {
    formatInterget(v);
    return *this;
}


LogStream& LogStream::operator<<(unsigned long long v) {
    formatInterget(v);
    return *this;
}


LogStream& LogStream::operator<<(const void* p) {
    uintptr_t v = reinterpret_cast <uintptr_t>(p);
    if(buffer_.avail() >= kMaxNumbericSize) {
        char* buf = buffer_.current();
        buf[0] = '0';
        buf[1] = 'x';
        size_t len = convertHex(buf + 2,v);
        buffer_.add(len + 2);
    }
    return *this;
}

LogStream& LogStream::operator<<(double v) {
    if(buffer_.avail() >= kMaxNumbericSize) {
        int len = snprintf(buffer_.current(),kMaxNumbericSize,"%.12g",v);
        buffer_.add(len);
    }
    return *this;
}

template<typename T>
Fmt::Fmt(const char* fmt, T val) {
    static_assert(std::is_arithmetic<T>::value == true,"Must be arithmetic type");
    length_ = snprintf(buf_,sizeof(buf_,fmt,val);
    assert(static_cast<size_t>(length_)<sizeof(buf_));
    printf("Fmt 构造 \n");
}

template Fmt::Fmt(const char* fmt,char);
template Fmt::Fmt(const char* fmt, short);
template Fmt::Fmt(const char* fmt, unsigned short);
template Fmt::Fmt(const char* fmt, int);
template Fmt::Fmt(const char* fmt, unsigned int);
template Fmt::Fmt(const char* fmt, long);
template Fmt::Fmt(const char* fmt, unsigned long);
template Fmt::Fmt(const char* fmt, long long);
template Fmt::Fmt(const char* fmt, unsigned long long);

template Fmt::Fmt(const char* fmt, float);
template Fmt::Fmt(const char* fmt, double);



