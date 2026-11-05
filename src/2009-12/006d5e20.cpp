// from server: 100% by nuck16
// roc 2009-12 006d5e20  unit: RBX::VLockTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d5e20
//
// 006d5e20  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d5e23  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d5e29  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d5e2f  85c0                 test eax, eax
// 006d5e31  7416                 je 0x6d5e49
// 006d5e33  50                   push eax
// 006d5e34  e84df41100           call 0x7f5286
// 006d5e39  83c404               add esp, 4
// 006d5e3c  50                   push eax
// 006d5e3d  b960f9b300           mov ecx, 0xb3f960
// 006d5e42  ff1568b79800         call dword ptr [0x98b768]
// 006d5e48  c3                   ret 
// 006d5e49  32c0                 xor al, al
// 006d5e4b  c3                   ret 

#include <typeinfo>

// 0xb3f960 is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3f960;

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
        return type_descriptor_b3f960 == typeid(*tool);
    return false;
}
