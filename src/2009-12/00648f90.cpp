// from server: 100% by nuck16
// roc 2009-12 00648f90  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648f90  64a100000000         mov eax, dword ptr fs:[0]
// 00648f96  6aff                 push -1
// 00648f98  68be1a9400           push 0x941abe
// 00648f9d  50                   push eax
// 00648f9e  b801000000           mov eax, 1
// 00648fa3  64892500000000       mov dword ptr fs:[0], esp
// 00648faa  8405205fb800         test byte ptr [0xb85f20], al
// 00648fb0  752e                 jne 0x648fe0
// 00648fb2  0905205fb800         or dword ptr [0xb85f20], eax
// 00648fb8  68f0a3b500           push 0xb5a3f0
// 00648fbd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648fc5  e81693feff           call 0x6322e0
// 00648fca  83c404               add esp, 4
// 00648fcd  a31c5fb800           mov dword ptr [0xb85f1c], eax
// 00648fd2  8b0c24               mov ecx, dword ptr [esp]
// 00648fd5  64890d00000000       mov dword ptr fs:[0], ecx
// 00648fdc  83c40c               add esp, 0xc
// 00648fdf  c3                   ret 
// 00648fe0  8b0c24               mov ecx, dword ptr [esp]
// 00648fe3  a11c5fb800           mov eax, dword ptr [0xb85f1c]
// 00648fe8  64890d00000000       mov dword ptr fs:[0], ecx
// 00648fef  83c40c               add esp, 0xc
// 00648ff2  c3                   ret 

extern char string_00b5a3f0[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5a3f0);
    return *name;
}
