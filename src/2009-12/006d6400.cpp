// from server: 100% by nuck16
// roc 2009-12 006d6400  unit: RBX::VGrabTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d6400
//
// 006d6400  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d6403  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d6409  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d640f  85c0                 test eax, eax
// 006d6411  7416                 je 0x6d6429
// 006d6413  50                   push eax
// 006d6414  e86dee1100           call 0x7f5286
// 006d6419  83c404               add esp, 4
// 006d641c  50                   push eax
// 006d641d  b9acfcb300           mov ecx, 0xb3fcac
// 006d6422  ff1568b79800         call dword ptr [0x98b768]
// 006d6428  c3                   ret 
// 006d6429  32c0                 xor al, al
// 006d642b  c3                   ret 

#include <typeinfo>

// 0xb3fcac is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3fcac;

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
        return type_descriptor_b3fcac == typeid(*tool);
    return false;
}
