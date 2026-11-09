// from server: 100% by Yeetserama
// roc 2007-08 00415f50  unit: RBX::VInstance::?$NonFactoryProduct  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00415f50
//
// 00415f50  6aff                 push -1
// 00415f52  685bab7300           push 0x73ab5b
// 00415f57  64a100000000         mov eax, dword ptr fs:[0]
// 00415f5d  50                   push eax
// 00415f5e  51                   push ecx
// 00415f5f  56                   push esi
// 00415f60  57                   push edi
// 00415f61  a188518b00           mov eax, dword ptr [0x8b5188]
// 00415f66  33c4                 xor eax, esp
// 00415f68  50                   push eax
// 00415f69  8d442410             lea eax, [esp + 0x10]
// 00415f6d  64a300000000         mov dword ptr fs:[0], eax
// 00415f73  8bf1                 mov esi, ecx
// 00415f75  8974240c             mov dword ptr [esp + 0xc], esi
// 00415f79  8d7e08               lea edi, [esi + 8]
// 00415f7c  c7460400000000       mov dword ptr [esi + 4], 0
// 00415f83  8bcf                 mov ecx, edi
// 00415f85  c70688737800         mov dword ptr [esi], 0x787388
// 00415f8b  e8a0ebffff           call 0x414b30
// 00415f90  8b442420             mov eax, dword ptr [esp + 0x20]
// 00415f94  c70774737800         mov dword ptr [edi], 0x787374
// 00415f9a  c747044c737800       mov dword ptr [edi + 4], 0x78734c
// 00415fa1  894708               mov dword ptr [edi + 8], eax
// 00415fa4  8b0d44ae8b00         mov ecx, dword ptr [0x8bae44]
// 00415faa  8b11                 mov edx, dword ptr [ecx]
// 00415fac  8b4204               mov eax, dword ptr [edx + 4]
// 00415faf  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00415fb7  ffd0                 call eax
// 00415fb9  8bc6                 mov eax, esi
// 00415fbb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00415fbf  64890d00000000       mov dword ptr fs:[0], ecx
// 00415fc6  59                   pop ecx
// 00415fc7  5f                   pop edi
// 00415fc8  5e                   pop esi
// 00415fc9  83c410               add esp, 0x10
// 00415fcc  c20400               ret 4
// copied from an identical function in another client (function ??0S@ns_ROCX000002@@QAE@PAX@Z)

namespace ns_ROCX000002 {
// from server: 100% by king_originala
struct InterfaceA {
    virtual void methodA();
};

struct InterfaceB {
    virtual void methodB();
};

struct InnerBase : InterfaceA, InterfaceB {
    void *owner;
    InnerBase();
    ~InnerBase();
};

struct Inner : InnerBase {
    virtual void methodA();
    virtual void methodB();
    Inner(void *);
};

struct Module {
    virtual void unused();
    virtual long lock();
};

extern Module *module;

struct Base {
    long references;
    Base();
};

struct S : Base {
    virtual void method();
    Inner contained;
    S(void *);
};

__forceinline Base::Base() : references(0)
{
}

__forceinline Inner::Inner(void *p)
{
    owner = p;
}

S::S(void *p) : contained(p)
{
    module->lock();
}
}
