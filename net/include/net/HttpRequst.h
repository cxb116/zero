#pragma once
#include <base/copyable.h>
#include <base/Timestamp.h>
#include <base/Types.h>

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

    const std::string& query() const {
        return query_;
    }

    void setReceiveTime(Timestamp t) {
        receiveTime_  = t;
    }

    Timestamp receiveTime() const {
        return receiveTime_;
    }
    /* request header spliter */
    void addHeader(const char* start,const char* colon, const char* end) {
        std::string field(start,colon);
        ++colon;
        while(colon < end && isspace(*colon)) {
            ++colon;
        }
        std::string value(colon,end);
        while(!value.empty() && isspace(value[value.size()-1])) {
            value.resize(value.size()-1);
        }
        headers_[field] = value;
    }
    /* 根据 header key return value*/
    std::string getHeader(const std::string& field) const{
        std::string result;
        std::map<std::string,std::string>::const_iterator it = headers_.find(field);
        if(it !=headers_.end()) {
            result = it->second;
        }
        return result;
    }

    const std::map<std::string,std::string>& headers() const {
        return headers_;
    }

    void swap(HttpRequest& that) {
        std::swap(method_,that.method_);
        std::swap(version_,that.version_);
        path_.swap(that.path_);
        query_.swap(that.query_);
        receiveTime_.swap(that.receiveTime_);
        headers_.swap(that.headers_);
    }


private:
    Method method_;
    Version version_;
    std::string path_;
    std::string query_;                     
    Timestamp receiveTime_;             /* request time */
    std::map<std::string,std::string> headers_;
};

}

}