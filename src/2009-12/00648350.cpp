// from server: 100% by nuck16
// roc 2009-12 00648350  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648350  64a100000000         mov eax, dword ptr fs:[0]
// 00648356  6aff                 push -1
// 00648358  683e179400           push 0x94173e
// 0064835d  50                   push eax
// 0064835e  b801000000           mov eax, 1
// 00648363  64892500000000       mov dword ptr fs:[0], esp
// 0064836a  8405405eb800         test byte ptr [0xb85e40], al
// 00648370  752e                 jne 0x6483a0
// 00648372  0905405eb800         or dword ptr [0xb85e40], eax
// 00648378  68584ab500           push 0xb54a58
// 0064837d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648385  e8569ffeff           call 0x6322e0
// 0064838a  83c404               add esp, 4
// 0064838d  a33c5eb800           mov dword ptr [0xb85e3c], eax
// 00648392  8b0c24               mov ecx, dword ptr [esp]
// 00648395  64890d00000000       mov dword ptr fs:[0], ecx
// 0064839c  83c40c               add esp, 0xc
// 0064839f  c3                   ret 
// 006483a0  8b0c24               mov ecx, dword ptr [esp]
// 006483a3  a13c5eb800           mov eax, dword ptr [0xb85e3c]
// 006483a8  64890d00000000       mov dword ptr fs:[0], ecx
// 006483af  83c40c               add esp, 0xc
// 006483b2  c3                   ret 

extern char string_00b54a58[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b54a58);
    return *name;
}
