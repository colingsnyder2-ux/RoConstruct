// from server: 100% by nuck16
// roc 2009-12 00648ac0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648ac0  64a100000000         mov eax, dword ptr fs:[0]
// 00648ac6  6aff                 push -1
// 00648ac8  685e199400           push 0x94195e
// 00648acd  50                   push eax
// 00648ace  b801000000           mov eax, 1
// 00648ad3  64892500000000       mov dword ptr fs:[0], esp
// 00648ada  8405c85eb800         test byte ptr [0xb85ec8], al
// 00648ae0  752e                 jne 0x648b10
// 00648ae2  0905c85eb800         or dword ptr [0xb85ec8], eax
// 00648ae8  68907fb500           push 0xb57f90
// 00648aed  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648af5  e8e697feff           call 0x6322e0
// 00648afa  83c404               add esp, 4
// 00648afd  a3c45eb800           mov dword ptr [0xb85ec4], eax
// 00648b02  8b0c24               mov ecx, dword ptr [esp]
// 00648b05  64890d00000000       mov dword ptr fs:[0], ecx
// 00648b0c  83c40c               add esp, 0xc
// 00648b0f  c3                   ret 
// 00648b10  8b0c24               mov ecx, dword ptr [esp]
// 00648b13  a1c45eb800           mov eax, dword ptr [0xb85ec4]
// 00648b18  64890d00000000       mov dword ptr fs:[0], ecx
// 00648b1f  83c40c               add esp, 0xc
// 00648b22  c3                   ret 

extern char string_00b57f90[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b57f90);
    return *name;
}
