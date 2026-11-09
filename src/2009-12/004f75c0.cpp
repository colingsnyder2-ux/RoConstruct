// from server: 100% by nuck16
// roc 2009-12 004f75c0  unit: RBX::VBrickColor::?$holder  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004f75c0
//
// 004f75c0  8b09                 mov ecx, dword ptr [ecx]
// 004f75c2  8b4108               mov eax, dword ptr [ecx + 8]
// 004f75c5  50                   push eax
// 004f75c6  b96c31b100           mov ecx, 0xb1316c
// 004f75cb  ff1568b79800         call dword ptr [0x98b768]
// 004f75d1  c3                   ret 

#include <typeinfo>

// 0xb1316c is the RTTI type descriptor of the expected type
extern const type_info type_descriptor_b1316c;

struct Holder { char pad[8]; const type_info *type; bool is(const type_info &t) const { return t == *type; } };

struct S
{
    Holder *holder;
    bool f();
};

bool S::f()
{
    return holder->is(type_descriptor_b1316c);
}
