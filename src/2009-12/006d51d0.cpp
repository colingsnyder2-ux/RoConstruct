// from server: 100% by nuck16
// roc 2009-12 006d51d0  unit: RBX::VGlueTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d51d0
//
// 006d51d0  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d51d3  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d51d9  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d51df  85c0                 test eax, eax
// 006d51e1  7416                 je 0x6d51f9
// 006d51e3  50                   push eax
// 006d51e4  e89d001200           call 0x7f5286
// 006d51e9  83c404               add esp, 4
// 006d51ec  50                   push eax
// 006d51ed  b9e4f1b300           mov ecx, 0xb3f1e4
// 006d51f2  ff1568b79800         call dword ptr [0x98b768]
// 006d51f8  c3                   ret 
// 006d51f9  32c0                 xor al, al
// 006d51fb  c3                   ret 

#include <typeinfo>

// 0xb3f1e4 is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3f1e4;

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
        return type_descriptor_b3f1e4 == typeid(*tool);
    return false;
}
