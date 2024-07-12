#include "log.h"
namespace zero {
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
        std::cout<< m_formatter.format(event);
    }
}

FileLogAppender::FileLogAppender(const std::string& filename) {

}
void FileLogAppender::log(LogLevel::Level level,LogEvent::logEvent_ptr event) {

}

void FileLogAppender::reopen() {

}


}