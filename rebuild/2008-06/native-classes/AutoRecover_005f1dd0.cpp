// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

// INFERRED: semaphore-guarded object; handle at +0, counter at +0x10
struct SemaphoreGuard {
    HANDLE handle;
    int pad[3];
    int count;
};

extern "C" void __fastcall fn_005f1dd0(SemaphoreGuard* self, int unusedEdx)
{
    WaitForSingleObject(self->handle, INFINITE);
    self->count++;
    ReleaseSemaphore(self->handle, 1, 0);
}
