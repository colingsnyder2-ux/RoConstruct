// from server: 100% by nuck16
// roc 2009-12 00648c10  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648c10  64a100000000         mov eax, dword ptr fs:[0]
// 00648c16  6aff                 push -1
// 00648c18  68be199400           push 0x9419be
// 00648c1d  50                   push eax
// 00648c1e  b801000000           mov eax, 1
// 00648c23  64892500000000       mov dword ptr fs:[0], esp
// 00648c2a  8405e05eb800         test byte ptr [0xb85ee0], al
// 00648c30  752e                 jne 0x648c60
// 00648c32  0905e05eb800         or dword ptr [0xb85ee0], eax
// 00648c38  68ec419e00           push 0x9e41ec
// 00648c3d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648c45  e89696feff           call 0x6322e0
// 00648c4a  83c404               add esp, 4
// 00648c4d  a3dc5eb800           mov dword ptr [0xb85edc], eax
// 00648c52  8b0c24               mov ecx, dword ptr [esp]
// 00648c55  64890d00000000       mov dword ptr fs:[0], ecx
// 00648c5c  83c40c               add esp, 0xc
// 00648c5f  c3                   ret 
// 00648c60  8b0c24               mov ecx, dword ptr [esp]
// 00648c63  a1dc5eb800           mov eax, dword ptr [0xb85edc]
// 00648c68  64890d00000000       mov dword ptr fs:[0], ecx
// 00648c6f  83c40c               add esp, 0xc
// 00648c72  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("LocalBackpack");
    return *name;
}
