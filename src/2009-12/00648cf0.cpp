// from server: 100% by nuck16
// roc 2009-12 00648cf0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648cf0  64a100000000         mov eax, dword ptr fs:[0]
// 00648cf6  6aff                 push -1
// 00648cf8  68fe199400           push 0x9419fe
// 00648cfd  50                   push eax
// 00648cfe  b801000000           mov eax, 1
// 00648d03  64892500000000       mov dword ptr fs:[0], esp
// 00648d0a  8405f05eb800         test byte ptr [0xb85ef0], al
// 00648d10  752e                 jne 0x648d40
// 00648d12  0905f05eb800         or dword ptr [0xb85ef0], eax
// 00648d18  680895b500           push 0xb59508
// 00648d1d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648d25  e8b695feff           call 0x6322e0
// 00648d2a  83c404               add esp, 4
// 00648d2d  a3ec5eb800           mov dword ptr [0xb85eec], eax
// 00648d32  8b0c24               mov ecx, dword ptr [esp]
// 00648d35  64890d00000000       mov dword ptr fs:[0], ecx
// 00648d3c  83c40c               add esp, 0xc
// 00648d3f  c3                   ret 
// 00648d40  8b0c24               mov ecx, dword ptr [esp]
// 00648d43  a1ec5eb800           mov eax, dword ptr [0xb85eec]
// 00648d48  64890d00000000       mov dword ptr fs:[0], ecx
// 00648d4f  83c40c               add esp, 0xc
// 00648d52  c3                   ret 

extern char string_00b59508[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b59508);
    return *name;
}
