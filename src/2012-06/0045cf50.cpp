// from server: 100% by Xemicl
// roc 2012-06 0045cf50  unit: RBX::VTexture::?$FactoryProduct::Creator  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0045cf50
//
// 0045cf50  6aff                 push -1
// 0045cf52  6878f4a900           push 0xa9f478
// 0045cf57  64a100000000         mov eax, dword ptr fs:[0]
// 0045cf5d  50                   push eax
// 0045cf5e  64892500000000       mov dword ptr fs:[0], esp
// 0045cf65  51                   push ecx
// 0045cf66  8b442418             mov eax, dword ptr [esp + 0x18]
// 0045cf6a  56                   push esi
// 0045cf6b  8bf1                 mov esi, ecx
// 0045cf6d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0045cf71  50                   push eax
// 0045cf72  51                   push ecx
// 0045cf73  8bce                 mov ecx, esi
// 0045cf75  8974240c             mov dword ptr [esp + 0xc], esi
// 0045cf79  e852b4ffff           call 0x4583d0
// 0045cf7e  6a01                 push 1
// 0045cf80  8bce                 mov ecx, esi
// 0045cf82  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0045cf8a  c7066454b500         mov dword ptr [esi], 0xb55464
// 0045cf90  c746200454b500       mov dword ptr [esi + 0x20], 0xb55404
// 0045cf97  c78620010000f853b500 mov dword ptr [esi + 0x120], 0xb553f8
// 0045cfa1  e8fa7c5900           call 0x9f4ca0
// 0045cfa6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0045cfaa  8bc6                 mov eax, esi
// 0045cfac  5e                   pop esi
// 0045cfad  64890d00000000       mov dword ptr fs:[0], ecx
// 0045cfb4  83c410               add esp, 0x10
// 0045cfb7  c20800               ret 8
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