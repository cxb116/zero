#pragma once

#include <stdint.h>
#include <string.h>
#include <string>
#include <assert.h>

namespace zero {
inline void zZero(void *p,size_t n) {
    memset(p,0,n);
}

/* 隐式迭代*/
/*
implicit_cast 函数的作用是进行隐式类型转换。在 C++ 中，
编译器会自动执行某些类型转换，例如从较小的整数类型到较大的整数类型，
或者从子类指针向父类指针的隐式转换。这个函数利用了模板的特性，
使得在编译时可以根据需要进行类型转换，而不必显式地指定转换函数或者类型转换操作符。
template<typename To, typename From>：这是一个模板函数的声明，
使用了两个模板参数 To 和 From。To 表示目标类型，From 表示源类型。

*/
// template<typename To,typename From>
// inline To implicit_cast(From const &f) {
//     return f;
// }

// template<typename To, typename From>     // use like this: down_cast<T*>(foo);
// inline To down_cast(From* f)                     // so we only accept pointers
// {
//   // Ensures that To is a sub-type of From *.  This test is here only
//   // for compile-time type checking, and has no overhead in an
//   // optimized build at run-time, as it will be optimized away
//   // completely.
//   if (false)
//   {
//     implicit_cast<From*, To>(0);
//   }

// #if !defined(NDEBUG) && !defined(GOOGLE_PROTOBUF_NO_RTTI)
//   assert(f == NULL || dynamic_cast<To>(f) != NULL);  // RTTI: debug mode only!
// #endif
//   return static_cast<To>(f);
// }

}