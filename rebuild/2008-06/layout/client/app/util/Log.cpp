// =============================================================================
// Log.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/util/Log.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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

namespace RBX
{
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
