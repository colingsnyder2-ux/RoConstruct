// from server: 100% by Yeetserama
// roc 2011-06 00448e80  unit: RBX::VTexture::?$FactoryProduct::Creator  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00448e80
//
// 00448e80  6aff                 push -1
// 00448e82  6898169d00           push 0x9d1698
// 00448e87  64a100000000         mov eax, dword ptr fs:[0]
// 00448e8d  50                   push eax
// 00448e8e  64892500000000       mov dword ptr fs:[0], esp
// 00448e95  51                   push ecx
// 00448e96  8b442418             mov eax, dword ptr [esp + 0x18]
// 00448e9a  56                   push esi
// 00448e9b  8bf1                 mov esi, ecx
// 00448e9d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00448ea1  50                   push eax
// 00448ea2  51                   push ecx
// 00448ea3  8bce                 mov ecx, esi
// 00448ea5  8974240c             mov dword ptr [esp + 0xc], esi
// 00448ea9  e8c2d1ffff           call 0x446070
// 00448eae  6a01                 push 1
// 00448eb0  8bce                 mov ecx, esi
// 00448eb2  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00448eba  c706bca7a600         mov dword ptr [esi], 0xa6a7bc
// 00448ec0  c746205ca7a600       mov dword ptr [esi + 0x20], 0xa6a75c
// 00448ec7  c7862001000050a7a600 mov dword ptr [esi + 0x120], 0xa6a750
// 00448ed1  e82a384300           call 0x87c700
// 00448ed6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00448eda  8bc6                 mov eax, esi
// 00448edc  5e                   pop esi
// 00448edd  64890d00000000       mov dword ptr fs:[0], ecx
// 00448ee4  83c410               add esp, 0x10
// 00448ee7  c20800               ret 8
// copied from an identical function in another client (function ??0S@ns_ROCX000003@@QAE@HH@Z)

namespace ns_ROCX000003 {
// from server: 100% by king_originala
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
