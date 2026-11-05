// from server: 100% by nuck16
// roc 2009-12 006495b0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006495b0  64a100000000         mov eax, dword ptr fs:[0]
// 006495b6  6aff                 push -1
// 006495b8  687e1c9400           push 0x941c7e
// 006495bd  50                   push eax
// 006495be  b801000000           mov eax, 1
// 006495c3  64892500000000       mov dword ptr fs:[0], esp
// 006495ca  8405905fb800         test byte ptr [0xb85f90], al
// 006495d0  752e                 jne 0x649600
// 006495d2  0905905fb800         or dword ptr [0xb85f90], eax
// 006495d8  687cf4b400           push 0xb4f47c
// 006495dd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006495e5  e8f68cfeff           call 0x6322e0
// 006495ea  83c404               add esp, 4
// 006495ed  a38c5fb800           mov dword ptr [0xb85f8c], eax
// 006495f2  8b0c24               mov ecx, dword ptr [esp]
// 006495f5  64890d00000000       mov dword ptr fs:[0], ecx
// 006495fc  83c40c               add esp, 0xc
// 006495ff  c3                   ret 
// 00649600  8b0c24               mov ecx, dword ptr [esp]
// 00649603  a18c5fb800           mov eax, dword ptr [0xb85f8c]
// 00649608  64890d00000000       mov dword ptr fs:[0], ecx
// 0064960f  83c40c               add esp, 0xc
// 00649612  c3                   ret 

extern char string_00b4f47c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4f47c);
    return *name;
}
