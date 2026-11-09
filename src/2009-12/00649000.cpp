// from server: 100% by nuck16
// roc 2009-12 00649000  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00649000  64a100000000         mov eax, dword ptr fs:[0]
// 00649006  6aff                 push -1
// 00649008  68de1a9400           push 0x941ade
// 0064900d  50                   push eax
// 0064900e  b801000000           mov eax, 1
// 00649013  64892500000000       mov dword ptr fs:[0], esp
// 0064901a  8405285fb800         test byte ptr [0xb85f28], al
// 00649020  752e                 jne 0x649050
// 00649022  0905285fb800         or dword ptr [0xb85f28], eax
// 00649028  68dca7b500           push 0xb5a7dc
// 0064902d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00649035  e8a692feff           call 0x6322e0
// 0064903a  83c404               add esp, 4
// 0064903d  a3245fb800           mov dword ptr [0xb85f24], eax
// 00649042  8b0c24               mov ecx, dword ptr [esp]
// 00649045  64890d00000000       mov dword ptr fs:[0], ecx
// 0064904c  83c40c               add esp, 0xc
// 0064904f  c3                   ret 
// 00649050  8b0c24               mov ecx, dword ptr [esp]
// 00649053  a1245fb800           mov eax, dword ptr [0xb85f24]
// 00649058  64890d00000000       mov dword ptr fs:[0], ecx
// 0064905f  83c40c               add esp, 0xc
// 00649062  c3                   ret 

extern char string_00b5a7dc[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5a7dc);
    return *name;
}
