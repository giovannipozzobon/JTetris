#include "log.hpp"


void Log::LogDebug(char * strLog){
    WriteLog (strDebug);
    WriteLog (strLog);
    util.WriteCharDebug ('\n');
}

void Log::LogError(char * strLog){
    WriteLog (strLog);
    WriteLog (strLog);
    util.WriteCharDebug ('\n');
}
void Log::LogWarning(char * strLog){
    WriteLog (strWarning);
    WriteLog (strLog);
    util.WriteCharDebug ('\n');   
}
void Log::LogInfo(char * strLog){
     WriteLog (strInfo);
    WriteLog (strLog);
    util.WriteCharDebug ('\n'); 
}

void Log::WriteLog(char * str){
    for (int i=0; i<strlen(str); i++) util.WriteCharDebug(str[i]);
}
