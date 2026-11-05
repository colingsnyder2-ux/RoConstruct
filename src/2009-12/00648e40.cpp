// from server: 100% by nuck16
// roc 2009-12 00648e40  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648e40  64a100000000         mov eax, dword ptr fs:[0]
// 00648e46  6aff                 push -1
// 00648e48  685e1a9400           push 0x941a5e
// 00648e4d  50                   push eax
// 00648e4e  b801000000           mov eax, 1
// 00648e53  64892500000000       mov dword ptr fs:[0], esp
// 00648e5a  8405085fb800         test byte ptr [0xb85f08], al
// 00648e60  752e                 jne 0x648e90
// 00648e62  0905085fb800         or dword ptr [0xb85f08], eax
// 00648e68  68ecf4b400           push 0xb4f4ec
// 00648e6d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648e75  e86694feff           call 0x6322e0
// 00648e7a  83c404               add esp, 4
// 00648e7d  a3045fb800           mov dword ptr [0xb85f04], eax
// 00648e82  8b0c24               mov ecx, dword ptr [esp]
// 00648e85  64890d00000000       mov dword ptr fs:[0], ecx
// 00648e8c  83c40c               add esp, 0xc
// 00648e8f  c3                   ret 
// 00648e90  8b0c24               mov ecx, dword ptr [esp]
// 00648e93  a1045fb800           mov eax, dword ptr [0xb85f04]
// 00648e98  64890d00000000       mov dword ptr fs:[0], ecx
// 00648e9f  83c40c               add esp, 0xc
// 00648ea2  c3                   ret 

extern char string_00b4f4ec[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4f4ec);
    return *name;
}
