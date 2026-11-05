// from server: 100% by nuck16
// roc 2009-12 00512ad0  unit: RBX::Network::Players  size: 99 bytes
//
// 00512ad0  64a100000000         mov eax, dword ptr fs:[0]
// 00512ad6  6aff                 push -1
// 00512ad8  68de759300           push 0x9375de
// 00512add  50                   push eax
// 00512ade  b801000000           mov eax, 1
// 00512ae3  64892500000000       mov dword ptr fs:[0], esp
// 00512aea  8405e8e8b700         test byte ptr [0xb7e8e8], al
// 00512af0  752e                 jne 0x512b20
// 00512af2  0905e8e8b700         or dword ptr [0xb7e8e8], eax
// 00512af8  688ccbb100           push 0xb1cb8c
// 00512afd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00512b05  e8d6f71100           call 0x6322e0
// 00512b0a  83c404               add esp, 4
// 00512b0d  a3e4e8b700           mov dword ptr [0xb7e8e4], eax
// 00512b12  8b0c24               mov ecx, dword ptr [esp]
// 00512b15  64890d00000000       mov dword ptr fs:[0], ecx
// 00512b1c  83c40c               add esp, 0xc
// 00512b1f  c3                   ret 
// 00512b20  8b0c24               mov ecx, dword ptr [esp]
// 00512b23  a1e4e8b700           mov eax, dword ptr [0xb7e8e4]
// 00512b28  64890d00000000       mov dword ptr fs:[0], ecx
// 00512b2f  83c40c               add esp, 0xc
// 00512b32  c3                   ret 

extern char string_00b1cb8c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b1cb8c);
    return *name;
}
