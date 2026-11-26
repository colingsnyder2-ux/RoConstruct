// from server: 100% by Xemicl
// roc 2012-06 00433570  unit: MainLogManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00433570
//
// 00433570  56                   push esi
// 00433571  8bf1                 mov esi, ecx
// 00433573  ff15a021b200         call dword ptr [0xb221a0]
// 00433579  3b460c               cmp eax, dword ptr [esi + 0xc]
// 0043357c  7509                 jne 0x433587
// 0043357e  8d4e04               lea ecx, [esi + 4]
// 00433581  5e                   pop esi
// 00433582  e939deffff           jmp 0x4313c0
// 00433587  e894fbffff           call 0x433120
// 0043358c  8bc8                 mov ecx, eax
// 0043358e  5e                   pop esi
// 0043358f  e92cdeffff           jmp 0x4313c0
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