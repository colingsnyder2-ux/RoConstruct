// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

// INFERRED: Terekhov-style condition variable layout (boost::thread condition_impl), from field use.
struct CondImpl {
    HANDLE queue;      // +0
    HANDLE gate;       // +4
    HANDLE mutex;      // +8
    int blocked;       // +0xc
    int gone;          // +0x10
    int unblock;       // +0x14
};

extern "C" void __fastcall fn_005f1df0(CondImpl* self, int unusedEdx)
{
    WaitForSingleObject(self->gate, INFINITE);
    WaitForSingleObject(self->mutex, INFINITE);

    int signalsLeft = self->unblock;
    int waitersWasBlocked = self->blocked;

    if (signalsLeft != 0) {
        if (--self->unblock == 0) {
            if (self->gone != 0) {
                ReleaseSemaphore(self->queue, 1, 0);
                signalsLeft = 0;
            } else if (waitersWasBlocked != 0) {
                self->blocked = 0;
            }
        }
    } else {
        self->blocked = waitersWasBlocked + 1;
        if (self->blocked == 0x7fffffff) {
            WaitForSingleObject(self->queue, INFINITE);
            self->gone -= self->blocked;
            ReleaseSemaphore(self->queue, 1, 0);
            self->blocked = 0;
        }
    }

    ReleaseMutex(self->mutex);

    if (signalsLeft == 1) {
        if (waitersWasBlocked != 0) {
            do {
                WaitForSingleObject(self->gate, INFINITE);
            } while (--waitersWasBlocked != 0);
        }
        ReleaseSemaphore(self->queue, 1, 0);
    }
}
