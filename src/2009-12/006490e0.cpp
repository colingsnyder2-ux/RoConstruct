// from server: 100% by nuck16
// roc 2009-12 006490e0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006490e0  64a100000000         mov eax, dword ptr fs:[0]
// 006490e6  6aff                 push -1
// 006490e8  681e1b9400           push 0x941b1e
// 006490ed  50                   push eax
// 006490ee  b801000000           mov eax, 1
// 006490f3  64892500000000       mov dword ptr fs:[0], esp
// 006490fa  8405385fb800         test byte ptr [0xb85f38], al
// 00649100  752e                 jne 0x649130
// 00649102  0905385fb800         or dword ptr [0xb85f38], eax
// 00649108  68f0afb500           push 0xb5aff0
// 0064910d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00649115  e8c691feff           call 0x6322e0
// 0064911a  83c404               add esp, 4
// 0064911d  a3345fb800           mov dword ptr [0xb85f34], eax
// 00649122  8b0c24               mov ecx, dword ptr [esp]
// 00649125  64890d00000000       mov dword ptr fs:[0], ecx
// 0064912c  83c40c               add esp, 0xc
// 0064912f  c3                   ret 
// 00649130  8b0c24               mov ecx, dword ptr [esp]
// 00649133  a1345fb800           mov eax, dword ptr [0xb85f34]
// 00649138  64890d00000000       mov dword ptr fs:[0], ecx
// 0064913f  83c40c               add esp, 0xc
// 00649142  c3                   ret 

extern char string_00b5aff0[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5aff0);
    return *name;
}
