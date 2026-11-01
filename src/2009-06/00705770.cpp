// from server: 85% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned long DWORD;
typedef unsigned long ULONG_PTR;
extern "C" __declspec(dllimport) void __stdcall RaiseException(DWORD code, DWORD flags, DWORD nargs, const ULONG_PTR* args);
struct THREADNAME_INFO {
    DWORD dwType;
    const char* szName;
    DWORD dwThreadID;
    DWORD dwFlags;
};
extern bool g_setThreadNames;
void SetThreadName(DWORD dwThreadID, const char* szThreadName)
{
    if (!g_setThreadNames)
        return;
    THREADNAME_INFO info;
    info.dwType = 0x1000;
    info.szName = szThreadName;
    info.dwThreadID = dwThreadID;
    info.dwFlags = 0;
    __try {
        RaiseException(0x406D1388, 0, sizeof(info) / sizeof(DWORD), (ULONG_PTR*)&info);
    }
    __except (-1) {
    }
}
