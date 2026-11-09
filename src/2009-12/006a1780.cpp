// from server: 100% by nuck16
// roc 2009-12 006a1780  unit: RBX::VScriptContext::?$FactoryProduct  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a1780
//
// 006a1780  8b09                 mov ecx, dword ptr [ecx]
// 006a1782  8b4108               mov eax, dword ptr [ecx + 8]
// 006a1785  50                   push eax
// 006a1786  b9fcd7b100           mov ecx, 0xb1d7fc
// 006a178b  ff1568b79800         call dword ptr [0x98b768]
// 006a1791  c3                   ret 

#include <typeinfo>

// 0xb1d7fc is the RTTI type descriptor of the expected type
extern const type_info type_descriptor_b1d7fc;

struct Holder { char pad[8]; const type_info *type; bool is(const type_info &t) const { return t == *type; } };

struct S
{
    Holder *holder;
    bool f();
};

bool S::f()
{
    return holder->is(type_descriptor_b1d7fc);
}
