// =============================================================================
// CrashReporter.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/network/include/network/CrashReporter.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <windows.h>
#include <dbghelp.h>

struct CrashReportControls
{
	int actionToTake;
	char appName[128];
	char appVersion[128];
	char pathToMinidump[260];
	char SMTPServer[128];
	char SMTPAccountName[64];
	char emailSender[64];
	char emailSubjectPrefix[128];
	char emailBody[1024];
	char emailRecipient[64];
	MINIDUMP_TYPE minidumpType;
};

class CrashReporter
{
public:
	CrashReportControls controls;
	static CrashReporter* singleton;

	CrashReporter();
	void Start();
	virtual LONG ProcessException(EXCEPTION_POINTERS* ExceptionInfo);
};
