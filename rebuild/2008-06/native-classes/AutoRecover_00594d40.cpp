// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

// INFERRED: a scoped lock holder. The first member is either a CRITICAL_SECTION*
// or a mutex HANDLE, and the byte at +4 selects which one it is.
struct ScopedLockHolder {
    void* handle;      // +0: CRITICAL_SECTION* or HANDLE
    bool isCritSect;   // +4: true means critical section, false means mutex
};

extern "C" void __fastcall fn_00594d40(ScopedLockHolder* self, int unusedEdx)
{
    if (self->isCritSect)
        LeaveCriticalSection((LPCRITICAL_SECTION)self->handle);
    else
        ReleaseMutex((HANDLE)self->handle);
}
