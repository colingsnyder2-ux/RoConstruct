// from server: 100% by nuck16
// roc 2009-12 00648dd0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648dd0  64a100000000         mov eax, dword ptr fs:[0]
// 00648dd6  6aff                 push -1
// 00648dd8  683e1a9400           push 0x941a3e
// 00648ddd  50                   push eax
// 00648dde  b801000000           mov eax, 1
// 00648de3  64892500000000       mov dword ptr fs:[0], esp
// 00648dea  8405005fb800         test byte ptr [0xb85f00], al
// 00648df0  752e                 jne 0x648e20
// 00648df2  0905005fb800         or dword ptr [0xb85f00], eax
// 00648df8  6838479e00           push 0x9e4738
// 00648dfd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648e05  e8d694feff           call 0x6322e0
// 00648e0a  83c404               add esp, 4
// 00648e0d  a3fc5eb800           mov dword ptr [0xb85efc], eax
// 00648e12  8b0c24               mov ecx, dword ptr [esp]
// 00648e15  64890d00000000       mov dword ptr fs:[0], ecx
// 00648e1c  83c40c               add esp, 0xc
// 00648e1f  c3                   ret 
// 00648e20  8b0c24               mov ecx, dword ptr [esp]
// 00648e23  a1fc5eb800           mov eax, dword ptr [0xb85efc]
// 00648e28  64890d00000000       mov dword ptr fs:[0], ecx
// 00648e2f  83c40c               add esp, 0xc
// 00648e32  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("TouchTransmitter");
    return *name;
}
