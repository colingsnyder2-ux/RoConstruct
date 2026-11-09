// from server: 100% by nuck16
// roc 2009-12 00648b30  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648b30  64a100000000         mov eax, dword ptr fs:[0]
// 00648b36  6aff                 push -1
// 00648b38  687e199400           push 0x94197e
// 00648b3d  50                   push eax
// 00648b3e  b801000000           mov eax, 1
// 00648b43  64892500000000       mov dword ptr fs:[0], esp
// 00648b4a  8405d05eb800         test byte ptr [0xb85ed0], al
// 00648b50  752e                 jne 0x648b80
// 00648b52  0905d05eb800         or dword ptr [0xb85ed0], eax
// 00648b58  68c0419e00           push 0x9e41c0
// 00648b5d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648b65  e87697feff           call 0x6322e0
// 00648b6a  83c404               add esp, 4
// 00648b6d  a3cc5eb800           mov dword ptr [0xb85ecc], eax
// 00648b72  8b0c24               mov ecx, dword ptr [esp]
// 00648b75  64890d00000000       mov dword ptr fs:[0], ecx
// 00648b7c  83c40c               add esp, 0xc
// 00648b7f  c3                   ret 
// 00648b80  8b0c24               mov ecx, dword ptr [esp]
// 00648b83  a1cc5eb800           mov eax, dword ptr [0xb85ecc]
// 00648b88  64890d00000000       mov dword ptr fs:[0], ecx
// 00648b8f  83c40c               add esp, 0xc
// 00648b92  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("LocalBackpackTool");
    return *name;
}
