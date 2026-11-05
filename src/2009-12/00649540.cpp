// from server: 100% by nuck16
// roc 2009-12 00649540  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00649540  64a100000000         mov eax, dword ptr fs:[0]
// 00649546  6aff                 push -1
// 00649548  685e1c9400           push 0x941c5e
// 0064954d  50                   push eax
// 0064954e  b801000000           mov eax, 1
// 00649553  64892500000000       mov dword ptr fs:[0], esp
// 0064955a  8405885fb800         test byte ptr [0xb85f88], al
// 00649560  752e                 jne 0x649590
// 00649562  0905885fb800         or dword ptr [0xb85f88], eax
// 00649568  6870f4b400           push 0xb4f470
// 0064956d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00649575  e8668dfeff           call 0x6322e0
// 0064957a  83c404               add esp, 4
// 0064957d  a3845fb800           mov dword ptr [0xb85f84], eax
// 00649582  8b0c24               mov ecx, dword ptr [esp]
// 00649585  64890d00000000       mov dword ptr fs:[0], ecx
// 0064958c  83c40c               add esp, 0xc
// 0064958f  c3                   ret 
// 00649590  8b0c24               mov ecx, dword ptr [esp]
// 00649593  a1845fb800           mov eax, dword ptr [0xb85f84]
// 00649598  64890d00000000       mov dword ptr fs:[0], ecx
// 0064959f  83c40c               add esp, 0xc
// 006495a2  c3                   ret 

extern char string_00b4f470[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4f470);
    return *name;
}
