// >>> native-status (generated) -- do not edit >>>
// LogLifetime | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src c82f1fd2 | roc native-status --write
#include "util/Log.h"
#include <windows.h>
#include <cstdio>

static void logTimeStamp(std::ofstream& stream, bool includeDate)
{
    char buffer[256];
    SYSTEMTIME now;
    GetLocalTime(&now);
    if (includeDate) {
        sprintf(buffer, "%02u.%02u.%u ", now.wDay, now.wMonth, now.wYear);
        stream << buffer;
    }
    sprintf(buffer, "%02u:%02u:%02u.%03u ", now.wHour, now.wMinute, now.wSecond, now.wMilliseconds);
    stream << buffer;
    stream.flush();
}

RBX::Log::Log(const char* file, const char* label)
    : name(label), worstSeverity(Information), logFile(file), stream(file, 2, 64)
{
    std::ofstream& output = stream;
    logTimeStamp(output, true);
    output << "Log \"" << label << "\"\n";
    output.flush();
}

RBX::Log::~Log()
{
    std::ofstream& output = stream;
    logTimeStamp(output, true);
    output << "End Log\n";
}
