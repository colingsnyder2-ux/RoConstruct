// from server: 100% by nuck16
// roc 2009-12 006d43f0  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d43f0  64a100000000         mov eax, dword ptr fs:[0]
// 006d43f6  6aff                 push -1
// 006d43f8  686ea49400           push 0x94a46e
// 006d43fd  50                   push eax
// 006d43fe  b801000000           mov eax, 1
// 006d4403  64892500000000       mov dword ptr fs:[0], esp
// 006d440a  8405bc2cb900         test byte ptr [0xb92cbc], al
// 006d4410  752e                 jne 0x6d4440
// 006d4412  0905bc2cb900         or dword ptr [0xb92cbc], eax
// 006d4418  681831b600           push 0xb63118
// 006d441d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d4425  e8b6def5ff           call 0x6322e0
// 006d442a  83c404               add esp, 4
// 006d442d  a3b82cb900           mov dword ptr [0xb92cb8], eax
// 006d4432  8b0c24               mov ecx, dword ptr [esp]
// 006d4435  64890d00000000       mov dword ptr fs:[0], ecx
// 006d443c  83c40c               add esp, 0xc
// 006d443f  c3                   ret 
// 006d4440  8b0c24               mov ecx, dword ptr [esp]
// 006d4443  a1b82cb900           mov eax, dword ptr [0xb92cb8]
// 006d4448  64890d00000000       mov dword ptr fs:[0], ecx
// 006d444f  83c40c               add esp, 0xc
// 006d4452  c3                   ret 

extern char string_00b63118[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b63118);
    return *name;
}
