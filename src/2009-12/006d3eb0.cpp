// from server: 100% by nuck16
// roc 2009-12 006d3eb0  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d3eb0  64a100000000         mov eax, dword ptr fs:[0]
// 006d3eb6  6aff                 push -1
// 006d3eb8  68eea29400           push 0x94a2ee
// 006d3ebd  50                   push eax
// 006d3ebe  b801000000           mov eax, 1
// 006d3ec3  64892500000000       mov dword ptr fs:[0], esp
// 006d3eca  84055c2cb900         test byte ptr [0xb92c5c], al
// 006d3ed0  752e                 jne 0x6d3f00
// 006d3ed2  09055c2cb900         or dword ptr [0xb92c5c], eax
// 006d3ed8  681424b600           push 0xb62414
// 006d3edd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d3ee5  e8f6e3f5ff           call 0x6322e0
// 006d3eea  83c404               add esp, 4
// 006d3eed  a3582cb900           mov dword ptr [0xb92c58], eax
// 006d3ef2  8b0c24               mov ecx, dword ptr [esp]
// 006d3ef5  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3efc  83c40c               add esp, 0xc
// 006d3eff  c3                   ret 
// 006d3f00  8b0c24               mov ecx, dword ptr [esp]
// 006d3f03  a1582cb900           mov eax, dword ptr [0xb92c58]
// 006d3f08  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3f0f  83c40c               add esp, 0xc
// 006d3f12  c3                   ret 

extern char string_00b62414[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b62414);
    return *name;
}
