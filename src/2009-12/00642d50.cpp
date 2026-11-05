// from server: 100% by nuck16
// roc 2009-12 00642d50  unit: RBX::Reflection::Descriptor  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00642d50
//
// 00642d50  8b09                 mov ecx, dword ptr [ecx]
// 00642d52  8b4108               mov eax, dword ptr [ecx + 8]
// 00642d55  50                   push eax
// 00642d56  b9d030b100           mov ecx, 0xb130d0
// 00642d5b  ff1568b79800         call dword ptr [0x98b768]
// 00642d61  c3                   ret 

#include <typeinfo>

// 0xb130d0 is the RTTI type descriptor of the expected type
extern const type_info type_descriptor_b130d0;

struct Holder { char pad[8]; const type_info *type; bool is(const type_info &t) const { return t == *type; } };

struct S
{
    Holder *holder;
    bool f();
};

bool S::f()
{
    return holder->is(type_descriptor_b130d0);
}
