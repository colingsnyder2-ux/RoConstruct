// from server: 100% by nuck16
// roc 2009-12 006a17a0  unit: RBX::VScriptContext::?$FactoryProduct  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a17a0
//
// 006a17a0  8b09                 mov ecx, dword ptr [ecx]
// 006a17a2  8b4108               mov eax, dword ptr [ecx + 8]
// 006a17a5  50                   push eax
// 006a17a6  b9b0d6b100           mov ecx, 0xb1d6b0
// 006a17ab  ff1568b79800         call dword ptr [0x98b768]
// 006a17b1  c3                   ret 

#include <typeinfo>

// 0xb1d6b0 is the RTTI type descriptor of the expected type
extern const type_info type_descriptor_b1d6b0;

struct Holder { char pad[8]; const type_info *type; bool is(const type_info &t) const { return t == *type; } };

struct S
{
    Holder *holder;
    bool f();
};

bool S::f()
{
    return holder->is(type_descriptor_b1d6b0);
}
