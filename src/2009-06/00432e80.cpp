// from server: 100% by EspClaude
// roc 2009-06 00432e80  unit: IIHAAH::?$CMap  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00432e80
//
// 00432e80  56                   push esi
// 00432e81  8bf1                 mov esi, ecx
// 00432e83  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 00432e89  85c0                 test eax, eax
// 00432e8b  7409                 je 0x432e96
// 00432e8d  50                   push eax
// 00432e8e  e89f5b2e00           call 0x718a32
// 00432e93  83c404               add esp, 4
// 00432e96  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 00432e9c  50                   push eax
// 00432e9d  c7861c01000000000000 mov dword ptr [esi + 0x11c], 0
// 00432ea7  c7862001000000000000 mov dword ptr [esi + 0x120], 0
// 00432eb1  c7862401000000000000 mov dword ptr [esi + 0x124], 0
// 00432ebb  e8725b2e00           call 0x718a32
// 00432ec0  83c404               add esp, 4
// 00432ec3  8bce                 mov ecx, esi
// 00432ec5  5e                   pop esi
// 00432ec6  e9358f3500           jmp 0x78be00
// copied from an identical function in another client (function ?cleanup@S@ns_ROCX00000e@@QAEXXZ)

namespace ns_ROCX00000e {
extern "C" void __cdecl release(void *);

struct S {
    unsigned char padding[0x110];
    void *storage;
    unsigned char reserved[8];
    void *entries;
    unsigned int count;
    unsigned int capacity;

    void cleanup();
    void finish();
};

void S::cleanup()
{
    if (entries)
        release(entries);

    entries = 0;
    count = 0;
    capacity = 0;

    release(storage);
    finish();
}
}
