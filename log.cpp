#include "log.h"
namespace zero {
//         UNKNOW = 0,
//         DEBUG = 1,
//         INFO  = 2,
//         WARN  = 3,
//         ERROR = 4,
//         FATAL = 5
static const char* ToString(LogLevel::Level level) {
    switch(level) {
#define XX(name) \
    case LogLevel::name: \
        return #name; \
        break;
    XX(UNKNOW);
    XX(DEBUG);
    XX(INFO);
    XX(WARN);
    XX(ERROR);
    XX(FATAL);
#undef XX
    default:
        return "UNKNOW"
    }
}


 Logger::Logger(const std::string& name)
    :m_name(name) {

 };
/* level 日志等级; event 日志事件 */
void Logger::log(LogLevel::Level level,LogEvent::logEvent_ptr event) {
    if(level >= m_level) {
        for(auto& item : m_appender_lists) {
            item->log(level,event);
        }
    }
}
void Logger::debug(LogEvent::logEvent_ptr event) { 
    log(LogLevel::DEBUG,event);
}
void Logger::info(LogEvent::logEvent_ptr event) {
    log(LogLevel::INFO,event);
}
void Logger::warn(LogEvent::logEvent_ptr event) {
    log(LogLevel::WARN,event);
}
void Logger::error(LogEvent::logEvent_ptr event) { 
    log(LogLevel::ERROR,event);
}
void Logger::fatal(LogEvent::logEvent_ptr event) {
    log(LogLevel::FATAL,event);
}

void Logger::addAppender(LogAppender::logAppender_ptr appender) {
    m_appender_lists.push_back(appender);
}

void Logger::delAppender(LogAppender::logAppender_ptr appender) {
    for(auto it = m_appender_lists.begin();it != m_appender_lists.end(); ++it) {
        if(*it == appender) {
            m_appender_lists.erase(it);
            break;
        }
    }
}

void StdoutLogAppender::log(LogLevel::Level level,LogEvent::logEvent_ptr event) {
    if(level >= m_level) {
        std::cout<< m_formatter->format(level,event);
    }
}

FileLogAppender::FileLogAppender(const std::string& filename)
    :m_filename(filename) {

}
void FileLogAppender::log(LogLevel::Level level,LogEvent::logEvent_ptr event) {
    if(level >= m_level) {
        m_filestream << m_formatter->format(level,event);
    }
}

bool FileLogAppender::reopen() {
    if(m_filestream) {
        m_filestream.close();
    }
    m_filestream.open(m_filename);
    return !!m_filestream; /* 非0值为ture,-400为true,!(-400)为false 双重否定定于肯定 */
}

/************************************************** 日志格式 *********************************************************/
LogFormatter::LogFormatter(const std::string& pattern) 
    :m_pattern(pattern) {

}

std::string LogFormatter::format(LogLevel::Level level, LogEvent::logEvent_ptr event) {
    std::stringstream ss;
    for(auto& item : m_formatItems) {
        item->format(ss,level,event);
    }
    return ss.str();
}


void LogFormatter::init() {
    /* str , format type */
    std::vector<std::tuple<std::string,std::string,int>> vec;
    std::string nstr;
    for(size_t i = 0; i < m_pattern.size(); ++i) {
        if(m_pattern[i] == '%') {
            nstr.append(1,m_pattern[i]);
            continue;
        }
        if((i +1) < m_pattern.size()) {
            if(m_pattern[i + 1] == '%') {
                nstr.append(1,'%');
                continue;
            }
        }
        size_t n = i + 1;
        int fmt_status = 0;
        int fmt_begin = 0;

        std::string str;
        std::string fmt;
        while (++n < m_pattern.size()){
            if(isspace(m_pattern[n])) {
                break;
            }
            if(fmt_status == 0) {
                if(m_pattern[n] = '{') {
                    str = m_pattern.substr(i + 1,n - i);
                    fmt_status = 1;             /* 解析格式 */
                    ++n;                 
                    fmt_begin = n;
                    continue;
                }
            }
            if(fmt_status == 1) {
                if(m_pattern[n] == '}') {
                    fmt = m_pattern.substr(fmt_begin + 1,n - fmt_begin - 1);
                    fmt_status = 2;
            
                    continue; 
                }
            }
        }
        if(fmt_status == 0) {
            if(!nstr.empty()) {
                vec.push_back(std::make_tuple(nstr,"",0));
            }
            str = m_pattern.substr(i + 1,n - i-1);
            vec.push_back(std::make_tuple(str,fmt,1));
        } else if(fmt_status == 1) {
            std::cout<<"pattern pares error: "<<m_pattern <<" - "<<m_pattern.substr(i)<<"\n";
            vec.push_back(std::make_tuple("<<pattern_error>>",fmt,1));
        } else if(fmt_status == 2) {
            vec.push_back(std::make_tuple(str,fmt,1));
            i = n;
        }
    }

    if(!nstr.empty()) {
        vec.push_back(std::make_tuple(nstr,"",0));
    }
    /*
    日志格式举例：%d{%Y-%m-%d %H:%M:%S}%T%t%T%N%T%F%T[%p]%T[%c]%T%f:%l%T%m%n
    格式解析：
    %d{%Y-%m-%d %H:%M:%S} : %d 标识输出的是时间 {%Y-%m-%d %H:%M:%S}为时间格式，可选 DateTimeFormatItem
    %T : Tab[\t]            TabFormatItem
    %t : 线程id             ThreadIdFormatItem
    %N : 线程名称           ThreadNameFormatItem
    %F : 协程id             FiberIdFormatItem
    %p : 日志级别           LevelFormatItem       
    %c : 日志名称           NameFormatItem
    %f : 文件名             FilenameFormatItem
    %l : 行号               LineFormatItem
    %m : 日志内容           MessageFormatItem
    %n : 换行符[\r\n]       NewLineFormatItem
    */

}
class MessageFormatItem : public LogFormatter::FormatItem {
public:
    void format(std::ostream& os,LogLevel::Level level, LogEvent::logEvent_ptr event) override {
        os<< event->getContent();
    }
};

class LevelFormatItem : public LogFormatter::FormatItem {
public:
    void format(std::ostream& os,LogLevel::Level level,LogEvent::logEvent_ptr event) override {
        os<<LogLevel::ToString(level);
    }
};

class ElapseFormatItem : public LogFormatter::FormatItem {
public:
    void format(std::ostream& os,LogLevel::Level level,LogEvent::logEvent_ptr event) override {
        os<<event->getElapse();
    }

}

//   const char* m_file = nullptr;  /* 文件名 */
//     int32_t m_line = 0;            /* 行号 */
//     uint32_t m_threadId = 0;       /* 线程id */
//     uint32_t m_fiberId = 0;        /* 协程id*/
//     uint64_t m_time;               /* 时间戳*/
//     uint32_t m_elapse = 0;           /* 程序启动开始到现在的毫秒数*/
//     std::string m_content;    

}