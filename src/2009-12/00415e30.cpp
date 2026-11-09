// from server: 100% by nuck16
// roc 2009-12 00415e30  unit: PasteVerb  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00415e30
//
// 00415e30  8b09                 mov ecx, dword ptr [ecx]
// 00415e32  8b4108               mov eax, dword ptr [ecx + 8]
// 00415e35  50                   push eax
// 00415e36  b9dc33b000           mov ecx, 0xb033dc
// 00415e3b  ff1568b79800         call dword ptr [0x98b768]
// 00415e41  c3                   ret 

#include <typeinfo>

// 0xb033dc is the RTTI type descriptor of the expected type
extern const type_info type_descriptor_b033dc;

struct Holder { char pad[8]; const type_info *type; bool is(const type_info &t) const { return t == *type; } };

struct S
{
    Holder *holder;
    bool f();
};

bool S::f()
{
    return holder->is(type_descriptor_b033dc);
}
