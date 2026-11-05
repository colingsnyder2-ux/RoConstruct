// from server: 100% by nuck16
// roc 2009-12 006487b0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006487b0  64a100000000         mov eax, dword ptr fs:[0]
// 006487b6  6aff                 push -1
// 006487b8  687e189400           push 0x94187e
// 006487bd  50                   push eax
// 006487be  b801000000           mov eax, 1
// 006487c3  64892500000000       mov dword ptr fs:[0], esp
// 006487ca  8405905eb800         test byte ptr [0xb85e90], al
// 006487d0  752e                 jne 0x648800
// 006487d2  0905905eb800         or dword ptr [0xb85e90], eax
// 006487d8  68501fb500           push 0xb51f50
// 006487dd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006487e5  e8f69afeff           call 0x6322e0
// 006487ea  83c404               add esp, 4
// 006487ed  a38c5eb800           mov dword ptr [0xb85e8c], eax
// 006487f2  8b0c24               mov ecx, dword ptr [esp]
// 006487f5  64890d00000000       mov dword ptr fs:[0], ecx
// 006487fc  83c40c               add esp, 0xc
// 006487ff  c3                   ret 
// 00648800  8b0c24               mov ecx, dword ptr [esp]
// 00648803  a18c5eb800           mov eax, dword ptr [0xb85e8c]
// 00648808  64890d00000000       mov dword ptr fs:[0], ecx
// 0064880f  83c40c               add esp, 0xc
// 00648812  c3                   ret 

extern char string_00b51f50[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b51f50);
    return *name;
}
