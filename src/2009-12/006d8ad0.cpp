// from server: 100% by nuck16
// roc 2009-12 006d8ad0  unit: VProfilingItem::?$BoundFuncDesc  size: 99 bytes
//
// 006d8ad0  64a100000000         mov eax, dword ptr fs:[0]
// 006d8ad6  6aff                 push -1
// 006d8ad8  681eaa9400           push 0x94aa1e
// 006d8add  50                   push eax
// 006d8ade  b801000000           mov eax, 1
// 006d8ae3  64892500000000       mov dword ptr fs:[0], esp
// 006d8aea  84059030b900         test byte ptr [0xb93090], al
// 006d8af0  752e                 jne 0x6d8b20
// 006d8af2  09059030b900         or dword ptr [0xb93090], eax
// 006d8af8  686c919d00           push 0x9d916c
// 006d8afd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d8b05  e8d697f5ff           call 0x6322e0
// 006d8b0a  83c404               add esp, 4
// 006d8b0d  a38c30b900           mov dword ptr [0xb9308c], eax
// 006d8b12  8b0c24               mov ecx, dword ptr [esp]
// 006d8b15  64890d00000000       mov dword ptr fs:[0], ecx
// 006d8b1c  83c40c               add esp, 0xc
// 006d8b1f  c3                   ret 
// 006d8b20  8b0c24               mov ecx, dword ptr [esp]
// 006d8b23  a18c30b900           mov eax, dword ptr [0xb9308c]
// 006d8b28  64890d00000000       mov dword ptr fs:[0], ecx
// 006d8b2f  83c40c               add esp, 0xc
// 006d8b32  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("ProfilingItem");
    return *name;
}
