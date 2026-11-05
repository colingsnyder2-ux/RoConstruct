// from server: 100% by EspClaude
// roc 2009-06 005c9320  unit: seg_005c0000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c9320
//
// 005c9320  81ec84000000         sub esp, 0x84
// 005c9326  56                   push esi
// 005c9327  8d4c2404             lea ecx, [esp + 4]
// 005c932b  e8e0c1f9ff           call 0x565510
// 005c9330  8b7064               mov esi, dword ptr [eax + 0x64]
// 005c9333  8d4c2404             lea ecx, [esp + 4]
// 005c9337  e894f8ffff           call 0x5c8bd0
// 005c933c  8bc6                 mov eax, esi
// 005c933e  5e                   pop esi
// 005c933f  81c484000000         add esp, 0x84
// 005c9345  c3                   ret 
// copied from an identical function in another client (function ?getCachedRemoteSourceLoadState@ContentProvider@ns_ROCX00001f@@QAEHXZ)

namespace ns_ROCX00001f {
struct Helper {
    char padding[0x64];
    int field64;
};
struct HelperMaker { Helper* makeHelper(); };
struct HelperDestroyer { void destroyHelper(); };
struct ContentProvider { int getCachedRemoteSourceLoadState(); };

int ContentProvider::getCachedRemoteSourceLoadState() {
    char buf[0x84];
    HelperMaker* m = (HelperMaker*)buf;
    Helper* h = m->makeHelper();
    int result = h->field64;
    HelperDestroyer* d = (HelperDestroyer*)buf;
    d->destroyHelper();
    return result;
}
}
