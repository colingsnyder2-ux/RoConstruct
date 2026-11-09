// from server: 100% by nuck16
// roc 2009-12 00415e50  unit: PasteVerb  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00415e50
//
// 00415e50  8b09                 mov ecx, dword ptr [ecx]
// 00415e52  8b4108               mov eax, dword ptr [ecx + 8]
// 00415e55  50                   push eax
// 00415e56  b9e833b000           mov ecx, 0xb033e8
// 00415e5b  ff1568b79800         call dword ptr [0x98b768]
// 00415e61  c3                   ret 

#include <typeinfo>

// 0xb033e8 is the RTTI type descriptor of the expected type
extern const type_info type_descriptor_b033e8;

struct Holder { char pad[8]; const type_info *type; bool is(const type_info &t) const { return t == *type; } };

struct S
{
    Holder *holder;
    bool f();
};

bool S::f()
{
    return holder->is(type_descriptor_b033e8);
}
