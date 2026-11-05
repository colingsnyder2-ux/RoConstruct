// from server: 100% by Yeetserama
// roc 2010-06 0042eb90  unit: CMemberTreeView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042eb90
//
// 0042eb90  6aff                 push -1
// 0042eb92  68da209800           push 0x9820da
// 0042eb97  64a100000000         mov eax, dword ptr fs:[0]
// 0042eb9d  50                   push eax
// 0042eb9e  64892500000000       mov dword ptr fs:[0], esp
// 0042eba5  51                   push ecx
// 0042eba6  68b0000000           push 0xb0
// 0042ebab  e8f08d3700           call 0x7a79a0
// 0042ebb0  83c404               add esp, 4
// 0042ebb3  890424               mov dword ptr [esp], eax
// 0042ebb6  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0042ebbe  85c0                 test eax, eax
// 0042ebc0  7416                 je 0x42ebd8
// 0042ebc2  8bc8                 mov ecx, eax
// 0042ebc4  e8a7f9ffff           call 0x42e570
// 0042ebc9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042ebcd  64890d00000000       mov dword ptr fs:[0], ecx
// 0042ebd4  83c410               add esp, 0x10
// 0042ebd7  c3                   ret 
// 0042ebd8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042ebdc  33c0                 xor eax, eax
// 0042ebde  64890d00000000       mov dword ptr fs:[0], ecx
// 0042ebe5  83c410               add esp, 0x10
// 0042ebe8  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000000_00433fc0@@YAPAUS@@XZ)

// from server: 100% by king_originala
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