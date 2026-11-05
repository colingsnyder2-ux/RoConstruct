// from server: 100% by EspClaude
// roc 2009-06 00424a60  unit: MainLogManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00424a60
//
// 00424a60  56                   push esi
// 00424a61  8bf1                 mov esi, ecx
// 00424a63  ff15ece18900         call dword ptr [0x89e1ec]
// 00424a69  3b460c               cmp eax, dword ptr [esi + 0xc]
// 00424a6c  7509                 jne 0x424a77
// 00424a6e  8d4e04               lea ecx, [esi + 4]
// 00424a71  5e                   pop esi
// 00424a72  e929dfffff           jmp 0x4229a0
// 00424a77  e8f4faffff           call 0x424570
// 00424a7c  8bc8                 mov ecx, eax
// 00424a7e  5e                   pop esi
// 00424a7f  e91cdfffff           jmp 0x4229a0
// copied from an identical function in another client (function ?apply@MainLogManager@ns_ROCX0000b1@@QAEXXZ)

namespace ns_ROCX0000b1 {
extern "C" unsigned long (__stdcall *GetCurrentThreadId)();

struct LogState {
    unsigned char storage[8];
    void apply();
};

LogState* __cdecl currentLogState();

struct MainLogManager {
    unsigned char storage[4];
    LogState state;
    unsigned long threadId;
    void apply();
};

void MainLogManager::apply()
{
    if (GetCurrentThreadId() == threadId)
        state.apply();
    else
        currentLogState()->apply();
}
}
