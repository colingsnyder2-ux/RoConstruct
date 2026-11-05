// from server: 100% by Yeetserama
// roc 2010-06 0043b340  unit: RBX::VTexture::?$FactoryProduct::Creator  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0043b340
//
// 0043b340  6aff                 push -1
// 0043b342  68d80c9800           push 0x980cd8
// 0043b347  64a100000000         mov eax, dword ptr fs:[0]
// 0043b34d  50                   push eax
// 0043b34e  64892500000000       mov dword ptr fs:[0], esp
// 0043b355  51                   push ecx
// 0043b356  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043b35a  56                   push esi
// 0043b35b  8bf1                 mov esi, ecx
// 0043b35d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043b361  50                   push eax
// 0043b362  51                   push ecx
// 0043b363  8bce                 mov ecx, esi
// 0043b365  8974240c             mov dword ptr [esp + 0xc], esi
// 0043b369  e862bcffff           call 0x436fd0
// 0043b36e  6a01                 push 1
// 0043b370  8bce                 mov ecx, esi
// 0043b372  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0043b37a  c706348da000         mov dword ptr [esi], 0xa08d34
// 0043b380  c74620d48ca000       mov dword ptr [esi + 0x20], 0xa08cd4
// 0043b387  c78620010000c88ca000 mov dword ptr [esi + 0x120], 0xa08cc8
// 0043b391  e87a3b3e00           call 0x81ef10
// 0043b396  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043b39a  8bc6                 mov eax, esi
// 0043b39c  5e                   pop esi
// 0043b39d  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b3a4  83c410               add esp, 0x10
// 0043b3a7  c20800               ret 8
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
