#include "CrashReporter.h" // donor copy (rbxgs has an older one)

#include "FileOperations.h"
#include "decomp.h"

#include <dbghelp.h>
#include <stdio.h>
#include <string.h>

CrashReporter* CrashReporter::singleton;

// FUNCTION: WEBSERVICE 0x1018b340
// FUNCTION: ROBLOX 0x004b7e20
LONG CrashReporter::ProcessException(_EXCEPTION_POINTERS* ExceptionInfo)
{
	_MINIDUMP_EXCEPTION_INFORMATION eInfo;
	char dumpFilepath[MAX_PATH];
	char appDescriptor[MAX_PATH];
	char dumpFilename[MAX_PATH];

	if (!(controls.actionToTake & AOC_SILENT_MODE)) {
		sprintf(appDescriptor, "%s has crashed.\nGenerate a report?", controls.appName);
		if (MessageBox(NULL, appDescriptor, "Crash Reporter", MB_YESNO) == IDNO) {
			return EXCEPTION_CONTINUE_SEARCH;
		}
	}

	sprintf(appDescriptor, "%s %s", controls.appName, controls.appVersion);

	if (controls.actionToTake & AOC_WRITE_TO_DISK) {
		strcpy(dumpFilepath, controls.pathToMinidump);
		WriteFileWithDirectories(dumpFilepath, NULL, 0);
		AddSlash(dumpFilepath);

		strcpy(dumpFilename, appDescriptor);
		unsigned int length = strlen(appDescriptor);
		for (unsigned int i = 0; i < length; i++) {
			if (dumpFilename[i] == ':') {
				dumpFilename[i] = '.';
			}
		}

		strcat(dumpFilepath, dumpFilename);
		strcat(dumpFilepath, ".dmp");

		HANDLE hFile =
			CreateFile(dumpFilepath, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hFile == INVALID_HANDLE_VALUE) {
			return EXCEPTION_CONTINUE_SEARCH;
		}

		eInfo.ThreadId = GetCurrentThreadId();
		eInfo.ExceptionPointers = ExceptionInfo;
		eInfo.ClientPointers = FALSE;

		LONG result = EXCEPTION_EXECUTE_HANDLER;
		if (!MiniDumpWriteDump(
				GetCurrentProcess(),
				GetCurrentProcessId(),
				hFile,
				(MINIDUMP_TYPE) controls.minidumpType,
				ExceptionInfo ? &eInfo : NULL,
				NULL,
				NULL
			)) {
			result = EXCEPTION_CONTINUE_SEARCH;
		}

		CloseHandle(hFile);
		return result;
	}

	return EXCEPTION_EXECUTE_HANDLER;
}

// FUNCTION: WEBSERVICE 0x1018b550
// FUNCTION: ROBLOX 0x004b8030
LONG WINAPI CrashExceptionFilter(_EXCEPTION_POINTERS* ExceptionInfo)
{
	return CrashReporter::singleton->ProcessException(ExceptionInfo);
}

LPTOP_LEVEL_EXCEPTION_FILTER WINAPI
MyDummySetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter)
{
	return NULL;
}

// FUNCTION: WEBSERVICE 0x1018b560
// FUNCTION: ROBLOX 0x004b8040
BOOL PreventSetUnhandledExceptionFilter()
{
	HMODULE hKernel32 = LoadLibrary("kernel32.dll");
	if (hKernel32 == NULL) {
		return FALSE;
	}

	void* pOrgEntry = GetProcAddress(hKernel32, "SetUnhandledExceptionFilter");
	if (pOrgEntry == NULL) {
		return FALSE;
	}

	unsigned char newJump[100];
	DWORD dwOrgEntryAddr = (DWORD) pOrgEntry;
	dwOrgEntryAddr += 5;
	void* pNewFunc = &MyDummySetUnhandledExceptionFilter;
	DWORD dwNewEntryAddr = (DWORD) pNewFunc;
	DWORD dwRelativeAddr = dwNewEntryAddr - dwOrgEntryAddr;

	newJump[0] = 0xe9;
	memcpy(&newJump[1], &dwRelativeAddr, sizeof(pNewFunc));
	SIZE_T bytesWritten;
	BOOL bRet = WriteProcessMemory(GetCurrentProcess(), pOrgEntry, newJump, sizeof(pNewFunc) + 1, &bytesWritten);
	return bRet;
}

// FUNCTION: WEBSERVICE 0x1018b5e0
// FUNCTION: ROBLOX 0x004b80c0
void CrashReporter::Start()
{
	SetUnhandledExceptionFilter(CrashExceptionFilter);

	PreventSetUnhandledExceptionFilter();
}
