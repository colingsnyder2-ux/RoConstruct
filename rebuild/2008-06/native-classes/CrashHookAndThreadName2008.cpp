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
