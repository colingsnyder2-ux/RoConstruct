// from server: 100% by nuck16
// roc 2009-12 00648ba0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648ba0  64a100000000         mov eax, dword ptr fs:[0]
// 00648ba6  6aff                 push -1
// 00648ba8  689e199400           push 0x94199e
// 00648bad  50                   push eax
// 00648bae  b801000000           mov eax, 1
// 00648bb3  64892500000000       mov dword ptr fs:[0], esp
// 00648bba  8405d85eb800         test byte ptr [0xb85ed8], al
// 00648bc0  752e                 jne 0x648bf0
// 00648bc2  0905d85eb800         or dword ptr [0xb85ed8], eax
// 00648bc8  68d4419e00           push 0x9e41d4
// 00648bcd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648bd5  e80697feff           call 0x6322e0
// 00648bda  83c404               add esp, 4
// 00648bdd  a3d45eb800           mov dword ptr [0xb85ed4], eax
// 00648be2  8b0c24               mov ecx, dword ptr [esp]
// 00648be5  64890d00000000       mov dword ptr fs:[0], ecx
// 00648bec  83c40c               add esp, 0xc
// 00648bef  c3                   ret 
// 00648bf0  8b0c24               mov ecx, dword ptr [esp]
// 00648bf3  a1d45eb800           mov eax, dword ptr [0xb85ed4]
// 00648bf8  64890d00000000       mov dword ptr fs:[0], ecx
// 00648bff  83c40c               add esp, 0xc
// 00648c02  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("LocalBackpackSwitcher");
    return *name;
}
