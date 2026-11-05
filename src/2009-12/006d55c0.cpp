// from server: 100% by nuck16
// roc 2009-12 006d55c0  unit: RBX::VInletTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d55c0
//
// 006d55c0  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d55c3  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d55c9  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d55cf  85c0                 test eax, eax
// 006d55d1  7416                 je 0x6d55e9
// 006d55d3  50                   push eax
// 006d55d4  e8adfc1100           call 0x7f5286
// 006d55d9  83c404               add esp, 4
// 006d55dc  50                   push eax
// 006d55dd  b9c4f3b300           mov ecx, 0xb3f3c4
// 006d55e2  ff1568b79800         call dword ptr [0x98b768]
// 006d55e8  c3                   ret 
// 006d55e9  32c0                 xor al, al
// 006d55eb  c3                   ret 

#include <typeinfo>

// 0xb3f3c4 is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3f3c4;

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
        return type_descriptor_b3f3c4 == typeid(*tool);
    return false;
}
