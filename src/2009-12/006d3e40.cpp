// from server: 100% by nuck16
// roc 2009-12 006d3e40  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d3e40  64a100000000         mov eax, dword ptr fs:[0]
// 006d3e46  6aff                 push -1
// 006d3e48  68cea29400           push 0x94a2ce
// 006d3e4d  50                   push eax
// 006d3e4e  b801000000           mov eax, 1
// 006d3e53  64892500000000       mov dword ptr fs:[0], esp
// 006d3e5a  8405542cb900         test byte ptr [0xb92c54], al
// 006d3e60  752e                 jne 0x6d3e90
// 006d3e62  0905542cb900         or dword ptr [0xb92c54], eax
// 006d3e68  680c24b600           push 0xb6240c
// 006d3e6d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d3e75  e866e4f5ff           call 0x6322e0
// 006d3e7a  83c404               add esp, 4
// 006d3e7d  a3502cb900           mov dword ptr [0xb92c50], eax
// 006d3e82  8b0c24               mov ecx, dword ptr [esp]
// 006d3e85  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3e8c  83c40c               add esp, 0xc
// 006d3e8f  c3                   ret 
// 006d3e90  8b0c24               mov ecx, dword ptr [esp]
// 006d3e93  a1502cb900           mov eax, dword ptr [0xb92c50]
// 006d3e98  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3e9f  83c40c               add esp, 0xc
// 006d3ea2  c3                   ret 

extern char string_00b6240c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b6240c);
    return *name;
}
