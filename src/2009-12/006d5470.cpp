// from server: 100% by nuck16
// roc 2009-12 006d5470  unit: RBX::VStudsTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d5470
//
// 006d5470  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d5473  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d5479  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d547f  85c0                 test eax, eax
// 006d5481  7416                 je 0x6d5499
// 006d5483  50                   push eax
// 006d5484  e8fdfd1100           call 0x7f5286
// 006d5489  83c404               add esp, 4
// 006d548c  50                   push eax
// 006d548d  b924f3b300           mov ecx, 0xb3f324
// 006d5492  ff1568b79800         call dword ptr [0x98b768]
// 006d5498  c3                   ret 
// 006d5499  32c0                 xor al, al
// 006d549b  c3                   ret 

#include <typeinfo>

// 0xb3f324 is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3f324;

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
        return type_descriptor_b3f324 == typeid(*tool);
    return false;
}
