// from server: 100% by EspClaude
// roc 2009-06 005c8c70  unit: seg_005c0000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c8c70
//
// 005c8c70  81ec84000000         sub esp, 0x84
// 005c8c76  56                   push esi
// 005c8c77  8d4c2404             lea ecx, [esp + 4]
// 005c8c7b  e890c8f9ff           call 0x565510
// 005c8c80  8b700c               mov esi, dword ptr [eax + 0xc]
// 005c8c83  8d4c2404             lea ecx, [esp + 4]
// 005c8c87  e844ffffff           call 0x5c8bd0
// 005c8c8c  8bc6                 mov eax, esi
// 005c8c8e  5e                   pop esi
// 005c8c8f  81c484000000         add esp, 0x84
// 005c8c95  c3                   ret 
// copied from an identical function in another client (function ?getCachedRemoteSourceLoadState@ContentProvider@ns_ROCX00001b@@QAEHXZ)

namespace ns_ROCX00001b {
struct Helper { int padding[3]; int value; };
struct HelperMaker { Helper* makeHelper(); };
struct HelperDestroyer { void destroyHelper(); };
struct ContentProvider { int getCachedRemoteSourceLoadState(); };

int ContentProvider::getCachedRemoteSourceLoadState() {
    char buf[0x84];
    Helper* h = ((HelperMaker*)buf)->makeHelper();
    int result = h->value;
    ((HelperDestroyer*)buf)->destroyHelper();
    return result;
}
}
