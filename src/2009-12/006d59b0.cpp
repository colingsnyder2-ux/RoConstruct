// from server: 100% by nuck16
// roc 2009-12 006d59b0  unit: RBX::VRightMotorTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d59b0
//
// 006d59b0  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d59b3  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d59b9  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d59bf  85c0                 test eax, eax
// 006d59c1  7416                 je 0x6d59d9
// 006d59c3  50                   push eax
// 006d59c4  e8bdf81100           call 0x7f5286
// 006d59c9  83c404               add esp, 4
// 006d59cc  50                   push eax
// 006d59cd  b9c4f5b300           mov ecx, 0xb3f5c4
// 006d59d2  ff1568b79800         call dword ptr [0x98b768]
// 006d59d8  c3                   ret 
// 006d59d9  32c0                 xor al, al
// 006d59db  c3                   ret 

#include <typeinfo>

// 0xb3f5c4 is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3f5c4;

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
        return type_descriptor_b3f5c4 == typeid(*tool);
    return false;
}
