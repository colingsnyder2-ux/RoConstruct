// from server: 100% by nuck16
// roc 2009-12 00649070  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00649070  64a100000000         mov eax, dword ptr fs:[0]
// 00649076  6aff                 push -1
// 00649078  68fe1a9400           push 0x941afe
// 0064907d  50                   push eax
// 0064907e  b801000000           mov eax, 1
// 00649083  64892500000000       mov dword ptr fs:[0], esp
// 0064908a  8405305fb800         test byte ptr [0xb85f30], al
// 00649090  752e                 jne 0x6490c0
// 00649092  0905305fb800         or dword ptr [0xb85f30], eax
// 00649098  6828abb500           push 0xb5ab28
// 0064909d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006490a5  e83692feff           call 0x6322e0
// 006490aa  83c404               add esp, 4
// 006490ad  a32c5fb800           mov dword ptr [0xb85f2c], eax
// 006490b2  8b0c24               mov ecx, dword ptr [esp]
// 006490b5  64890d00000000       mov dword ptr fs:[0], ecx
// 006490bc  83c40c               add esp, 0xc
// 006490bf  c3                   ret 
// 006490c0  8b0c24               mov ecx, dword ptr [esp]
// 006490c3  a12c5fb800           mov eax, dword ptr [0xb85f2c]
// 006490c8  64890d00000000       mov dword ptr fs:[0], ecx
// 006490cf  83c40c               add esp, 0xc
// 006490d2  c3                   ret 

extern char string_00b5ab28[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5ab28);
    return *name;
}
