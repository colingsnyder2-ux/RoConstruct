// from server: 100% by nuck16
// roc 2009-12 00648890  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648890  64a100000000         mov eax, dword ptr fs:[0]
// 00648896  6aff                 push -1
// 00648898  68be189400           push 0x9418be
// 0064889d  50                   push eax
// 0064889e  b801000000           mov eax, 1
// 006488a3  64892500000000       mov dword ptr fs:[0], esp
// 006488aa  8405a05eb800         test byte ptr [0xb85ea0], al
// 006488b0  752e                 jne 0x6488e0
// 006488b2  0905a05eb800         or dword ptr [0xb85ea0], eax
// 006488b8  68101fb500           push 0xb51f10
// 006488bd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006488c5  e8169afeff           call 0x6322e0
// 006488ca  83c404               add esp, 4
// 006488cd  a39c5eb800           mov dword ptr [0xb85e9c], eax
// 006488d2  8b0c24               mov ecx, dword ptr [esp]
// 006488d5  64890d00000000       mov dword ptr fs:[0], ecx
// 006488dc  83c40c               add esp, 0xc
// 006488df  c3                   ret 
// 006488e0  8b0c24               mov ecx, dword ptr [esp]
// 006488e3  a19c5eb800           mov eax, dword ptr [0xb85e9c]
// 006488e8  64890d00000000       mov dword ptr fs:[0], ecx
// 006488ef  83c40c               add esp, 0xc
// 006488f2  c3                   ret 

extern char string_00b51f10[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b51f10);
    return *name;
}
