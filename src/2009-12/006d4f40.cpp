// from server: 100% by nuck16
// roc 2009-12 006d4f40  unit: RBX::VAxisRotateTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d4f40
//
// 006d4f40  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d4f43  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d4f49  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d4f4f  85c0                 test eax, eax
// 006d4f51  7416                 je 0x6d4f69
// 006d4f53  50                   push eax
// 006d4f54  e82d031200           call 0x7f5286
// 006d4f59  83c404               add esp, 4
// 006d4f5c  50                   push eax
// 006d4f5d  b994f0b300           mov ecx, 0xb3f094
// 006d4f62  ff1568b79800         call dword ptr [0x98b768]
// 006d4f68  c3                   ret 
// 006d4f69  32c0                 xor al, al
// 006d4f6b  c3                   ret 

#include <typeinfo>

// 0xb3f094 is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3f094;

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
        return type_descriptor_b3f094 == typeid(*tool);
    return false;
}
