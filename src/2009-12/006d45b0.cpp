// from server: 100% by nuck16
// roc 2009-12 006d45b0  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d45b0  64a100000000         mov eax, dword ptr fs:[0]
// 006d45b6  6aff                 push -1
// 006d45b8  68eea49400           push 0x94a4ee
// 006d45bd  50                   push eax
// 006d45be  b801000000           mov eax, 1
// 006d45c3  64892500000000       mov dword ptr fs:[0], esp
// 006d45ca  8405dc2cb900         test byte ptr [0xb92cdc], al
// 006d45d0  752e                 jne 0x6d4600
// 006d45d2  0905dc2cb900         or dword ptr [0xb92cdc], eax
// 006d45d8  684831b600           push 0xb63148
// 006d45dd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d45e5  e8f6dcf5ff           call 0x6322e0
// 006d45ea  83c404               add esp, 4
// 006d45ed  a3d82cb900           mov dword ptr [0xb92cd8], eax
// 006d45f2  8b0c24               mov ecx, dword ptr [esp]
// 006d45f5  64890d00000000       mov dword ptr fs:[0], ecx
// 006d45fc  83c40c               add esp, 0xc
// 006d45ff  c3                   ret 
// 006d4600  8b0c24               mov ecx, dword ptr [esp]
// 006d4603  a1d82cb900           mov eax, dword ptr [0xb92cd8]
// 006d4608  64890d00000000       mov dword ptr fs:[0], ecx
// 006d460f  83c40c               add esp, 0xc
// 006d4612  c3                   ret 

extern char string_00b63148[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b63148);
    return *name;
}
