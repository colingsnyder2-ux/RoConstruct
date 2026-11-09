// from server: 100% by nuck16
// roc 2009-12 006d5ee0  unit: RBX::VFillTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d5ee0
//
// 006d5ee0  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d5ee3  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d5ee9  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d5eef  85c0                 test eax, eax
// 006d5ef1  7416                 je 0x6d5f09
// 006d5ef3  50                   push eax
// 006d5ef4  e88df31100           call 0x7f5286
// 006d5ef9  83c404               add esp, 4
// 006d5efc  50                   push eax
// 006d5efd  b9fcf9b300           mov ecx, 0xb3f9fc
// 006d5f02  ff1568b79800         call dword ptr [0x98b768]
// 006d5f08  c3                   ret 
// 006d5f09  32c0                 xor al, al
// 006d5f0b  c3                   ret 

#include <typeinfo>

// 0xb3f9fc is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3f9fc;

struct Tool { virtual ~Tool(); };
struct ToolHolder { char pad[0x1b4]; Tool *tool; };
struct ToolOwner { char pad[0xa90]; ToolHolder *holder; };

struct S
{
    char pad[0xc];
    ToolOwner *owner;
    bool f();
};

bool S::f()
{
    Tool *tool = owner->holder->tool;
    if (tool)
        return type_descriptor_b3f9fc == typeid(*tool);
    return false;
}
