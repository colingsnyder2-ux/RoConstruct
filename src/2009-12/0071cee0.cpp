// from server: 100% by nuck16
// roc 2009-12 0071cee0  unit: RBX::Sky  size: 99 bytes
//
// 0071cee0  64a100000000         mov eax, dword ptr fs:[0]
// 0071cee6  6aff                 push -1
// 0071cee8  683ee99400           push 0x94e93e
// 0071ceed  50                   push eax
// 0071ceee  b801000000           mov eax, 1
// 0071cef3  64892500000000       mov dword ptr fs:[0], esp
// 0071cefa  8405e459b900         test byte ptr [0xb959e4], al
// 0071cf00  752e                 jne 0x71cf30
// 0071cf02  0905e459b900         or dword ptr [0xb959e4], eax
// 0071cf08  689cd8b400           push 0xb4d89c
// 0071cf0d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0071cf15  e8c653f1ff           call 0x6322e0
// 0071cf1a  83c404               add esp, 4
// 0071cf1d  a3e059b900           mov dword ptr [0xb959e0], eax
// 0071cf22  8b0c24               mov ecx, dword ptr [esp]
// 0071cf25  64890d00000000       mov dword ptr fs:[0], ecx
// 0071cf2c  83c40c               add esp, 0xc
// 0071cf2f  c3                   ret 
// 0071cf30  8b0c24               mov ecx, dword ptr [esp]
// 0071cf33  a1e059b900           mov eax, dword ptr [0xb959e0]
// 0071cf38  64890d00000000       mov dword ptr fs:[0], ecx
// 0071cf3f  83c40c               add esp, 0xc
// 0071cf42  c3                   ret 

extern char string_00b4d89c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4d89c);
    return *name;
}
