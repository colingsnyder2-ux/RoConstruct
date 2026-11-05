// from server: 100% by nuck16
// roc 2009-12 00512b40  unit: RBX::Network::Players  size: 99 bytes
//
// 00512b40  64a100000000         mov eax, dword ptr fs:[0]
// 00512b46  6aff                 push -1
// 00512b48  68fe759300           push 0x9375fe
// 00512b4d  50                   push eax
// 00512b4e  b801000000           mov eax, 1
// 00512b53  64892500000000       mov dword ptr fs:[0], esp
// 00512b5a  8405f0e8b700         test byte ptr [0xb7e8f0], al
// 00512b60  752e                 jne 0x512b90
// 00512b62  0905f0e8b700         or dword ptr [0xb7e8f0], eax
// 00512b68  68d0bdb100           push 0xb1bdd0
// 00512b6d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00512b75  e866f71100           call 0x6322e0
// 00512b7a  83c404               add esp, 4
// 00512b7d  a3ece8b700           mov dword ptr [0xb7e8ec], eax
// 00512b82  8b0c24               mov ecx, dword ptr [esp]
// 00512b85  64890d00000000       mov dword ptr fs:[0], ecx
// 00512b8c  83c40c               add esp, 0xc
// 00512b8f  c3                   ret 
// 00512b90  8b0c24               mov ecx, dword ptr [esp]
// 00512b93  a1ece8b700           mov eax, dword ptr [0xb7e8ec]
// 00512b98  64890d00000000       mov dword ptr fs:[0], ecx
// 00512b9f  83c40c               add esp, 0xc
// 00512ba2  c3                   ret 

extern char string_00b1bdd0[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b1bdd0);
    return *name;
}
