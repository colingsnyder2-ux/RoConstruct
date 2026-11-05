// from server: 100% by nuck16
// roc 2009-12 00415e10  unit: PasteVerb  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00415e10
//
// 00415e10  8b09                 mov ecx, dword ptr [ecx]
// 00415e12  8b4108               mov eax, dword ptr [ecx + 8]
// 00415e15  50                   push eax
// 00415e16  b9d033b000           mov ecx, 0xb033d0
// 00415e1b  ff1568b79800         call dword ptr [0x98b768]
// 00415e21  c3                   ret 

#include <typeinfo>

// 0xb033d0 is the RTTI type descriptor of the expected type
extern const type_info type_descriptor_b033d0;

struct Holder { char pad[8]; const type_info *type; bool is(const type_info &t) const { return t == *type; } };

struct S
{
    Holder *holder;
    bool f();
};

bool S::f()
{
    return holder->is(type_descriptor_b033d0);
}
