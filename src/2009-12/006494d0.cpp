// from server: 100% by nuck16
// roc 2009-12 006494d0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006494d0  64a100000000         mov eax, dword ptr fs:[0]
// 006494d6  6aff                 push -1
// 006494d8  683e1c9400           push 0x941c3e
// 006494dd  50                   push eax
// 006494de  b801000000           mov eax, 1
// 006494e3  64892500000000       mov dword ptr fs:[0], esp
// 006494ea  8405805fb800         test byte ptr [0xb85f80], al
// 006494f0  752e                 jne 0x649520
// 006494f2  0905805fb800         or dword ptr [0xb85f80], eax
// 006494f8  6858f4b400           push 0xb4f458
// 006494fd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00649505  e8d68dfeff           call 0x6322e0
// 0064950a  83c404               add esp, 4
// 0064950d  a37c5fb800           mov dword ptr [0xb85f7c], eax
// 00649512  8b0c24               mov ecx, dword ptr [esp]
// 00649515  64890d00000000       mov dword ptr fs:[0], ecx
// 0064951c  83c40c               add esp, 0xc
// 0064951f  c3                   ret 
// 00649520  8b0c24               mov ecx, dword ptr [esp]
// 00649523  a17c5fb800           mov eax, dword ptr [0xb85f7c]
// 00649528  64890d00000000       mov dword ptr fs:[0], ecx
// 0064952f  83c40c               add esp, 0xc
// 00649532  c3                   ret 

extern char string_00b4f458[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4f458);
    return *name;
}
