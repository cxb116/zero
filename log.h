#ifndef __LOG_H__
#define __LOG_H__
/*********************************************************************************************************************************************************************************************************************
* 将日志抽象成Logger（日志器），LogAppender（输出落地点），LogFormat（日志格式器）三大模块。
* Logger，对外使用的类，输入的日志级别大于等于Logger的日志，才会被真正写入。可以有多个Logger，不同的logger，记录不同类型的日志，比如将系统框架日志和业务逻辑日志分离。
* LogAppender, 定义日志的输出落地点，目前实现了控制台日志(StdoutLogAppender)，文件日志(FileLogAppender).两种类型。拥有自己的日志级别和日志格式，可以灵活定义不同的输出。主要用于区分日志级别，将error日志，单独输出到一个文件，以防被其他类型的日志淹没
* LogFormat，日志格式，通过字符串自定义日志的格式，仿printf格式。可以灵活定义日志格式
* *******************************************************************************************************************************************************************************************************************/
#include <string>
#include <memory>
#include <stdint.h>
#include <list>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <stdarg.h>
#include <iostream>

namespace  zero {
class LogEvent {
public:
    using logEvent_ptr = std::shared_ptr<LogEvent>;
    LogEvent();
private:
    const char* m_file = nullptr;  /* 文件名 */
    int32_t m_line = 0;            /* 行号 */
    uint32_t m_threadId = 0;       /* 线程id */
    uint32_t m_fiberId = 0;        /* 协程id*/
    uint64_t m_time;               /* 时间戳*/
    uint32_t elapse = 0;           /* 程序启动开始到现在的毫秒数*/
    std::string m_content;         

};

/* 日志等级 */
class LogLevel {
public:
    enum Level {
        DEBUG = 1,
        INFO  = 2,
        WARN  = 3,
        ERROR = 4,
        FATAL = 5
    };
};

/* LogFormat（日志格式器） */
class LogFormatter {
public:
    using logFormatter_ptr = std::shared_ptr<LogFormatter>;

protected:
    std::string format(LogEvent::logEvent_ptr event);

};

/* LogAppender（输出落地点） */
class LogAppender {
public:
    using logAppender_ptr = std::shared_ptr<LogAppender>;
    virtual ~LogAppender() { };

    virtual void log(LogLevel::Level level,LogEvent::logEvent_ptr event) = 0;
    void setFormatter(LogFormatter::logFormatter_ptr format) {  m_formatter = format; }
    LogFormatter::logFormatter_ptr getFormatter() const { return m_formatter; }
private:
protected:
    LogLevel::Level m_level;
    /
    LogFormatter::logFormatter_ptr m_formatter;
};

/* 将日志抽象成Logger（日志器）*/
class Logger {
public:
    using logger_ptr = std::shared_ptr<Logger>;

    Logger(const std::string& name ="root");
    void log(LogLevel::Level level,LogEvent::logEvent_ptr event);
    void debug(LogEvent::logEvent_ptr event);
    void info(LogEvent::logEvent_ptr event);
    void warn(LogEvent::logEvent_ptr event);
    void error(LogEvent::logEvent_ptr event);
    void fatal(LogEvent::logEvent_ptr event);

    void addAppender(LogAppender::logAppender_ptr appender);
    void delAppender(LogAppender::logAppender_ptr appender);
    LogLevel::Level getLevel() const { return m_level; }
    void setLevel(LogLevel::Level level) { m_level = level; }
private:
    std::string m_name;                                              /* 日志级别 */
    LogLevel::Level m_level;                                         /* 日志名称 */
    std::list<LogAppender::logAppender_ptr> m_appender_lists;        /* Appender 集合 */
};

/* 输出到控制台的Appender */
class StdoutLogAppender : public LogAppender {
public:
    using stdoutLogAppender_ptr = std::shared_ptr<StdoutLogAppender>;
    virtual void log(LogLevel::Level level,LogEvent::logEvent_ptr event) override;
};

/* 定义输出到文件的appender */
class FileLogAppender : public LogAppender {
public:
    using fileLogAppender_ptr = std::shared_ptr<FileLogAppender>;
    FileLogAppender(const std::string& filename);
    virtual void log(LogLevel::Level level,LogEvent::logEvent_ptr event) override;
    void reopen();                                                     /* 文件打开 */
private:
    std::string m_name;
    std::ofstream m_filestream;
};

}
#endif // !__LoG_H__
