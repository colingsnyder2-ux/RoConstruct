// from server: 100% by EspClaude
// roc 2009-06 005c9480  unit: seg_005c0000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c9480
//
// 005c9480  81ec84000000         sub esp, 0x84
// 005c9486  56                   push esi
// 005c9487  8d4c2404             lea ecx, [esp + 4]
// 005c948b  e880c0f9ff           call 0x565510
// 005c9490  8b7004               mov esi, dword ptr [eax + 4]
// 005c9493  8d4c2404             lea ecx, [esp + 4]
// 005c9497  e834f7ffff           call 0x5c8bd0
// 005c949c  8bc6                 mov eax, esi
// 005c949e  5e                   pop esi
// 005c949f  81c484000000         add esp, 0x84
// 005c94a5  c3                   ret 
// copied from an identical function in another client (function ?getCachedRemoteSourceLoadState@ContentProvider@ns_ROCX000019@@QAEHXZ)

namespace ns_ROCX000019 {
struct Helper { int field0; int field4; };
struct ContentProvider { int getCachedRemoteSourceLoadState(); };
struct HelperMaker { Helper* makeHelper(); };
struct HelperDestroyer { void destroyHelper(); };
int ContentProvider::getCachedRemoteSourceLoadState() {
    char buf[0x84];
    HelperMaker* m = (HelperMaker*)buf;
    Helper* h = m->makeHelper();
    int result = h->field4;
    HelperDestroyer* d = (HelperDestroyer*)buf;
    d->destroyHelper();
    return result;
}
}
