// from server: 100% by nuck16
// roc 2009-12 006a1910  unit: RBX::VScriptContext::?$FactoryProduct  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a1910
//
// 006a1910  8b09                 mov ecx, dword ptr [ecx]
// 006a1912  8b4108               mov eax, dword ptr [ecx + 8]
// 006a1915  50                   push eax
// 006a1916  b9b48eb200           mov ecx, 0xb28eb4
// 006a191b  ff1568b79800         call dword ptr [0x98b768]
// 006a1921  c3                   ret 

#include <typeinfo>

// 0xb28eb4 is the RTTI type descriptor of the expected type
extern const type_info type_descriptor_b28eb4;

struct Holder { char pad[8]; const type_info *type; bool is(const type_info &t) const { return t == *type; } };

struct S
{
    Holder *holder;
    bool f();
};

bool S::f()
{
    return holder->is(type_descriptor_b28eb4);
}
