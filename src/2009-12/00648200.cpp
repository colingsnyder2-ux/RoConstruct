// from server: 100% by nuck16
// roc 2009-12 00648200  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648200  64a100000000         mov eax, dword ptr fs:[0]
// 00648206  6aff                 push -1
// 00648208  68de169400           push 0x9416de
// 0064820d  50                   push eax
// 0064820e  b801000000           mov eax, 1
// 00648213  64892500000000       mov dword ptr fs:[0], esp
// 0064821a  8405285eb800         test byte ptr [0xb85e28], al
// 00648220  752e                 jne 0x648250
// 00648222  0905285eb800         or dword ptr [0xb85e28], eax
// 00648228  68d43fb500           push 0xb53fd4
// 0064822d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648235  e8a6a0feff           call 0x6322e0
// 0064823a  83c404               add esp, 4
// 0064823d  a3245eb800           mov dword ptr [0xb85e24], eax
// 00648242  8b0c24               mov ecx, dword ptr [esp]
// 00648245  64890d00000000       mov dword ptr fs:[0], ecx
// 0064824c  83c40c               add esp, 0xc
// 0064824f  c3                   ret 
// 00648250  8b0c24               mov ecx, dword ptr [esp]
// 00648253  a1245eb800           mov eax, dword ptr [0xb85e24]
// 00648258  64890d00000000       mov dword ptr fs:[0], ecx
// 0064825f  83c40c               add esp, 0xc
// 00648262  c3                   ret 

extern char string_00b53fd4[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b53fd4);
    return *name;
}
