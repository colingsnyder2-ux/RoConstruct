// from server: 100% by nuck16
// roc 2009-12 00649230  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00649230  64a100000000         mov eax, dword ptr fs:[0]
// 00649236  6aff                 push -1
// 00649238  687e1b9400           push 0x941b7e
// 0064923d  50                   push eax
// 0064923e  b801000000           mov eax, 1
// 00649243  64892500000000       mov dword ptr fs:[0], esp
// 0064924a  8405505fb800         test byte ptr [0xb85f50], al
// 00649250  752e                 jne 0x649280
// 00649252  0905505fb800         or dword ptr [0xb85f50], eax
// 00649258  6884c6b500           push 0xb5c684
// 0064925d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00649265  e87690feff           call 0x6322e0
// 0064926a  83c404               add esp, 4
// 0064926d  a34c5fb800           mov dword ptr [0xb85f4c], eax
// 00649272  8b0c24               mov ecx, dword ptr [esp]
// 00649275  64890d00000000       mov dword ptr fs:[0], ecx
// 0064927c  83c40c               add esp, 0xc
// 0064927f  c3                   ret 
// 00649280  8b0c24               mov ecx, dword ptr [esp]
// 00649283  a14c5fb800           mov eax, dword ptr [0xb85f4c]
// 00649288  64890d00000000       mov dword ptr fs:[0], ecx
// 0064928f  83c40c               add esp, 0xc
// 00649292  c3                   ret 

extern char string_00b5c684[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5c684);
    return *name;
}
