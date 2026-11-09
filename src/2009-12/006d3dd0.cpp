// from server: 100% by nuck16
// roc 2009-12 006d3dd0  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d3dd0  64a100000000         mov eax, dword ptr fs:[0]
// 006d3dd6  6aff                 push -1
// 006d3dd8  68aea29400           push 0x94a2ae
// 006d3ddd  50                   push eax
// 006d3dde  b801000000           mov eax, 1
// 006d3de3  64892500000000       mov dword ptr fs:[0], esp
// 006d3dea  84054c2cb900         test byte ptr [0xb92c4c], al
// 006d3df0  752e                 jne 0x6d3e20
// 006d3df2  09054c2cb900         or dword ptr [0xb92c4c], eax
// 006d3df8  680424b600           push 0xb62404
// 006d3dfd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d3e05  e8d6e4f5ff           call 0x6322e0
// 006d3e0a  83c404               add esp, 4
// 006d3e0d  a3482cb900           mov dword ptr [0xb92c48], eax
// 006d3e12  8b0c24               mov ecx, dword ptr [esp]
// 006d3e15  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3e1c  83c40c               add esp, 0xc
// 006d3e1f  c3                   ret 
// 006d3e20  8b0c24               mov ecx, dword ptr [esp]
// 006d3e23  a1482cb900           mov eax, dword ptr [0xb92c48]
// 006d3e28  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3e2f  83c40c               add esp, 0xc
// 006d3e32  c3                   ret 

extern char string_00b62404[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b62404);
    return *name;
}
