// from server: 100% by nuck16
// roc 2009-12 006d3f20  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d3f20  64a100000000         mov eax, dword ptr fs:[0]
// 006d3f26  6aff                 push -1
// 006d3f28  680ea39400           push 0x94a30e
// 006d3f2d  50                   push eax
// 006d3f2e  b801000000           mov eax, 1
// 006d3f33  64892500000000       mov dword ptr fs:[0], esp
// 006d3f3a  8405642cb900         test byte ptr [0xb92c64], al
// 006d3f40  752e                 jne 0x6d3f70
// 006d3f42  0905642cb900         or dword ptr [0xb92c64], eax
// 006d3f48  681c24b600           push 0xb6241c
// 006d3f4d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d3f55  e886e3f5ff           call 0x6322e0
// 006d3f5a  83c404               add esp, 4
// 006d3f5d  a3602cb900           mov dword ptr [0xb92c60], eax
// 006d3f62  8b0c24               mov ecx, dword ptr [esp]
// 006d3f65  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3f6c  83c40c               add esp, 0xc
// 006d3f6f  c3                   ret 
// 006d3f70  8b0c24               mov ecx, dword ptr [esp]
// 006d3f73  a1602cb900           mov eax, dword ptr [0xb92c60]
// 006d3f78  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3f7f  83c40c               add esp, 0xc
// 006d3f82  c3                   ret 

extern char string_00b6241c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b6241c);
    return *name;
}
