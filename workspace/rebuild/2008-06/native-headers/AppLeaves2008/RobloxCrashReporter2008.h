#pragma once
// >>> native-status (generated) -- do not edit >>>
// RobloxCrashReporter2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 61d3a82a | roc native-status --write
// Inactive native 2008-06 RobloxCrashReporter (RTTI of vtable 00810320: RobloxCrashReporter : CrashReporter).
// CrashReporter is the donor Network/CrashReporter.h class: vptr +0, CrashReportControls controls +4
// (actionToTake +4, appName +8, appVersion +0x88, pathToMinidump +0x108, minidumpType +0x7cc), sizeof 0x7d0.
// MainLogManager::startCrashReporter 00428180 news 0x7d0 and calls the constructor 00427a20; the object is freed
// with plain operator delete (no destructor, no destructor slot: the vtable has the single ProcessException slot).
#include "Network/CrashReporter.h"

// Registry value "SilentCrashReport" (string 00816bc0) != 0, stored to 0096d0f4 by CRobloxApp::initializeSettings
// 0044c760 and read once by RobloxCrashReporter::ProcessException 00427b00. Name provisional (from the value name).
extern bool silentCrashReport;

class RobloxCrashReporter : public CrashReporter
{
public:
    // 00427a20: CrashReporter base is inline (stores CrashReporter::singleton 009706c0); actionToTake = 0xc,
    // pathToMinidump/appName copied, appVersion = CVersionInfo(_AtlBaseModule.m_hInst).GetFileVersionAsString().
    RobloxCrashReporter(const char* pathToMinidump, const char* appName, MINIDUMP_TYPE minidumpType);
    // slot 0 (00427b00)
    virtual LONG ProcessException(EXCEPTION_POINTERS* ExceptionInfo);
};
