#pragma once
#include <string.h>
#include <iosfwd>
#include <include/base/Types.h>

namespace zero
{
class StringArg {
private:
    const char* str_;
public:
    StringArg(const char* str) 
        :str_(str) {};
        
     StringArg(const std::string& str) 
        :str_(str.c_str()){
    }
};

class StringPiece {
private:
    const char* ptr_;
    int         length_;
public:
    StringPiece() 
        : ptr_(nullptr),length_(0) {}

    StringPiece(const char* str) 
        : ptr_(str),length_(static_cast<int>(strlen(ptr_))) {}

    StringPiece(const unsigned char* str) 
        : ptr_(reinterpret_cast<const char*>(str)),
        length_(static_cast<int>(strlen(ptr_))){}

    StringPiece(const std::string& str) 
        :ptr_(str.data()), length_(static_cast<int>(str.size())){}
    

    StringPiece(const char* offset,int len) 
        :ptr_(offset),length_(len) {}


    const char* data() const{ return ptr_;}
    int size() const { return length_;}
    bool empty() const { return length_ == 0; }
    const char* begin() const { return ptr_;}
    const char* end() const { return ptr_ + length_; }

    void clear() { ptr_ = NULL; length_ = 0; }
    void set(const char* buffer,int len){
        ptr_ = buffer; 
        length_ = len;}
    
    void set(const char* str) { ptr_ = str; length_ = static_cast<int>(strlen(str));}

    char operator[] (int i) const{ return ptr_[i];}

    void remove_prefix(int n) {
        ptr_ += n;
        length_ -= n;
    }

    void remove_suffix(int n) {
        length_ -= n;
    }

    bool operator==(const StringPiece& x) const {
        return ((length_ == x.length_) && (memcmp(ptr_,x.ptr_,length_)==0));
    }

    bool operator !=(const StringPiece& x) const {
        return !(*this == x);
    }


};

}