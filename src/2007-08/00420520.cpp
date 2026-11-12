// from server: 100% by EspClaude
// from server: 57% by colin
// roc 2007-08 00420520  unit: CRobloxTreeCtrl  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00420520
//
// 00420520  53                   push ebx
// 00420521  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00420525  55                   push ebp
// 00420526  56                   push esi
// 00420527  57                   push edi
// 00420528  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0042052c  8be9                 mov ebp, ecx
// 0042052e  8bff                 mov edi, edi
// 00420530  85db                 test ebx, ebx
// 00420532  7406                 je 0x42053a
// 00420534  3b5c241c             cmp ebx, dword ptr [esp + 0x1c]
// 00420538  740a                 je 0x420544
// 0042053a  8b35d8e67700         mov esi, dword ptr [0x77e6d8]
// 00420540  ffd6                 call esi
// 00420542  eb06                 jmp 0x42054a
// 00420544  8b35d8e67700         mov esi, dword ptr [0x77e6d8]
// 0042054a  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0042054e  745d                 je 0x4205ad
// 00420550  85db                 test ebx, ebx
// 00420552  7502                 jne 0x420556
// 00420554  ffd6                 call esi
// 00420556  3b7b08               cmp edi, dword ptr [ebx + 8]
// 00420559  7202                 jb 0x42055d
// 0042055b  ffd6                 call esi
// 0042055d  8b37                 mov esi, dword ptr [edi]
// 0042055f  85f6                 test esi, esi
// 00420561  7441                 je 0x4205a4
// 00420563  55                   push ebp
// 00420564  8bce                 mov ecx, esi
// 00420566  e855dd1100           call 0x53e2c0
// 0042056b  84c0                 test al, al
// 0042056d  7535                 jne 0x4205a4
// 0042056f  39aebc000000         cmp dword ptr [esi + 0xbc], ebp
// 00420575  742d                 je 0x4205a4
// 00420577  8b4500               mov eax, dword ptr [ebp]
// 0042057a  8b500c               mov edx, dword ptr [eax + 0xc]
// 0042057d  56                   push esi
// 0042057e  8bcd                 mov ecx, ebp
// 00420580  ffd2                 call edx
// 00420582  84c0                 test al, al
// 00420584  750e                 jne 0x420594
// 00420586  8b06                 mov eax, dword ptr [esi]
// 00420588  8b5010               mov edx, dword ptr [eax + 0x10]
// 0042058b  55                   push ebp
// 0042058c  8bce                 mov ecx, esi
// 0042058e  ffd2                 call edx
// 00420590  84c0                 test al, al
// 00420592  7410                 je 0x4205a4
// 00420594  3b7b08               cmp edi, dword ptr [ebx + 8]
// 00420597  7206                 jb 0x42059f
// 00420599  ff15d8e67700         call dword ptr [0x77e6d8]
// 0042059f  83c708               add edi, 8
// 004205a2  eb8c                 jmp 0x420530
// 004205a4  5f                   pop edi
// 004205a5  5e                   pop esi
// 004205a6  5d                   pop ebp
// 004205a7  32c0                 xor al, al

// VS2005 checked vector const_iterators passed by value (cont,ptr pairs at
// [esp+4..0x10], ret 0x10); element stride 8 (pointer + count), _Mylast at +8.
#include <vector>

class Instance;

struct InstancePtr
{
    Instance* px;
    void* pn;
    Instance* get() const { return px; }
};

class Instance
{
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool canAddChild(Instance* child);        // vtable +0xc
    virtual bool canSetParent(Instance* parent);      // vtable +0x10
    bool isAncestorOf(Instance* other);               // 0x53e2c0, thiscall
    char pad4[0xbc - 4];
    Instance* parent;                                 // +0xbc

    bool canAddChildren(std::vector<InstancePtr>::const_iterator begin,
                        std::vector<InstancePtr>::const_iterator end);
};

bool Instance::canAddChildren(std::vector<InstancePtr>::const_iterator begin,
                              std::vector<InstancePtr>::const_iterator end)
{
    for (std::vector<InstancePtr>::const_iterator it = begin; it != end; ++it)
    {
        Instance* c = it->get();
        if (!c)
            return false;
        if (c->isAncestorOf(this))
            return false;
        if (c->parent == this)
            return false;
        if (!canAddChild(c) && !c->canSetParent(this))
            return false;
    }
    return true;
}
