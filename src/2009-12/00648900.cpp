// from server: 100% by nuck16
// roc 2009-12 00648900  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648900  64a100000000         mov eax, dword ptr fs:[0]
// 00648906  6aff                 push -1
// 00648908  68de189400           push 0x9418de
// 0064890d  50                   push eax
// 0064890e  b801000000           mov eax, 1
// 00648913  64892500000000       mov dword ptr fs:[0], esp
// 0064891a  8405a85eb800         test byte ptr [0xb85ea8], al
// 00648920  752e                 jne 0x648950
// 00648922  0905a85eb800         or dword ptr [0xb85ea8], eax
// 00648928  68201fb500           push 0xb51f20
// 0064892d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648935  e8a699feff           call 0x6322e0
// 0064893a  83c404               add esp, 4
// 0064893d  a3a45eb800           mov dword ptr [0xb85ea4], eax
// 00648942  8b0c24               mov ecx, dword ptr [esp]
// 00648945  64890d00000000       mov dword ptr fs:[0], ecx
// 0064894c  83c40c               add esp, 0xc
// 0064894f  c3                   ret 
// 00648950  8b0c24               mov ecx, dword ptr [esp]
// 00648953  a1a45eb800           mov eax, dword ptr [0xb85ea4]
// 00648958  64890d00000000       mov dword ptr fs:[0], ecx
// 0064895f  83c40c               add esp, 0xc
// 00648962  c3                   ret 

extern char string_00b51f20[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b51f20);
    return *name;
}
