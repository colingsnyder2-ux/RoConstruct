// from server: 100% by nuck16
// roc 2009-12 00649380  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00649380  64a100000000         mov eax, dword ptr fs:[0]
// 00649386  6aff                 push -1
// 00649388  68de1b9400           push 0x941bde
// 0064938d  50                   push eax
// 0064938e  b801000000           mov eax, 1
// 00649393  64892500000000       mov dword ptr fs:[0], esp
// 0064939a  8405685fb800         test byte ptr [0xb85f68], al
// 006493a0  752e                 jne 0x6493d0
// 006493a2  0905685fb800         or dword ptr [0xb85f68], eax
// 006493a8  683cd8b500           push 0xb5d83c
// 006493ad  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006493b5  e8268ffeff           call 0x6322e0
// 006493ba  83c404               add esp, 4
// 006493bd  a3645fb800           mov dword ptr [0xb85f64], eax
// 006493c2  8b0c24               mov ecx, dword ptr [esp]
// 006493c5  64890d00000000       mov dword ptr fs:[0], ecx
// 006493cc  83c40c               add esp, 0xc
// 006493cf  c3                   ret 
// 006493d0  8b0c24               mov ecx, dword ptr [esp]
// 006493d3  a1645fb800           mov eax, dword ptr [0xb85f64]
// 006493d8  64890d00000000       mov dword ptr fs:[0], ecx
// 006493df  83c40c               add esp, 0xc
// 006493e2  c3                   ret 

extern char string_00b5d83c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5d83c);
    return *name;
}
