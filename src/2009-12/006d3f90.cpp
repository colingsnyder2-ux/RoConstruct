// from server: 100% by nuck16
// roc 2009-12 006d3f90  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d3f90  64a100000000         mov eax, dword ptr fs:[0]
// 006d3f96  6aff                 push -1
// 006d3f98  682ea39400           push 0x94a32e
// 006d3f9d  50                   push eax
// 006d3f9e  b801000000           mov eax, 1
// 006d3fa3  64892500000000       mov dword ptr fs:[0], esp
// 006d3faa  84056c2cb900         test byte ptr [0xb92c6c], al
// 006d3fb0  752e                 jne 0x6d3fe0
// 006d3fb2  09056c2cb900         or dword ptr [0xb92c6c], eax
// 006d3fb8  682424b600           push 0xb62424
// 006d3fbd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d3fc5  e816e3f5ff           call 0x6322e0
// 006d3fca  83c404               add esp, 4
// 006d3fcd  a3682cb900           mov dword ptr [0xb92c68], eax
// 006d3fd2  8b0c24               mov ecx, dword ptr [esp]
// 006d3fd5  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3fdc  83c40c               add esp, 0xc
// 006d3fdf  c3                   ret 
// 006d3fe0  8b0c24               mov ecx, dword ptr [esp]
// 006d3fe3  a1682cb900           mov eax, dword ptr [0xb92c68]
// 006d3fe8  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3fef  83c40c               add esp, 0xc
// 006d3ff2  c3                   ret 

extern char string_00b62424[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b62424);
    return *name;
}
