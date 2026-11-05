// from server: 100% by nuck16
// roc 2009-12 00428ae0  unit: CMainFrame  size: 99 bytes
//
// 00428ae0  64a100000000         mov eax, dword ptr fs:[0]
// 00428ae6  6aff                 push -1
// 00428ae8  681e959200           push 0x92951e
// 00428aed  50                   push eax
// 00428aee  b801000000           mov eax, 1
// 00428af3  64892500000000       mov dword ptr fs:[0], esp
// 00428afa  8405dca2b700         test byte ptr [0xb7a2dc], al
// 00428b00  752e                 jne 0x428b30
// 00428b02  0905dca2b700         or dword ptr [0xb7a2dc], eax
// 00428b08  68e0309d00           push 0x9d30e0
// 00428b0d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00428b15  e8c6972000           call 0x6322e0
// 00428b1a  83c404               add esp, 4
// 00428b1d  a3d8a2b700           mov dword ptr [0xb7a2d8], eax
// 00428b22  8b0c24               mov ecx, dword ptr [esp]
// 00428b25  64890d00000000       mov dword ptr fs:[0], ecx
// 00428b2c  83c40c               add esp, 0xc
// 00428b2f  c3                   ret 
// 00428b30  8b0c24               mov ecx, dword ptr [esp]
// 00428b33  a1d8a2b700           mov eax, dword ptr [0xb7a2d8]
// 00428b38  64890d00000000       mov dword ptr fs:[0], ecx
// 00428b3f  83c40c               add esp, 0xc
// 00428b42  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Accoutrement");
    return *name;
}
