// =============================================================================
// LogManager.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/LogManager.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include <afxwin.h>
#include <string.h>
#include <atlbase.h>
#include "AppLeaves2008/RobloxCrashReporter2008.h"
#include "VersionInfo.h"

inline CrashReporter::CrashReporter()
{
    singleton = this;
}

RobloxCrashReporter::RobloxCrashReporter(const char* pathToMinidump, const char* appName, MINIDUMP_TYPE minidumpType)
{
    controls.minidumpType = minidumpType;
    controls.actionToTake = 0xc;
    strcpy(controls.pathToMinidump, pathToMinidump);
    strcpy(controls.appName, appName);
    CVersionInfo info;
    info.Load(ATL::_AtlBaseModule.GetModuleInstance());
    CString version = info.GetFileVersionAsString();
    strcpy(controls.appVersion, version);
}

LONG RobloxCrashReporter::ProcessException(EXCEPTION_POINTERS* ExceptionInfo)
{
    LONG result = CrashReporter::ProcessException(ExceptionInfo);
    static bool messageShown = silentCrashReport;
    if (!messageShown)
    {
        messageShown = true;
        MessageBoxA(NULL, "An unexpected error occurred and ROBLOX needs to quit.  We're sorry!", "ROBLOX Crash", MB_OK);
    }
    return result;
}

#include "CRobloxApp.h"

std::string archiveFile(const char* path, std::string directory);

LogManager::~LogManager()
{
    if (log) {
        std::string path(log->logFile);
        RBX::Log::Severity severity = log->worstSeverity;
        delete log;
        log = 0;
        if (severity == RBX::Log::Error)
            archiveFile(path.c_str(), "error\\");
        else
            archiveFile(path.c_str(), "archive\\");
    }
}

extern bool loggingEnabled;

RBX::Log* LogManager::getLog()
{
    if (!loggingEnabled)
        return 0;
    if (!log)
        log = new RBX::Log(getLogPath().c_str(), name.c_str());
    return log;
}
