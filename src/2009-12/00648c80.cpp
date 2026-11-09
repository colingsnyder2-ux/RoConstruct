// from server: 100% by nuck16
// roc 2009-12 00648c80  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648c80  64a100000000         mov eax, dword ptr fs:[0]
// 00648c86  6aff                 push -1
// 00648c88  68de199400           push 0x9419de
// 00648c8d  50                   push eax
// 00648c8e  b801000000           mov eax, 1
// 00648c93  64892500000000       mov dword ptr fs:[0], esp
// 00648c9a  8405e85eb800         test byte ptr [0xb85ee8], al
// 00648ca0  752e                 jne 0x648cd0
// 00648ca2  0905e85eb800         or dword ptr [0xb85ee8], eax
// 00648ca8  68fc94b500           push 0xb594fc
// 00648cad  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648cb5  e82696feff           call 0x6322e0
// 00648cba  83c404               add esp, 4
// 00648cbd  a3e45eb800           mov dword ptr [0xb85ee4], eax
// 00648cc2  8b0c24               mov ecx, dword ptr [esp]
// 00648cc5  64890d00000000       mov dword ptr fs:[0], ecx
// 00648ccc  83c40c               add esp, 0xc
// 00648ccf  c3                   ret 
// 00648cd0  8b0c24               mov ecx, dword ptr [esp]
// 00648cd3  a1e45eb800           mov eax, dword ptr [0xb85ee4]
// 00648cd8  64890d00000000       mov dword ptr fs:[0], ecx
// 00648cdf  83c40c               add esp, 0xc
// 00648ce2  c3                   ret 

extern char string_00b594fc[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b594fc);
    return *name;
}
