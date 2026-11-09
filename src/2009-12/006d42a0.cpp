// from server: 100% by nuck16
// roc 2009-12 006d42a0  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d42a0  64a100000000         mov eax, dword ptr fs:[0]
// 006d42a6  6aff                 push -1
// 006d42a8  680ea49400           push 0x94a40e
// 006d42ad  50                   push eax
// 006d42ae  b801000000           mov eax, 1
// 006d42b3  64892500000000       mov dword ptr fs:[0], esp
// 006d42ba  8405a42cb900         test byte ptr [0xb92ca4], al
// 006d42c0  752e                 jne 0x6d42f0
// 006d42c2  0905a42cb900         or dword ptr [0xb92ca4], eax
// 006d42c8  68f830b600           push 0xb630f8
// 006d42cd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d42d5  e806e0f5ff           call 0x6322e0
// 006d42da  83c404               add esp, 4
// 006d42dd  a3a02cb900           mov dword ptr [0xb92ca0], eax
// 006d42e2  8b0c24               mov ecx, dword ptr [esp]
// 006d42e5  64890d00000000       mov dword ptr fs:[0], ecx
// 006d42ec  83c40c               add esp, 0xc
// 006d42ef  c3                   ret 
// 006d42f0  8b0c24               mov ecx, dword ptr [esp]
// 006d42f3  a1a02cb900           mov eax, dword ptr [0xb92ca0]
// 006d42f8  64890d00000000       mov dword ptr fs:[0], ecx
// 006d42ff  83c40c               add esp, 0xc
// 006d4302  c3                   ret 

extern char string_00b630f8[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b630f8);
    return *name;
}
