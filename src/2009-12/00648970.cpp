// from server: 100% by nuck16
// roc 2009-12 00648970  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00648970
//
// 00648970  64a100000000         mov eax, dword ptr fs:[0]
// 00648976  6aff                 push -1
// 00648978  68fe189400           push 0x9418fe
// 0064897d  50                   push eax
// 0064897e  b801000000           mov eax, 1
// 00648983  64892500000000       mov dword ptr fs:[0], esp
// 0064898a  8405b05eb800         test byte ptr [0xb85eb0], al
// 00648990  752e                 jne 0x6489c0
// 00648992  0905b05eb800         or dword ptr [0xb85eb0], eax
// 00648998  683c1fb500           push 0xb51f3c
// 0064899d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006489a5  e83699feff           call 0x6322e0
// 006489aa  83c404               add esp, 4
// 006489ad  a3ac5eb800           mov dword ptr [0xb85eac], eax
// 006489b2  8b0c24               mov ecx, dword ptr [esp]
// 006489b5  64890d00000000       mov dword ptr fs:[0], ecx
// 006489bc  83c40c               add esp, 0xc
// 006489bf  c3                   ret 
// 006489c0  8b0c24               mov ecx, dword ptr [esp]
// 006489c3  a1ac5eb800           mov eax, dword ptr [0xb85eac]
// 006489c8  64890d00000000       mov dword ptr fs:[0], ecx
// 006489cf  83c40c               add esp, 0xc
// 006489d2  c3                   ret 

extern char string_00b51f3c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b51f3c);
    return *name;
}
