// from server: 100% by nuck16
// roc 2009-12 006d6880  unit: RBX::VRocketTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d6880
//
// 006d6880  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d6883  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d6889  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d688f  85c0                 test eax, eax
// 006d6891  7416                 je 0x6d68a9
// 006d6893  50                   push eax
// 006d6894  e8ede91100           call 0x7f5286
// 006d6899  83c404               add esp, 4
// 006d689c  50                   push eax
// 006d689d  b9d8feb300           mov ecx, 0xb3fed8
// 006d68a2  ff1568b79800         call dword ptr [0x98b768]
// 006d68a8  c3                   ret 
// 006d68a9  32c0                 xor al, al
// 006d68ab  c3                   ret 

#include <typeinfo>

// 0xb3fed8 is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3fed8;

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
        return type_descriptor_b3fed8 == typeid(*tool);
    return false;
}
