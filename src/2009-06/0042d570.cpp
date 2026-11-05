// from server: 100% by EspClaude
// roc 2009-06 0042d570  unit: CMemberTreeView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042d570
//
// 0042d570  6aff                 push -1
// 0042d572  687aef8400           push 0x84ef7a
// 0042d577  64a100000000         mov eax, dword ptr fs:[0]
// 0042d57d  50                   push eax
// 0042d57e  64892500000000       mov dword ptr fs:[0], esp
// 0042d585  51                   push ecx
// 0042d586  68b0000000           push 0xb0
// 0042d58b  e8a8b42e00           call 0x718a38
// 0042d590  83c404               add esp, 4
// 0042d593  890424               mov dword ptr [esp], eax
// 0042d596  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0042d59e  85c0                 test eax, eax
// 0042d5a0  7416                 je 0x42d5b8
// 0042d5a2  8bc8                 mov ecx, eax
// 0042d5a4  e8a7f9ffff           call 0x42cf50
// 0042d5a9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042d5ad  64890d00000000       mov dword ptr fs:[0], ecx
// 0042d5b4  83c410               add esp, 0x10
// 0042d5b7  c3                   ret 
// 0042d5b8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042d5bc  33c0                 xor eax, eax
// 0042d5be  64890d00000000       mov dword ptr fs:[0], ecx
// 0042d5c5  83c410               add esp, 0x10
// 0042d5c8  c3                   ret 
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