// from server: 100% by EspClaude
// roc 2009-06 00437c40  unit: RBX::VTexture::?$FactoryProduct::Creator  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00437c40
//
// 00437c40  6aff                 push -1
// 00437c42  6888fc8400           push 0x84fc88
// 00437c47  64a100000000         mov eax, dword ptr fs:[0]
// 00437c4d  50                   push eax
// 00437c4e  64892500000000       mov dword ptr fs:[0], esp
// 00437c55  51                   push ecx
// 00437c56  8b442418             mov eax, dword ptr [esp + 0x18]
// 00437c5a  56                   push esi
// 00437c5b  8bf1                 mov esi, ecx
// 00437c5d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00437c61  50                   push eax
// 00437c62  51                   push ecx
// 00437c63  8bce                 mov ecx, esi
// 00437c65  8974240c             mov dword ptr [esp + 0xc], esi
// 00437c69  e8d2c8ffff           call 0x434540
// 00437c6e  6a01                 push 1
// 00437c70  8bce                 mov ecx, esi
// 00437c72  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00437c7a  c7067c4c8b00         mov dword ptr [esi], 0x8b4c7c
// 00437c80  c746201c4c8b00       mov dword ptr [esi + 0x20], 0x8b4c1c
// 00437c87  c78620010000104c8b00 mov dword ptr [esi + 0x120], 0x8b4c10
// 00437c91  e88a823500           call 0x78ff20
// 00437c96  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00437c9a  8bc6                 mov eax, esi
// 00437c9c  5e                   pop esi
// 00437c9d  64890d00000000       mov dword ptr fs:[0], ecx
// 00437ca4  83c410               add esp, 0x10
// 00437ca7  c20800               ret 8
// copied from an identical function in another client (function ??0S@ns_ROCX000002@@QAE@HH@Z)

namespace ns_ROCX000002 {
struct Primary {
    virtual ~Primary();
    char storage[0x1C];
};

struct Secondary {
    virtual ~Secondary();
    char storage[0xFC];
};

struct Tertiary {
    virtual ~Tertiary();
};

struct Base : Primary, Secondary, Tertiary {
    Base(int, int);
    virtual ~Base();
    void SetCheckBoxStyle(int);
};

struct S : Base {
    S(int, int);
    virtual ~S();
};

S::S(int a, int b) : Base(a, b) {
    SetCheckBoxStyle(1);
}
}
