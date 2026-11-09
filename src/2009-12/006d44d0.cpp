// from server: 100% by nuck16
// roc 2009-12 006d44d0  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d44d0  64a100000000         mov eax, dword ptr fs:[0]
// 006d44d6  6aff                 push -1
// 006d44d8  68aea49400           push 0x94a4ae
// 006d44dd  50                   push eax
// 006d44de  b801000000           mov eax, 1
// 006d44e3  64892500000000       mov dword ptr fs:[0], esp
// 006d44ea  8405cc2cb900         test byte ptr [0xb92ccc], al
// 006d44f0  752e                 jne 0x6d4520
// 006d44f2  0905cc2cb900         or dword ptr [0xb92ccc], eax
// 006d44f8  683031b600           push 0xb63130
// 006d44fd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d4505  e8d6ddf5ff           call 0x6322e0
// 006d450a  83c404               add esp, 4
// 006d450d  a3c82cb900           mov dword ptr [0xb92cc8], eax
// 006d4512  8b0c24               mov ecx, dword ptr [esp]
// 006d4515  64890d00000000       mov dword ptr fs:[0], ecx
// 006d451c  83c40c               add esp, 0xc
// 006d451f  c3                   ret 
// 006d4520  8b0c24               mov ecx, dword ptr [esp]
// 006d4523  a1c82cb900           mov eax, dword ptr [0xb92cc8]
// 006d4528  64890d00000000       mov dword ptr fs:[0], ecx
// 006d452f  83c40c               add esp, 0xc
// 006d4532  c3                   ret 

extern char string_00b63130[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b63130);
    return *name;
}
