// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00405d80  unit: VCWorkspace::?$CComObject  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00405d80
//
// 00405d80  51                   push ecx
// 00405d81  8d0424               lea eax, [esp]
// 00405d84  c701e0b28000         mov dword ptr [ecx], 0x80b2e0
// 00405d8a  890c24               mov dword ptr [esp], ecx
// 00405d8d  50                   push eax
// 00405d8e  b93cc29600           mov ecx, 0x96c23c
// 00405d93  e8c8411e00           call 0x5e9f60
// 00405d98  59                   pop ecx
// 00405d99  c3                   ret 

struct S;

struct Registry {
    void remove(S* const* object);
};

struct S {
    unsigned long vtable;
    void f();
};

void S::f()
{
    vtable = 0x80b2e0;
    S* object = this;
    reinterpret_cast<Registry*>(0x96c23c)->remove(&object);
}
