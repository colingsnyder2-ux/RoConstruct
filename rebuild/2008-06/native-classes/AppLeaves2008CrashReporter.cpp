// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
// Inactive native 2008-06 RobloxCrashReporter (native-headers/AppLeaves2008/RobloxCrashReporter2008.h).
// mfc-noinline-pcxstr: 00427ab4 calls CSimpleStringT::operator PCXSTR out of line (mfc90 #910), as in AppLeftovers.cpp.
#include <afxwin.h>
#include <string.h>
#include <atlbase.h>
#include "AppLeaves2008/RobloxCrashReporter2008.h"
#include "VersionInfo.h"

// 00427a20 inlines the CrashReporter base constructor: its only effect is the store of this to CrashReporter::singleton
// 009706c0 (00427a3f), with no CrashReporter vptr store and no call. The read-only donor Network/CrashReporter.h
// declares CrashReporter() out of line and no native header defines it, so this unit supplies the definition as an
// inline member function (legal for a member declared without inline; it must precede its use). Codegen analog of
// the original inline base constructor, not a claim about its declaration.
inline CrashReporter::CrashReporter()
{
    singleton = this;
}

// 00427a20 (MainLogManager::startCrashReporter 00428180 news 0x7d0 and calls it): minidumpType +0x7cc, vptr 00810320,
// actionToTake = 0xc, pathToMinidump +0x108 and appName +8 copied, appVersion +0x88 from
// CVersionInfo(_AtlBaseModule.m_hInst 0097f2ac).GetFileVersionAsString().
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
