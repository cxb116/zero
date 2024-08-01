#include <base/StringPiece.h>
#include <base/Types.h>
#include <base/Timestamp.h>
#include <vector>
#include <sys/types.h>
#include <string>
namespace zero {

namespace ProcessInfo {
    pid_t pid();
    std::string pidString();
    uid_t uid();
    std::string username();
    uid_t euid();
    Timestamp startTime();
    int clockTicksPerSecond();
    int pageSize();
    bool isDebugBuild();

    std::string hostname();
    std::string procname();
    StringPiece procname(const std::string& stat);

    std::string procStatus();

    std::string procStat();

    std::string threadStat();

    std::string exePath();

    int openedFiles();

    int maxOpenFiles();

    struct CpuTime {

        double userSeconds;
        double systemSeconds;

        CpuTime() :userSeconds(0.0),systemSeconds(0.0) {
        };
    };
    CpuTime cpuTime();
    int numThreads();
    std::vector<pid_t> threads();
};
}