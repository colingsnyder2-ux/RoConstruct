// from server: 100% by nuck16
// roc 2009-12 006486d0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006486d0  64a100000000         mov eax, dword ptr fs:[0]
// 006486d6  6aff                 push -1
// 006486d8  683e189400           push 0x94183e
// 006486dd  50                   push eax
// 006486de  b801000000           mov eax, 1
// 006486e3  64892500000000       mov dword ptr fs:[0], esp
// 006486ea  8405805eb800         test byte ptr [0xb85e80], al
// 006486f0  752e                 jne 0x648720
// 006486f2  0905805eb800         or dword ptr [0xb85e80], eax
// 006486f8  68bc66b500           push 0xb566bc
// 006486fd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648705  e8d69bfeff           call 0x6322e0
// 0064870a  83c404               add esp, 4
// 0064870d  a37c5eb800           mov dword ptr [0xb85e7c], eax
// 00648712  8b0c24               mov ecx, dword ptr [esp]
// 00648715  64890d00000000       mov dword ptr fs:[0], ecx
// 0064871c  83c40c               add esp, 0xc
// 0064871f  c3                   ret 
// 00648720  8b0c24               mov ecx, dword ptr [esp]
// 00648723  a17c5eb800           mov eax, dword ptr [0xb85e7c]
// 00648728  64890d00000000       mov dword ptr fs:[0], ecx
// 0064872f  83c40c               add esp, 0xc
// 00648732  c3                   ret 

extern char string_00b566bc[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b566bc);
    return *name;
}
