// from server: 100% by nuck16
// roc 2009-12 00649620  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00649620  64a100000000         mov eax, dword ptr fs:[0]
// 00649626  6aff                 push -1
// 00649628  689e1c9400           push 0x941c9e
// 0064962d  50                   push eax
// 0064962e  b801000000           mov eax, 1
// 00649633  64892500000000       mov dword ptr fs:[0], esp
// 0064963a  8405985fb800         test byte ptr [0xb85f98], al
// 00649640  752e                 jne 0x649670
// 00649642  0905985fb800         or dword ptr [0xb85f98], eax
// 00649648  688cf4b400           push 0xb4f48c
// 0064964d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00649655  e8868cfeff           call 0x6322e0
// 0064965a  83c404               add esp, 4
// 0064965d  a3945fb800           mov dword ptr [0xb85f94], eax
// 00649662  8b0c24               mov ecx, dword ptr [esp]
// 00649665  64890d00000000       mov dword ptr fs:[0], ecx
// 0064966c  83c40c               add esp, 0xc
// 0064966f  c3                   ret 
// 00649670  8b0c24               mov ecx, dword ptr [esp]
// 00649673  a1945fb800           mov eax, dword ptr [0xb85f94]
// 00649678  64890d00000000       mov dword ptr fs:[0], ecx
// 0064967f  83c40c               add esp, 0xc
// 00649682  c3                   ret 

extern char string_00b4f48c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4f48c);
    return *name;
}
