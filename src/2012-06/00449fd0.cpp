// from server: 100% by Xemicl
// roc 2012-06 00449fd0  unit: CMemberTreeView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00449fd0
//
// 00449fd0  6aff                 push -1
// 00449fd2  686a21aa00           push 0xaa216a
// 00449fd7  64a100000000         mov eax, dword ptr fs:[0]
// 00449fdd  50                   push eax
// 00449fde  64892500000000       mov dword ptr fs:[0], esp
// 00449fe5  51                   push ecx
// 00449fe6  68b0000000           push 0xb0
// 00449feb  e82a815300           call 0x98211a
// 00449ff0  83c404               add esp, 4
// 00449ff3  890424               mov dword ptr [esp], eax
// 00449ff6  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00449ffe  85c0                 test eax, eax
// 0044a000  7416                 je 0x44a018
// 0044a002  8bc8                 mov ecx, eax
// 0044a004  e8c7faffff           call 0x449ad0
// 0044a009  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044a00d  64890d00000000       mov dword ptr fs:[0], ecx
// 0044a014  83c410               add esp, 0x10
// 0044a017  c3                   ret 
// 0044a018  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044a01c  33c0                 xor eax, eax
// 0044a01e  64890d00000000       mov dword ptr fs:[0], ecx
// 0044a025  83c410               add esp, 0x10
// 0044a028  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000000_00433fc0@@YAPAUS@@XZ)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S
{
    char storage[0xB0];
    S();
};

S* func_00433fc0()
{
    return new S;
}