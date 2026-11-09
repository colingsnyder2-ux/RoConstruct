// from server: 100% by nuck16
// roc 2009-12 006d6030  unit: RBX::VMaterialTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d6030
//
// 006d6030  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d6033  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d6039  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d603f  85c0                 test eax, eax
// 006d6041  7416                 je 0x6d6059
// 006d6043  50                   push eax
// 006d6044  e83df21100           call 0x7f5286
// 006d6049  83c404               add esp, 4
// 006d604c  50                   push eax
// 006d604d  b99cfab300           mov ecx, 0xb3fa9c
// 006d6052  ff1568b79800         call dword ptr [0x98b768]
// 006d6058  c3                   ret 
// 006d6059  32c0                 xor al, al
// 006d605b  c3                   ret 

#include <typeinfo>

// 0xb3fa9c is the RTTI type descriptor of the expected tool class
extern const type_info type_descriptor_b3fa9c;

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
        return type_descriptor_b3fa9c == typeid(*tool);
    return false;
}
