#ifndef LOG_HPP
#define LOG_HPP

#include "util.hpp"
#include <string.h>

class Log {

private:

Util util;
char * strDebug = {"Debug: "};
char * strError = {"Error: "};
char * strWarning = {"Warning: "};
char * strInfo = {"Info: "};

void WriteLog(char * str);

public:

    void LogDebug(char * strLog);
    void LogError(char * strLog);
    void LogWarning(char * strLog);
    void LogInfo(char * strLog);

};

#endif //LOG_HPP