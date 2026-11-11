#ifndef NETWORK_CRASHREPORTER_H
#define NETWORK_CRASHREPORTER_H

#include "decomp.h"

#include <windows.h>

enum CrashReportAction
{
	AOC_WRITE_TO_DISK = 4,
	AOC_SILENT_MODE = 8
};

// SIZE 0x7cc
struct CrashReportControls
{
	int actionToTake;             // 0x000
	char appName[128];            // 0x004
	char appVersion[128];         // 0x084
	char pathToMinidump[260];     // 0x104
	char SMTPServer[128];         // 0x208
	char SMTPAccountName[64];     // 0x288
	char emailSender[64];         // 0x2c8
	char emailSubjectPrefix[128]; // 0x308
	char emailBody[1024];         // 0x388
	char emailRecipient[64];      // 0x788
	int minidumpType;             // 0x7c8
};

DECOMP_SIZE_ASSERT(CrashReportControls, 0x7cc)

// SIZE 0x7d0
class CrashReporter
{
public:
	static CrashReporter* singleton;

	CrashReportControls controls; // 0x004

	CrashReporter() { singleton = this; }

	void Start();

	virtual LONG ProcessException(_EXCEPTION_POINTERS* ExceptionInfo); // vtable+0x00
};

DECOMP_SIZE_ASSERT(CrashReporter, 0x7d0)

#endif // NETWORK_CRASHREPORTER_H
