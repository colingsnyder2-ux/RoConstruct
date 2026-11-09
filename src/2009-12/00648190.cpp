// from server: 100% by nuck16
// roc 2009-12 00648190  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648190  64a100000000         mov eax, dword ptr fs:[0]
// 00648196  6aff                 push -1
// 00648198  68be169400           push 0x9416be
// 0064819d  50                   push eax
// 0064819e  b801000000           mov eax, 1
// 006481a3  64892500000000       mov dword ptr fs:[0], esp
// 006481aa  8405205eb800         test byte ptr [0xb85e20], al
// 006481b0  752e                 jne 0x6481e0
// 006481b2  0905205eb800         or dword ptr [0xb85e20], eax
// 006481b8  68d83bb500           push 0xb53bd8
// 006481bd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006481c5  e816a1feff           call 0x6322e0
// 006481ca  83c404               add esp, 4
// 006481cd  a31c5eb800           mov dword ptr [0xb85e1c], eax
// 006481d2  8b0c24               mov ecx, dword ptr [esp]
// 006481d5  64890d00000000       mov dword ptr fs:[0], ecx
// 006481dc  83c40c               add esp, 0xc
// 006481df  c3                   ret 
// 006481e0  8b0c24               mov ecx, dword ptr [esp]
// 006481e3  a11c5eb800           mov eax, dword ptr [0xb85e1c]
// 006481e8  64890d00000000       mov dword ptr fs:[0], ecx
// 006481ef  83c40c               add esp, 0xc
// 006481f2  c3                   ret 

extern char string_00b53bd8[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b53bd8);
    return *name;
}
