// from server: 100% by nuck16
// roc 2009-12 006d3c80  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d3c80  64a100000000         mov eax, dword ptr fs:[0]
// 006d3c86  6aff                 push -1
// 006d3c88  684ea29400           push 0x94a24e
// 006d3c8d  50                   push eax
// 006d3c8e  b801000000           mov eax, 1
// 006d3c93  64892500000000       mov dword ptr fs:[0], esp
// 006d3c9a  8405342cb900         test byte ptr [0xb92c34], al
// 006d3ca0  752e                 jne 0x6d3cd0
// 006d3ca2  0905342cb900         or dword ptr [0xb92c34], eax
// 006d3ca8  68f0a6b300           push 0xb3a6f0
// 006d3cad  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d3cb5  e826e6f5ff           call 0x6322e0
// 006d3cba  83c404               add esp, 4
// 006d3cbd  a3302cb900           mov dword ptr [0xb92c30], eax
// 006d3cc2  8b0c24               mov ecx, dword ptr [esp]
// 006d3cc5  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3ccc  83c40c               add esp, 0xc
// 006d3ccf  c3                   ret 
// 006d3cd0  8b0c24               mov ecx, dword ptr [esp]
// 006d3cd3  a1302cb900           mov eax, dword ptr [0xb92c30]
// 006d3cd8  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3cdf  83c40c               add esp, 0xc
// 006d3ce2  c3                   ret 

extern char string_00b3a6f0[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3a6f0);
    return *name;
}
