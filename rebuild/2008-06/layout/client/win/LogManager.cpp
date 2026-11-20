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
