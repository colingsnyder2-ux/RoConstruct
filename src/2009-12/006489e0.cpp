// from server: 100% by nuck16
// roc 2009-12 006489e0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006489e0  64a100000000         mov eax, dword ptr fs:[0]
// 006489e6  6aff                 push -1
// 006489e8  681e199400           push 0x94191e
// 006489ed  50                   push eax
// 006489ee  b801000000           mov eax, 1
// 006489f3  64892500000000       mov dword ptr fs:[0], esp
// 006489fa  8405b85eb800         test byte ptr [0xb85eb8], al
// 00648a00  752e                 jne 0x648a30
// 00648a02  0905b85eb800         or dword ptr [0xb85eb8], eax
// 00648a08  68681fb500           push 0xb51f68
// 00648a0d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648a15  e8c698feff           call 0x6322e0
// 00648a1a  83c404               add esp, 4
// 00648a1d  a3b45eb800           mov dword ptr [0xb85eb4], eax
// 00648a22  8b0c24               mov ecx, dword ptr [esp]
// 00648a25  64890d00000000       mov dword ptr fs:[0], ecx
// 00648a2c  83c40c               add esp, 0xc
// 00648a2f  c3                   ret 
// 00648a30  8b0c24               mov ecx, dword ptr [esp]
// 00648a33  a1b45eb800           mov eax, dword ptr [0xb85eb4]
// 00648a38  64890d00000000       mov dword ptr fs:[0], ecx
// 00648a3f  83c40c               add esp, 0xc
// 00648a42  c3                   ret 

extern char string_00b51f68[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b51f68);
    return *name;
}
