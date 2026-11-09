// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef void* HANDLE; typedef unsigned long DWORD_PTR; typedef int BOOL;
typedef union _LARGE_INTEGER { struct { unsigned long LowPart; long HighPart; } u; __int64 QuadPart; } LARGE_INTEGER;
extern "C" {
__declspec(dllimport) HANDLE __stdcall GetCurrentProcess();
__declspec(dllimport) HANDLE __stdcall GetCurrentThread();
__declspec(dllimport) BOOL __stdcall GetProcessAffinityMask(HANDLE, DWORD_PTR*, DWORD_PTR*);
__declspec(dllimport) DWORD_PTR __stdcall SetThreadAffinityMask(HANDLE, DWORD_PTR);
__declspec(dllimport) BOOL __stdcall QueryPerformanceFrequency(LARGE_INTEGER*);
__declspec(dllimport) BOOL __stdcall QueryPerformanceCounter(LARGE_INTEGER*);
}
unsigned __int64 getMicroseconds()
{
    static HANDLE thread;
    static DWORD_PTR processMask;
    static LARGE_INTEGER frequency;
    static DWORD_PTR systemMask;
    static bool initialized = false;
    static unsigned __int64 lastTime;
    if (!initialized) {
        initialized = true;
        HANDLE process = GetCurrentProcess();
        GetProcessAffinityMask(process, &processMask, &systemMask);
        thread = GetCurrentThread();
        QueryPerformanceFrequency(&frequency);
    }
    SetThreadAffinityMask(thread, 1);
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    SetThreadAffinityMask(thread, processMask);
    unsigned __int64 c = counter.QuadPart;
    unsigned __int64 f = frequency.QuadPart;
    unsigned __int64 t = (c / f) * 1000000 + (c % f) * 1000000 / f;
    if (t < lastTime)
        return lastTime;
    lastTime = t;
    return t;
}
