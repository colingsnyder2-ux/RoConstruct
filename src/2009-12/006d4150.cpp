// from server: 100% by nuck16
// roc 2009-12 006d4150  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d4150  64a100000000         mov eax, dword ptr fs:[0]
// 006d4156  6aff                 push -1
// 006d4158  68aea39400           push 0x94a3ae
// 006d415d  50                   push eax
// 006d415e  b801000000           mov eax, 1
// 006d4163  64892500000000       mov dword ptr fs:[0], esp
// 006d416a  84058c2cb900         test byte ptr [0xb92c8c], al
// 006d4170  752e                 jne 0x6d41a0
// 006d4172  09058c2cb900         or dword ptr [0xb92c8c], eax
// 006d4178  684c24b600           push 0xb6244c
// 006d417d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d4185  e856e1f5ff           call 0x6322e0
// 006d418a  83c404               add esp, 4
// 006d418d  a3882cb900           mov dword ptr [0xb92c88], eax
// 006d4192  8b0c24               mov ecx, dword ptr [esp]
// 006d4195  64890d00000000       mov dword ptr fs:[0], ecx
// 006d419c  83c40c               add esp, 0xc
// 006d419f  c3                   ret 
// 006d41a0  8b0c24               mov ecx, dword ptr [esp]
// 006d41a3  a1882cb900           mov eax, dword ptr [0xb92c88]
// 006d41a8  64890d00000000       mov dword ptr fs:[0], ecx
// 006d41af  83c40c               add esp, 0xc
// 006d41b2  c3                   ret 

extern char string_00b6244c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b6244c);
    return *name;
}
