// from server: 100% by nuck16
// roc 2009-12 00454f00  unit: VCWorkspace::?$CComObject  size: 99 bytes
//
// 00454f00  64a100000000         mov eax, dword ptr fs:[0]
// 00454f06  6aff                 push -1
// 00454f08  685eb69200           push 0x92b65e
// 00454f0d  50                   push eax
// 00454f0e  b801000000           mov eax, 1
// 00454f13  64892500000000       mov dword ptr fs:[0], esp
// 00454f1a  8405d4b7b700         test byte ptr [0xb7b7d4], al
// 00454f20  752e                 jne 0x454f50
// 00454f22  0905d4b7b700         or dword ptr [0xb7b7d4], eax
// 00454f28  685cbfb300           push 0xb3bf5c
// 00454f2d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00454f35  e8a6d31d00           call 0x6322e0
// 00454f3a  83c404               add esp, 4
// 00454f3d  a3d0b7b700           mov dword ptr [0xb7b7d0], eax
// 00454f42  8b0c24               mov ecx, dword ptr [esp]
// 00454f45  64890d00000000       mov dword ptr fs:[0], ecx
// 00454f4c  83c40c               add esp, 0xc
// 00454f4f  c3                   ret 
// 00454f50  8b0c24               mov ecx, dword ptr [esp]
// 00454f53  a1d0b7b700           mov eax, dword ptr [0xb7b7d0]
// 00454f58  64890d00000000       mov dword ptr fs:[0], ecx
// 00454f5f  83c40c               add esp, 0xc
// 00454f62  c3                   ret 

extern char string_00b3bf5c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3bf5c);
    return *name;
}
