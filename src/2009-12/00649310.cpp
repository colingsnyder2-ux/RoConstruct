// from server: 100% by nuck16
// roc 2009-12 00649310  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00649310  64a100000000         mov eax, dword ptr fs:[0]
// 00649316  6aff                 push -1
// 00649318  68be1b9400           push 0x941bbe
// 0064931d  50                   push eax
// 0064931e  b801000000           mov eax, 1
// 00649323  64892500000000       mov dword ptr fs:[0], esp
// 0064932a  8405605fb800         test byte ptr [0xb85f60], al
// 00649330  752e                 jne 0x649360
// 00649332  0905605fb800         or dword ptr [0xb85f60], eax
// 00649338  6828cfb500           push 0xb5cf28
// 0064933d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00649345  e8968ffeff           call 0x6322e0
// 0064934a  83c404               add esp, 4
// 0064934d  a35c5fb800           mov dword ptr [0xb85f5c], eax
// 00649352  8b0c24               mov ecx, dword ptr [esp]
// 00649355  64890d00000000       mov dword ptr fs:[0], ecx
// 0064935c  83c40c               add esp, 0xc
// 0064935f  c3                   ret 
// 00649360  8b0c24               mov ecx, dword ptr [esp]
// 00649363  a15c5fb800           mov eax, dword ptr [0xb85f5c]
// 00649368  64890d00000000       mov dword ptr fs:[0], ecx
// 0064936f  83c40c               add esp, 0xc
// 00649372  c3                   ret 

extern char string_00b5cf28[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5cf28);
    return *name;
}
