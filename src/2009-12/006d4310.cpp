// from server: 100% by nuck16
// roc 2009-12 006d4310  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d4310  64a100000000         mov eax, dword ptr fs:[0]
// 006d4316  6aff                 push -1
// 006d4318  682ea49400           push 0x94a42e
// 006d431d  50                   push eax
// 006d431e  b801000000           mov eax, 1
// 006d4323  64892500000000       mov dword ptr fs:[0], esp
// 006d432a  8405ac2cb900         test byte ptr [0xb92cac], al
// 006d4330  752e                 jne 0x6d4360
// 006d4332  0905ac2cb900         or dword ptr [0xb92cac], eax
// 006d4338  680031b600           push 0xb63100
// 006d433d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d4345  e896dff5ff           call 0x6322e0
// 006d434a  83c404               add esp, 4
// 006d434d  a3a82cb900           mov dword ptr [0xb92ca8], eax
// 006d4352  8b0c24               mov ecx, dword ptr [esp]
// 006d4355  64890d00000000       mov dword ptr fs:[0], ecx
// 006d435c  83c40c               add esp, 0xc
// 006d435f  c3                   ret 
// 006d4360  8b0c24               mov ecx, dword ptr [esp]
// 006d4363  a1a82cb900           mov eax, dword ptr [0xb92ca8]
// 006d4368  64890d00000000       mov dword ptr fs:[0], ecx
// 006d436f  83c40c               add esp, 0xc
// 006d4372  c3                   ret 

extern char string_00b63100[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b63100);
    return *name;
}
