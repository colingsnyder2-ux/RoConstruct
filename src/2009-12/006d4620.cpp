// from server: 100% by nuck16
// roc 2009-12 006d4620  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d4620  64a100000000         mov eax, dword ptr fs:[0]
// 006d4626  6aff                 push -1
// 006d4628  680ea59400           push 0x94a50e
// 006d462d  50                   push eax
// 006d462e  b801000000           mov eax, 1
// 006d4633  64892500000000       mov dword ptr fs:[0], esp
// 006d463a  8405e42cb900         test byte ptr [0xb92ce4], al
// 006d4640  752e                 jne 0x6d4670
// 006d4642  0905e42cb900         or dword ptr [0xb92ce4], eax
// 006d4648  689831b600           push 0xb63198
// 006d464d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d4655  e886dcf5ff           call 0x6322e0
// 006d465a  83c404               add esp, 4
// 006d465d  a3e02cb900           mov dword ptr [0xb92ce0], eax
// 006d4662  8b0c24               mov ecx, dword ptr [esp]
// 006d4665  64890d00000000       mov dword ptr fs:[0], ecx
// 006d466c  83c40c               add esp, 0xc
// 006d466f  c3                   ret 
// 006d4670  8b0c24               mov ecx, dword ptr [esp]
// 006d4673  a1e02cb900           mov eax, dword ptr [0xb92ce0]
// 006d4678  64890d00000000       mov dword ptr fs:[0], ecx
// 006d467f  83c40c               add esp, 0xc
// 006d4682  c3                   ret 

extern char string_00b63198[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b63198);
    return *name;
}
