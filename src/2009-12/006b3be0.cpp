// from server: 100% by nuck16
// roc 2009-12 006b3be0  unit: RBX::DropperTool  size: 99 bytes
//
// 006b3be0  64a100000000         mov eax, dword ptr fs:[0]
// 006b3be6  6aff                 push -1
// 006b3be8  68de849400           push 0x9484de
// 006b3bed  50                   push eax
// 006b3bee  b801000000           mov eax, 1
// 006b3bf3  64892500000000       mov dword ptr fs:[0], esp
// 006b3bfa  84059c1cb900         test byte ptr [0xb91c9c], al
// 006b3c00  752e                 jne 0x6b3c30
// 006b3c02  09059c1cb900         or dword ptr [0xb91c9c], eax
// 006b3c08  685ca7b300           push 0xb3a75c
// 006b3c0d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006b3c15  e8c6e6f7ff           call 0x6322e0
// 006b3c1a  83c404               add esp, 4
// 006b3c1d  a3981cb900           mov dword ptr [0xb91c98], eax
// 006b3c22  8b0c24               mov ecx, dword ptr [esp]
// 006b3c25  64890d00000000       mov dword ptr fs:[0], ecx
// 006b3c2c  83c40c               add esp, 0xc
// 006b3c2f  c3                   ret 
// 006b3c30  8b0c24               mov ecx, dword ptr [esp]
// 006b3c33  a1981cb900           mov eax, dword ptr [0xb91c98]
// 006b3c38  64890d00000000       mov dword ptr fs:[0], ecx
// 006b3c3f  83c40c               add esp, 0xc
// 006b3c42  c3                   ret 

extern char string_00b3a75c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3a75c);
    return *name;
}
