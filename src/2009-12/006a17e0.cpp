// from server: 100% by nuck16
// roc 2009-12 006a17e0  unit: RBX::VScriptContext::?$FactoryProduct  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a17e0
//
// 006a17e0  8b09                 mov ecx, dword ptr [ecx]
// 006a17e2  8b4108               mov eax, dword ptr [ecx + 8]
// 006a17e5  50                   push eax
// 006a17e6  b96cd7b100           mov ecx, 0xb1d76c
// 006a17eb  ff1568b79800         call dword ptr [0x98b768]
// 006a17f1  c3                   ret 

#include <typeinfo>

// 0xb1d76c is the RTTI type descriptor of the expected type
extern const type_info type_descriptor_b1d76c;

struct Holder { char pad[8]; const type_info *type; bool is(const type_info &t) const { return t == *type; } };

struct S
{
    Holder *holder;
    bool f();
};

bool S::f()
{
    return holder->is(type_descriptor_b1d76c);
}
