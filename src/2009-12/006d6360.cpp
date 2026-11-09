// from server: 100% by nuck16
// roc 2009-12 006d6360  unit: RBX::VGameTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d6360
//
// 006d6360  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d6363  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d6369  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d636f  85c0                 test eax, eax
// 006d6371  7416                 je 0x6d6389
// 006d6373  50                   push eax
// 006d6374  e80def1100           call 0x7f5286
// 006d6379  83c404               add esp, 4
// 006d637c  50                   push eax
// 006d637d  b950fcb300           mov ecx, 0xb3fc50
// 006d6382  ff1568b79800         call dword ptr [0x98b768]
// 006d6388  c3                   ret 
// 006d6389  32c0                 xor al, al
// 006d638b  c3                   ret 

#include <typeinfo>

// 0xb3fc50 is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3fc50;

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
        return type_descriptor_b3fc50 == typeid(*tool);
    return false;
}
