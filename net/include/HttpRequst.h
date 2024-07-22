#pragma once
#include "zero/base/include/copyable.h"
#include "zero/base/include/Timestamp.h"
#include "zero/base/include/Types.h"

#include <map>
#include <assert.h>
#include <stdio.h>

namespace zero 
{
namespace net {
class HttpRequest : public zero::copyable {
public:
    enum Method
    {
        kInvalid, kGet, kPost, kHead, kPut, kDelete
    };
    enum Version 
    {
        kUnknown, kHttp10, kHttp11
    };
    HttpRequest() 
        : method_(kInvalid),
          version_(kUnknown) {

          }
    void setVersion(Version ver) {
        version_ = ver;
    }

    Version getVersion() const {
        return version_;
    }
/* method_ != kInvalid */
    bool setMethod(const char* start, const char* end) {
        assert(method_ == kInvalid);
        std::string m(start,end);
        if(m == "GET") {
            method_ = kGet;
        }else if(m == "POST") {
            method_ = kPost;
        }else if(m == "HEAD") {
            method_ = kHead;
        }else if(m == "PUT") {
            method_ = kPut;
        }else if(m == "DELETE") {
            method_ = kDelete;
        }else {
            method_ = kInvalid;
        }
        return method_ != kInvalid;
    }
Method method() const {
    return method_;
}

const char* methodString() const {
    const char* result = "UNKNOWN";
    switch(method_)
    {
        case kGet:
            result = "GET";
            break;
        case kPost:
            result = "POST";
            break;
        case kHead:
            result = "HEAD";
            break;
        case kDelete:
            result = "DELETE";;
            break;
        default:
            break;
    }
    return result;
}

    void setPath(const char* start,const char* end) {
        path_.assign(start,end);
    }

    const std::string& path() const {
        return path_;
    }

    void setQuery(const char* start,const char* end) {
        query_.assign(start,end);
    }


private:
    Method method_;
    Version version_;
    std::string path_;
    std::string query_;
    Timestamp receiveTime_;
    std::map<std::string,std::string> headers_;
};

}

}