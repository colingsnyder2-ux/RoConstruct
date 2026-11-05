// from server: 100% by Yeetserama
// roc 2010-06 004361e0  unit: IIHAAH::?$CMap  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004361e0
//
// 004361e0  56                   push esi
// 004361e1  8bf1                 mov esi, ecx
// 004361e3  8b8630010000         mov eax, dword ptr [esi + 0x130]
// 004361e9  85c0                 test eax, eax
// 004361eb  7409                 je 0x4361f6
// 004361ed  50                   push eax
// 004361ee  e8a7173700           call 0x7a799a
// 004361f3  83c404               add esp, 4
// 004361f6  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 004361fc  50                   push eax
// 004361fd  c7863001000000000000 mov dword ptr [esi + 0x130], 0
// 00436207  c7863401000000000000 mov dword ptr [esi + 0x134], 0
// 00436211  c7863801000000000000 mov dword ptr [esi + 0x138], 0
// 0043621b  e87a173700           call 0x7a799a
// 00436220  83c404               add esp, 4
// 00436223  8bce                 mov ecx, esi
// 00436225  5e                   pop esi
// 00436226  e9758a3e00           jmp 0x81eca0
// copied from an identical function in another client (function ?cleanup@S@ns_ROCX000007@@QAEXXZ)

namespace ns_ROCX000007 {
// from server: 100% by tester
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
