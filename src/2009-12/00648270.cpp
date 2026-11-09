// from server: 100% by nuck16
// roc 2009-12 00648270  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648270  64a100000000         mov eax, dword ptr fs:[0]
// 00648276  6aff                 push -1
// 00648278  68fe169400           push 0x9416fe
// 0064827d  50                   push eax
// 0064827e  b801000000           mov eax, 1
// 00648283  64892500000000       mov dword ptr fs:[0], esp
// 0064828a  8405305eb800         test byte ptr [0xb85e30], al
// 00648290  752e                 jne 0x6482c0
// 00648292  0905305eb800         or dword ptr [0xb85e30], eax
// 00648298  686041b500           push 0xb54160
// 0064829d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006482a5  e836a0feff           call 0x6322e0
// 006482aa  83c404               add esp, 4
// 006482ad  a32c5eb800           mov dword ptr [0xb85e2c], eax
// 006482b2  8b0c24               mov ecx, dword ptr [esp]
// 006482b5  64890d00000000       mov dword ptr fs:[0], ecx
// 006482bc  83c40c               add esp, 0xc
// 006482bf  c3                   ret 
// 006482c0  8b0c24               mov ecx, dword ptr [esp]
// 006482c3  a12c5eb800           mov eax, dword ptr [0xb85e2c]
// 006482c8  64890d00000000       mov dword ptr fs:[0], ecx
// 006482cf  83c40c               add esp, 0xc
// 006482d2  c3                   ret 

extern char string_00b54160[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b54160);
    return *name;
}
