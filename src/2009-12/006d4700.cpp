// from server: 100% by nuck16
// roc 2009-12 006d4700  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d4700  64a100000000         mov eax, dword ptr fs:[0]
// 006d4706  6aff                 push -1
// 006d4708  684ea59400           push 0x94a54e
// 006d470d  50                   push eax
// 006d470e  b801000000           mov eax, 1
// 006d4713  64892500000000       mov dword ptr fs:[0], esp
// 006d471a  8405f42cb900         test byte ptr [0xb92cf4], al
// 006d4720  752e                 jne 0x6d4750
// 006d4722  0905f42cb900         or dword ptr [0xb92cf4], eax
// 006d4728  68e831b600           push 0xb631e8
// 006d472d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d4735  e8a6dbf5ff           call 0x6322e0
// 006d473a  83c404               add esp, 4
// 006d473d  a3f02cb900           mov dword ptr [0xb92cf0], eax
// 006d4742  8b0c24               mov ecx, dword ptr [esp]
// 006d4745  64890d00000000       mov dword ptr fs:[0], ecx
// 006d474c  83c40c               add esp, 0xc
// 006d474f  c3                   ret 
// 006d4750  8b0c24               mov ecx, dword ptr [esp]
// 006d4753  a1f02cb900           mov eax, dword ptr [0xb92cf0]
// 006d4758  64890d00000000       mov dword ptr fs:[0], ecx
// 006d475f  83c40c               add esp, 0xc
// 006d4762  c3                   ret 

extern char string_00b631e8[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b631e8);
    return *name;
}
