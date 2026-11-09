// from server: 100% by nuck16
// roc 2009-12 006d4a80  unit: RBX::VArrowTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d4a80
//
// 006d4a80  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d4a83  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d4a89  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d4a8f  85c0                 test eax, eax
// 006d4a91  7416                 je 0x6d4aa9
// 006d4a93  50                   push eax
// 006d4a94  e8ed071200           call 0x7f5286
// 006d4a99  83c404               add esp, 4
// 006d4a9c  50                   push eax
// 006d4a9d  b90c8eb300           mov ecx, 0xb38e0c
// 006d4aa2  ff1568b79800         call dword ptr [0x98b768]
// 006d4aa8  c3                   ret 
// 006d4aa9  32c0                 xor al, al
// 006d4aab  c3                   ret 

#include <typeinfo>

// 0xb38e0c is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b38e0c;

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
        return type_descriptor_b38e0c == typeid(*tool);
    return false;
}
