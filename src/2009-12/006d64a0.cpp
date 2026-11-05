// from server: 100% by nuck16
// from server: 97% by atomic.potato
// roc 2009-12 006d64a0  unit: RBX::VCloneTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d64a0
//
// 006d64a0  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006d64a3  8b88900a0000         mov ecx, dword ptr [eax + 0xa90]
// 006d64a9  8b81b4010000         mov eax, dword ptr [ecx + 0x1b4]
// 006d64af  85c0                 test eax, eax
// 006d64b1  7416                 je 0x6d64c9
// 006d64b3  50                   push eax
// 006d64b4  e8cded1100           call 0x7f5286
// 006d64b9  83c404               add esp, 4
// 006d64bc  50                   push eax
// 006d64bd  b908fdb300           mov ecx, 0xb3fd08
// 006d64c2  ff1568b79800         call dword ptr [0x98b768]
// 006d64c8  c3                   ret 

#include <typeinfo>

namespace RBX {
class Tool { public: virtual ~Tool(); };
class CloneTool : public Tool { public: ~CloneTool(); };
}

// layout read from the target: this+0xc -> owner, owner+0xa90 -> holder, holder+0x1b4 -> current tool
struct ToolHolder { char pad[0x1b4]; RBX::Tool *tool; };
struct ToolOwner { char pad[0xa90]; ToolHolder *holder; };

struct S
{
    char pad[0xc];
    ToolOwner *owner;
    bool f();
};

bool S::f()
{
    RBX::Tool *tool = owner->holder->tool;
    if (tool)
        return typeid(RBX::CloneTool) == typeid(*tool);
    return false;
}
