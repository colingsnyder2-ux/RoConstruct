// from server: 100% by nuck16
// roc 2009-12 006d5c40  unit: RBX::VModelSetFrontTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d5c40
//
// 006d5c40  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d5c43  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d5c49  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d5c4f  85c0                 test eax, eax
// 006d5c51  7416                 je 0x6d5c69
// 006d5c53  50                   push eax
// 006d5c54  e82df61100           call 0x7f5286
// 006d5c59  83c404               add esp, 4
// 006d5c5c  50                   push eax
// 006d5c5d  b9e8f7b300           mov ecx, 0xb3f7e8
// 006d5c62  ff1568b79800         call dword ptr [0x98b768]
// 006d5c68  c3                   ret 
// 006d5c69  32c0                 xor al, al
// 006d5c6b  c3                   ret 

#include <typeinfo>

// 0xb3f7e8 is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3f7e8;

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
        return type_descriptor_b3f7e8 == typeid(*tool);
    return false;
}
