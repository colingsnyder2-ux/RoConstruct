// from server: 100% by nuck16
// roc 2009-12 006d5a70  unit: RBX::VLeftMotorTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d5a70
//
// 006d5a70  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d5a73  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d5a79  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d5a7f  85c0                 test eax, eax
// 006d5a81  7416                 je 0x6d5a99
// 006d5a83  50                   push eax
// 006d5a84  e8fdf71100           call 0x7f5286
// 006d5a89  83c404               add esp, 4
// 006d5a8c  50                   push eax
// 006d5a8d  b974f6b300           mov ecx, 0xb3f674
// 006d5a92  ff1568b79800         call dword ptr [0x98b768]
// 006d5a98  c3                   ret 
// 006d5a99  32c0                 xor al, al
// 006d5a9b  c3                   ret 

#include <typeinfo>

// 0xb3f674 is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3f674;

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
        return type_descriptor_b3f674 == typeid(*tool);
    return false;
}
