// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 00557330 boost::call_once (boost 1.34 win32 once, named-mutex variant)
#include <windows.h>
#include <sstream>

namespace boost {

// INFERRED: signature from mangled name ?call_once@boost@@YAXP6AXXZAAJ@Z
void call_once(void (__cdecl* func)(void), long& flag)
{
    if (InterlockedCompareExchange(&flag, 1, 1) == 0) {
        std::ostringstream strm;
        strm << "2AC1A572DB6944B0A65C38C4140AF2F4" << std::hex << GetCurrentProcessId() << (const void*)&flag;
        HANDLE mutex = CreateMutexA(0, 0, strm.str().c_str());
        WaitForSingleObject(mutex, INFINITE);
        try {
            if (InterlockedCompareExchange(&flag, 1, 1) == 0) {
                func();
                InterlockedExchange(&flag, 1);
            }
        } catch (...) {
            ReleaseMutex(mutex);
            CloseHandle(mutex);
            throw;
        }
        ReleaseMutex(mutex);
        CloseHandle(mutex);
    }
}

}
