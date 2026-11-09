// from server: 100% by Yeetserama
// roc 2007-08 00434d60  unit: CMemberTreeView  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434d60
//
// 00434d60  6aff                 push -1
// 00434d62  68eaf27500           push 0x75f2ea
// 00434d67  64a100000000         mov eax, dword ptr fs:[0]
// 00434d6d  50                   push eax
// 00434d6e  51                   push ecx
// 00434d6f  a188518b00           mov eax, dword ptr [0x8b5188]
// 00434d74  33c4                 xor eax, esp
// 00434d76  50                   push eax
// 00434d77  8d442408             lea eax, [esp + 8]
// 00434d7b  64a300000000         mov dword ptr fs:[0], eax
// 00434d81  68b0000000           push 0xb0
// 00434d86  e86bb11f00           call 0x62fef6
// 00434d8b  83c404               add esp, 4
// 00434d8e  89442404             mov dword ptr [esp + 4], eax
// 00434d92  85c0                 test eax, eax
// 00434d94  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00434d9c  7417                 je 0x434db5
// 00434d9e  8bc8                 mov ecx, eax
// 00434da0  e8cbf8ffff           call 0x434670
// 00434da5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00434da9  64890d00000000       mov dword ptr fs:[0], ecx
// 00434db0  59                   pop ecx
// 00434db1  83c410               add esp, 0x10
// 00434db4  c3                   ret 
// 00434db5  33c0                 xor eax, eax
// 00434db7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00434dbb  64890d00000000       mov dword ptr fs:[0], ecx
// 00434dc2  59                   pop ecx
// 00434dc3  83c410               add esp, 0x10
// 00434dc6  c3                   ret 
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