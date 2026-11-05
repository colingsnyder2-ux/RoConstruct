// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00563260  unit: RBX::ContentProvider  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00563260
//
// 00563260  81ec84000000         sub esp, 0x84
// 00563266  56                   push esi
// 00563267  8d4c2404             lea ecx, [esp + 4]
// 0056326b  e870e8f9ff           call 0x501ae0
// 00563270  8b7008               mov esi, dword ptr [eax + 8]
// 00563273  8d4c2404             lea ecx, [esp + 4]
// 00563277  e844ffffff           call 0x5631c0
// 0056327c  8bc6                 mov eax, esi
// 0056327e  5e                   pop esi
// 0056327f  81c484000000         add esp, 0x84
// 00563285  c3                   ret 

struct Helper { int field0; int field4; int field8; };
struct HelperMaker { Helper* makeHelper(); };
struct HelperDestroyer { void destroyHelper(); };
struct ContentProvider { int getCachedRemoteSourceLoadState(); };

int ContentProvider::getCachedRemoteSourceLoadState() {
    char buf[0x84];
    HelperMaker* m = (HelperMaker*)buf;
    Helper* h = m->makeHelper();
    int result = h->field8;
    HelperDestroyer* d = (HelperDestroyer*)buf;
    d->destroyHelper();
    return result;
}
