// from server: 100% by EspClaude
// roc 2009-06 00433490  unit: IIHAAH::?$CMap  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00433490
//
// 00433490  56                   push esi
// 00433491  8bf1                 mov esi, ecx
// 00433493  8b8630010000         mov eax, dword ptr [esi + 0x130]
// 00433499  85c0                 test eax, eax
// 0043349b  7409                 je 0x4334a6
// 0043349d  50                   push eax
// 0043349e  e88f552e00           call 0x718a32
// 004334a3  83c404               add esp, 4
// 004334a6  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 004334ac  50                   push eax
// 004334ad  c7863001000000000000 mov dword ptr [esi + 0x130], 0
// 004334b7  c7863401000000000000 mov dword ptr [esi + 0x134], 0
// 004334c1  c7863801000000000000 mov dword ptr [esi + 0x138], 0
// 004334cb  e862552e00           call 0x718a32
// 004334d0  83c404               add esp, 4
// 004334d3  8bce                 mov ecx, esi
// 004334d5  5e                   pop esi
// 004334d6  e9d5c73500           jmp 0x78fcb0
// copied from an identical function in another client (function ?cleanup@S@ns_ROCX00000d@@QAEXXZ)

namespace ns_ROCX00000d {
extern "C" void __cdecl release(void *);

struct S {
    unsigned char padding[0x124];
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
