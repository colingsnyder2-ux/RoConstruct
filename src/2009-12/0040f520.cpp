// from server: 100% by nuck16
// roc 2009-12 0040f520  unit: CChatPrompt  size: 99 bytes
//
// 0040f520  64a100000000         mov eax, dword ptr fs:[0]
// 0040f526  6aff                 push -1
// 0040f528  689e7a9200           push 0x927a9e
// 0040f52d  50                   push eax
// 0040f52e  b801000000           mov eax, 1
// 0040f533  64892500000000       mov dword ptr fs:[0], esp
// 0040f53a  8405b0a0b700         test byte ptr [0xb7a0b0], al
// 0040f540  752e                 jne 0x40f570
// 0040f542  0905b0a0b700         or dword ptr [0xb7a0b0], eax
// 0040f548  68b87fb100           push 0xb17fb8
// 0040f54d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0040f555  e8862d2200           call 0x6322e0
// 0040f55a  83c404               add esp, 4
// 0040f55d  a3aca0b700           mov dword ptr [0xb7a0ac], eax
// 0040f562  8b0c24               mov ecx, dword ptr [esp]
// 0040f565  64890d00000000       mov dword ptr fs:[0], ecx
// 0040f56c  83c40c               add esp, 0xc
// 0040f56f  c3                   ret 
// 0040f570  8b0c24               mov ecx, dword ptr [esp]
// 0040f573  a1aca0b700           mov eax, dword ptr [0xb7a0ac]
// 0040f578  64890d00000000       mov dword ptr fs:[0], ecx
// 0040f57f  83c40c               add esp, 0xc
// 0040f582  c3                   ret 

extern char string_00b17fb8[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b17fb8);
    return *name;
}
