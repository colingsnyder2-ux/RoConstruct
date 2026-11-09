// from server: 100% by nuck16
// roc 2009-12 00648a50  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648a50  64a100000000         mov eax, dword ptr fs:[0]
// 00648a56  6aff                 push -1
// 00648a58  683e199400           push 0x94193e
// 00648a5d  50                   push eax
// 00648a5e  b801000000           mov eax, 1
// 00648a63  64892500000000       mov dword ptr fs:[0], esp
// 00648a6a  8405c05eb800         test byte ptr [0xb85ec0], al
// 00648a70  752e                 jne 0x648aa0
// 00648a72  0905c05eb800         or dword ptr [0xb85ec0], eax
// 00648a78  687c68b500           push 0xb5687c
// 00648a7d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648a85  e85698feff           call 0x6322e0
// 00648a8a  83c404               add esp, 4
// 00648a8d  a3bc5eb800           mov dword ptr [0xb85ebc], eax
// 00648a92  8b0c24               mov ecx, dword ptr [esp]
// 00648a95  64890d00000000       mov dword ptr fs:[0], ecx
// 00648a9c  83c40c               add esp, 0xc
// 00648a9f  c3                   ret 
// 00648aa0  8b0c24               mov ecx, dword ptr [esp]
// 00648aa3  a1bc5eb800           mov eax, dword ptr [0xb85ebc]
// 00648aa8  64890d00000000       mov dword ptr fs:[0], ecx
// 00648aaf  83c40c               add esp, 0xc
// 00648ab2  c3                   ret 

extern char string_00b5687c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5687c);
    return *name;
}
