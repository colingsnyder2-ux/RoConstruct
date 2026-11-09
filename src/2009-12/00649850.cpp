// from server: 100% by nuck16
// roc 2009-12 00649850  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00649850  64a100000000         mov eax, dword ptr fs:[0]
// 00649856  6aff                 push -1
// 00649858  683e1d9400           push 0x941d3e
// 0064985d  50                   push eax
// 0064985e  b801000000           mov eax, 1
// 00649863  64892500000000       mov dword ptr fs:[0], esp
// 0064986a  8405c05fb800         test byte ptr [0xb85fc0], al
// 00649870  752e                 jne 0x6498a0
// 00649872  0905c05fb800         or dword ptr [0xb85fc0], eax
// 00649878  68d4f4b400           push 0xb4f4d4
// 0064987d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00649885  e8568afeff           call 0x6322e0
// 0064988a  83c404               add esp, 4
// 0064988d  a3bc5fb800           mov dword ptr [0xb85fbc], eax
// 00649892  8b0c24               mov ecx, dword ptr [esp]
// 00649895  64890d00000000       mov dword ptr fs:[0], ecx
// 0064989c  83c40c               add esp, 0xc
// 0064989f  c3                   ret 
// 006498a0  8b0c24               mov ecx, dword ptr [esp]
// 006498a3  a1bc5fb800           mov eax, dword ptr [0xb85fbc]
// 006498a8  64890d00000000       mov dword ptr fs:[0], ecx
// 006498af  83c40c               add esp, 0xc
// 006498b2  c3                   ret 

extern char string_00b4f4d4[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4f4d4);
    return *name;
}
