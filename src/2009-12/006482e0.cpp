// from server: 100% by nuck16
// roc 2009-12 006482e0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006482e0  64a100000000         mov eax, dword ptr fs:[0]
// 006482e6  6aff                 push -1
// 006482e8  681e179400           push 0x94171e
// 006482ed  50                   push eax
// 006482ee  b801000000           mov eax, 1
// 006482f3  64892500000000       mov dword ptr fs:[0], esp
// 006482fa  8405385eb800         test byte ptr [0xb85e38], al
// 00648300  752e                 jne 0x648330
// 00648302  0905385eb800         or dword ptr [0xb85e38], eax
// 00648308  686847b500           push 0xb54768
// 0064830d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648315  e8c69ffeff           call 0x6322e0
// 0064831a  83c404               add esp, 4
// 0064831d  a3345eb800           mov dword ptr [0xb85e34], eax
// 00648322  8b0c24               mov ecx, dword ptr [esp]
// 00648325  64890d00000000       mov dword ptr fs:[0], ecx
// 0064832c  83c40c               add esp, 0xc
// 0064832f  c3                   ret 
// 00648330  8b0c24               mov ecx, dword ptr [esp]
// 00648333  a1345eb800           mov eax, dword ptr [0xb85e34]
// 00648338  64890d00000000       mov dword ptr fs:[0], ecx
// 0064833f  83c40c               add esp, 0xc
// 00648342  c3                   ret 

extern char string_00b54768[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b54768);
    return *name;
}
