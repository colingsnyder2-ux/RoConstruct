// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native (inactive): two free functions the donor-free boot reaches.
//  - PreventSetUnhandledExceptionFilter 0049e4a0 (CrashReporter unit): the standard "patch SetUnhandledExceptionFilter with a
//    jmp to a dummy" hook: LoadLibrary("kernel32.dll"), GetProcAddress("SetUnhandledExceptionFilter"), then write
//    E9 <rel32 to the dummy> over its entry with WriteProcessMemory(GetCurrentProcess()). The exe's dummy target 005f2310 is a
//    folded `xor eax,eax; ret 4`.
//  - RBX::SetThreadName 00595a80: a flag byte (00949874) guards an empty __try/__except(CONTINUE_EXECUTION) body; the usual
//    RaiseException(0x406D1388) thread-name notification is compiled out in this build.
// INFERRED: the dummy filter and the empty-body SetThreadName shape follow the disassembly; no original source.
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "Network/CrashReporter.h"

// raknet30 FileOperations.h (openrbx Network/raknet30/Source): WriteFileWithDirectories 004a9a40, AddSlash 004a9b30.
bool WriteFileWithDirectories(const char* path, char* data, unsigned dataLength);
void AddSlash(char* input);

// openrbx Network/include/network/CrashReporter.h: the binary tests actionToTake (+4) with 8 and 4.
enum
{
	AOC_WRITE_TO_DISK = 4,
	AOC_SILENT_MODE = 8
};

// 0049e290: CrashReporter::ProcessException (openrbx Network/CrashReporter.cpp; called by
// RobloxCrashReporter::ProcessException 00427b00). Frame 0x318 = eInfo + three MAX_PATH buffers.
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

LPTOP_LEVEL_EXCEPTION_FILTER WINAPI DummySetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER)
{
    return NULL;
}

BOOL PreventSetUnhandledExceptionFilter()
{
    HMODULE kernel = LoadLibraryA("kernel32.dll");
    if (!kernel) return FALSE;
    void* entry = GetProcAddress(kernel, "SetUnhandledExceptionFilter");
    if (!entry) return FALSE;
    unsigned char jump[100];
    DWORD relative = (DWORD)&DummySetUnhandledExceptionFilter - ((DWORD)entry + 5);
    jump[0] = 0xE9;
    memcpy(&jump[1], &relative, sizeof(relative));
    SIZE_T written;
    return WriteProcessMemory(GetCurrentProcess(), entry, jump, sizeof(relative) + 1, &written);
}

namespace RBX
{
    bool threadNamingEnabled;   // 00949874
    void SetThreadName(DWORD, const char*)
    {
        if (threadNamingEnabled) {
            __try {
            } __except (EXCEPTION_CONTINUE_EXECUTION) {
            }
        }
    }
}
