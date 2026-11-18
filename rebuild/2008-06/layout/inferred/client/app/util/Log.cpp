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

namespace RBX {
static const char* information = "          ";
static const char* warning = " Warning: ";
static const char* error = " Error:   ";

void Log::writeEntry(Severity severity, const char* message)
{
    SYSTEMTIME now;
    char stamp[256];
    std::ostream& output = stream;
    GetLocalTime(&now);
    sprintf(stamp, "%02u:%02u:%02u.%03u ", now.wHour, now.wMinute, now.wSecond, now.wMilliseconds);
    output << stamp;
    output.flush();
    switch (severity) {
    case Information: output << information; break;
    case Warning: output << warning; break;
    case Error: output << error; break;
    }
    output << message;
    output << '\n';
    output.flush();
}
}
