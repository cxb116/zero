#pragma once
#include <net/TcpConnection.h>
#include <base/Timestamp.h>
#include <functional>
#include <memory>
namespace zero {

using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;

template <typename T>
inline T* get_pointer(const std::shared_ptr<T>& ptr) {
    return ptr.get();
}

template <typename T>
inline T* get_pointer(const std::unique_ptr<T>& ptr) {
    return ptr.get();
}

class Buffer;
class TcpConection;
using TcpConnectionPtr = std::shared_ptr<TcpConection>;
using TimerCallback = std::function<void()>;
using ConnectionCallback = std::function<void(const TcpConnectionPtr&)>;
using CloseCallback = std::function<void(const TcpConnectionPtr&)>;
using WriteCompleteCallback = std::function<void(const TcpConnectionPtr&)>;
/* 水位线 */
using HighWaterMarkCallback = std::function<void(const TcpConnectionPtr&)>;

using MessageCallback = std::function<void(const TcpConnectionPtr&,Buffer*,Timestamp)>;

void defaultConnectionCallback(const TcpConnectionPtr& conn);
void defaultMessageCallback(const TcpConnectionPtr& conn, Buffer* buffer,Timestamp receiveTime);

}