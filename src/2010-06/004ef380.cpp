// from server: 100% by Yeetserama
// roc 2010-06 004ef380  unit: RBX::Network::Replicator::NewInstanceItem  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ef380
//
// 004ef380  56                   push esi
// 004ef381  8bf1                 mov esi, ecx
// 004ef383  8b4630               mov eax, dword ptr [esi + 0x30]
// 004ef386  85c0                 test eax, eax
// 004ef388  7409                 je 0x4ef393
// 004ef38a  50                   push eax
// 004ef38b  e80a862b00           call 0x7a799a
// 004ef390  83c404               add esp, 4
// 004ef393  8b4624               mov eax, dword ptr [esi + 0x24]
// 004ef396  50                   push eax
// 004ef397  c7463000000000       mov dword ptr [esi + 0x30], 0
// 004ef39e  c7463400000000       mov dword ptr [esi + 0x34], 0
// 004ef3a5  c7463800000000       mov dword ptr [esi + 0x38], 0
// 004ef3ac  e8e9852b00           call 0x7a799a
// 004ef3b1  83c404               add esp, 4
// 004ef3b4  8bce                 mov ecx, esi
// 004ef3b6  5e                   pop esi
// 004ef3b7  e9e49bf7ff           jmp 0x468fa0
// copied from an identical function in another client (function ?cleanup@S@ns_ROCX00000e@@QAEXXZ)

namespace ns_ROCX00000e {
// from server: 100% by king_originala
extern "C" void __cdecl release(void *);

struct S {
    char padding0[0x24];
    void *allocation;
    char padding1[8];
    void *begin;
    void *end;
    void *capacity;

    void cleanup();
    void finish();
};

void S::cleanup()
{
    if (begin)
        release(begin);

    begin = 0;
    end = 0;
    capacity = 0;

    release(allocation);
    finish();
}
}
