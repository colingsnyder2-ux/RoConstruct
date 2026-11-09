// from server: 100% by EspClaude
// roc 2009-06 00432ed0  unit: IIHAAH::?$CMap  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00432ed0
//
// 00432ed0  56                   push esi
// 00432ed1  8bf1                 mov esi, ecx
// 00432ed3  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 00432ed9  85c0                 test eax, eax
// 00432edb  7409                 je 0x432ee6
// 00432edd  50                   push eax
// 00432ede  e84f5b2e00           call 0x718a32
// 00432ee3  83c404               add esp, 4
// 00432ee6  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 00432eec  50                   push eax
// 00432eed  c7862401000000000000 mov dword ptr [esi + 0x124], 0
// 00432ef7  c7862801000000000000 mov dword ptr [esi + 0x128], 0
// 00432f01  c7862c01000000000000 mov dword ptr [esi + 0x12c], 0
// 00432f0b  e8225b2e00           call 0x718a32
// 00432f10  83c404               add esp, 4
// 00432f13  8bce                 mov ecx, esi
// 00432f15  5e                   pop esi
// 00432f16  e925d13500           jmp 0x790040
// copied from an identical function in another client (function ?cleanup@S@ns_ROCX00000b@@QAEXXZ)

namespace ns_ROCX00000b {
extern "C" void __cdecl release(void *);

struct S {
    unsigned char padding[0x118];
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
