// from server: 100% by nuck16
// roc 2009-12 006d5320  unit: RBX::VWeldTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d5320
//
// 006d5320  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d5323  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d5329  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d532f  85c0                 test eax, eax
// 006d5331  7416                 je 0x6d5349
// 006d5333  50                   push eax
// 006d5334  e84dff1100           call 0x7f5286
// 006d5339  83c404               add esp, 4
// 006d533c  50                   push eax
// 006d533d  b984f2b300           mov ecx, 0xb3f284
// 006d5342  ff1568b79800         call dword ptr [0x98b768]
// 006d5348  c3                   ret 
// 006d5349  32c0                 xor al, al
// 006d534b  c3                   ret 

#include <typeinfo>

// 0xb3f284 is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3f284;

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
        return type_descriptor_b3f284 == typeid(*tool);
    return false;
}
