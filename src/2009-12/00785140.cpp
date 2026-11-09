// from server: 100% by nuck16
// roc 2009-12 00785140  unit: RBX::ToolMouseCommand  size: 99 bytes
//
// 00785140  64a100000000         mov eax, dword ptr fs:[0]
// 00785146  6aff                 push -1
// 00785148  68de399500           push 0x9539de
// 0078514d  50                   push eax
// 0078514e  b801000000           mov eax, 1
// 00785153  64892500000000       mov dword ptr fs:[0], esp
// 0078515a  84057488b900         test byte ptr [0xb98874], al
// 00785160  752e                 jne 0x785190
// 00785162  09057488b900         or dword ptr [0xb98874], eax
// 00785168  68d820b600           push 0xb620d8
// 0078516d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00785175  e866d1eaff           call 0x6322e0
// 0078517a  83c404               add esp, 4
// 0078517d  a37088b900           mov dword ptr [0xb98870], eax
// 00785182  8b0c24               mov ecx, dword ptr [esp]
// 00785185  64890d00000000       mov dword ptr fs:[0], ecx
// 0078518c  83c40c               add esp, 0xc
// 0078518f  c3                   ret 
// 00785190  8b0c24               mov ecx, dword ptr [esp]
// 00785193  a17088b900           mov eax, dword ptr [0xb98870]
// 00785198  64890d00000000       mov dword ptr fs:[0], ecx
// 0078519f  83c40c               add esp, 0xc
// 007851a2  c3                   ret 

extern char string_00b620d8[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b620d8);
    return *name;
}
