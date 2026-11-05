// from server: 100% by nuck16
// roc 2009-12 006d4380  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d4380  64a100000000         mov eax, dword ptr fs:[0]
// 006d4386  6aff                 push -1
// 006d4388  684ea49400           push 0x94a44e
// 006d438d  50                   push eax
// 006d438e  b801000000           mov eax, 1
// 006d4393  64892500000000       mov dword ptr fs:[0], esp
// 006d439a  8405b42cb900         test byte ptr [0xb92cb4], al
// 006d43a0  752e                 jne 0x6d43d0
// 006d43a2  0905b42cb900         or dword ptr [0xb92cb4], eax
// 006d43a8  680c31b600           push 0xb6310c
// 006d43ad  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d43b5  e826dff5ff           call 0x6322e0
// 006d43ba  83c404               add esp, 4
// 006d43bd  a3b02cb900           mov dword ptr [0xb92cb0], eax
// 006d43c2  8b0c24               mov ecx, dword ptr [esp]
// 006d43c5  64890d00000000       mov dword ptr fs:[0], ecx
// 006d43cc  83c40c               add esp, 0xc
// 006d43cf  c3                   ret 
// 006d43d0  8b0c24               mov ecx, dword ptr [esp]
// 006d43d3  a1b02cb900           mov eax, dword ptr [0xb92cb0]
// 006d43d8  64890d00000000       mov dword ptr fs:[0], ecx
// 006d43df  83c40c               add esp, 0xc
// 006d43e2  c3                   ret 

extern char string_00b6310c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b6310c);
    return *name;
}
