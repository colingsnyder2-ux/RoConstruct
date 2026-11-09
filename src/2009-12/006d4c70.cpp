// from server: 100% by nuck16
// roc 2009-12 006d4c70  unit: RBX::VResizeTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d4c70
//
// 006d4c70  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d4c73  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d4c79  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d4c7f  85c0                 test eax, eax
// 006d4c81  7416                 je 0x6d4c99
// 006d4c83  50                   push eax
// 006d4c84  e8fd051200           call 0x7f5286
// 006d4c89  83c404               add esp, 4
// 006d4c8c  50                   push eax
// 006d4c8d  b918efb300           mov ecx, 0xb3ef18
// 006d4c92  ff1568b79800         call dword ptr [0x98b768]
// 006d4c98  c3                   ret 
// 006d4c99  32c0                 xor al, al
// 006d4c9b  c3                   ret 

#include <typeinfo>

// 0xb3ef18 is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3ef18;

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
        return type_descriptor_b3ef18 == typeid(*tool);
    return false;
}
