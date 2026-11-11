// Inactive native 2008-06 RobloxCrashReporter (native-headers/AppLeaves2008/RobloxCrashReporter2008.h).
// >>> native-status (generated) -- do not edit >>>
// AppLeaves2008CrashReporter | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src bc1af4a1 | roc native-status --write
#include <afxwin.h>
#include <string.h>
#include <atlbase.h>
#include "AppLeaves2008/RobloxCrashReporter2008.h"
#include "VersionInfo.h"

#ifdef NATIVE_APPLEAVES2008_PENDING
// Needs an inline CrashReporter::CrashReporter() { singleton = this; } (the donor header declares it out of line;
// 00427a20 has no CrashReporter constructor call, only the singleton store).
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
#endif

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
