// from server: 100% by Yeetserama
// roc 2011-06 00484a90  unit: CRobloxView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00484a90
//
// 00484a90  6aff                 push -1
// 00484a92  68aa639d00           push 0x9d63aa
// 00484a97  64a100000000         mov eax, dword ptr fs:[0]
// 00484a9d  50                   push eax
// 00484a9e  64892500000000       mov dword ptr fs:[0], esp
// 00484aa5  51                   push ecx
// 00484aa6  68f0010000           push 0x1f0
// 00484aab  e8ae553800           call 0x80a05e
// 00484ab0  83c404               add esp, 4
// 00484ab3  890424               mov dword ptr [esp], eax
// 00484ab6  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00484abe  85c0                 test eax, eax
// 00484ac0  7416                 je 0x484ad8
// 00484ac2  8bc8                 mov ecx, eax
// 00484ac4  e887faffff           call 0x484550
// 00484ac9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00484acd  64890d00000000       mov dword ptr fs:[0], ecx
// 00484ad4  83c410               add esp, 0x10
// 00484ad7  c3                   ret 
// 00484ad8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00484adc  33c0                 xor eax, eax
// 00484ade  64890d00000000       mov dword ptr fs:[0], ecx
// 00484ae5  83c410               add esp, 0x10
// 00484ae8  c3                   ret 
// copied from an identical function in another client (function ?f@@YAPAUS@@XZ)

// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S
{
    char storage[0x1f0];
    S();
};

S* __cdecl f()
{
    return new S;
}