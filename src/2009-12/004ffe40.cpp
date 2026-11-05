// from server: 100% by nuck16
// roc 2009-12 004ffe40  unit: RBX::Network::Player::W4BuildPermission::?$EnumDesc  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ffe40
//
// 004ffe40  8b09                 mov ecx, dword ptr [ecx]
// 004ffe42  8b4108               mov eax, dword ptr [ecx + 8]
// 004ffe45  50                   push eax
// 004ffe46  b9f83cb100           mov ecx, 0xb13cf8
// 004ffe4b  ff1568b79800         call dword ptr [0x98b768]
// 004ffe51  c3                   ret 

#include <typeinfo>

// 0xb13cf8 is the RTTI type descriptor of the expected type
extern const type_info type_descriptor_b13cf8;

struct Holder { char pad[8]; const type_info *type; bool is(const type_info &t) const { return t == *type; } };

struct S
{
    Holder *holder;
    bool f();
};

bool S::f()
{
    return holder->is(type_descriptor_b13cf8);
}
