// from server: 100% by nuck16
// roc 2009-12 006d4230  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d4230  64a100000000         mov eax, dword ptr fs:[0]
// 006d4236  6aff                 push -1
// 006d4238  68eea39400           push 0x94a3ee
// 006d423d  50                   push eax
// 006d423e  b801000000           mov eax, 1
// 006d4243  64892500000000       mov dword ptr fs:[0], esp
// 006d424a  84059c2cb900         test byte ptr [0xb92c9c], al
// 006d4250  752e                 jne 0x6d4280
// 006d4252  09059c2cb900         or dword ptr [0xb92c9c], eax
// 006d4258  686824b600           push 0xb62468
// 006d425d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d4265  e876e0f5ff           call 0x6322e0
// 006d426a  83c404               add esp, 4
// 006d426d  a3982cb900           mov dword ptr [0xb92c98], eax
// 006d4272  8b0c24               mov ecx, dword ptr [esp]
// 006d4275  64890d00000000       mov dword ptr fs:[0], ecx
// 006d427c  83c40c               add esp, 0xc
// 006d427f  c3                   ret 
// 006d4280  8b0c24               mov ecx, dword ptr [esp]
// 006d4283  a1982cb900           mov eax, dword ptr [0xb92c98]
// 006d4288  64890d00000000       mov dword ptr fs:[0], ecx
// 006d428f  83c40c               add esp, 0xc
// 006d4292  c3                   ret 

extern char string_00b62468[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b62468);
    return *name;
}
