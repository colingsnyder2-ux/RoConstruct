#include "util/Log.h"
#include <windows.h>
#include <cstdio>

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
