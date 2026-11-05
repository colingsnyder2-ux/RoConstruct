// from server: 100% by nuck16
// roc 2009-12 0067eac0  unit: RBX::ModelInstance  size: 18 bytes
//
// 0067eac0  8b09                 mov ecx, dword ptr [ecx]
// 0067eac2  8b4108               mov eax, dword ptr [ecx + 8]
// 0067eac5  50                   push eax
// 0067eac6  b950d8b100           mov ecx, 0xb1d850
// 0067eacb  ff1568b79800         call dword ptr [0x98b768]
// 0067ead1  c3                   ret 

#include <typeinfo>

// 0xb1d850 is the RTTI type descriptor of the expected type
extern const type_info type_descriptor_b1d850;

struct Holder { char pad[8]; const type_info *type; bool is(const type_info &t) const { return t == *type; } };

struct S
{
    Holder *holder;
    bool f();
};

bool S::f()
{
    return holder->is(type_descriptor_b1d850);
}
