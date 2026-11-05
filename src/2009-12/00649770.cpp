// from server: 100% by nuck16
// roc 2009-12 00649770  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00649770  64a100000000         mov eax, dword ptr fs:[0]
// 00649776  6aff                 push -1
// 00649778  68fe1c9400           push 0x941cfe
// 0064977d  50                   push eax
// 0064977e  b801000000           mov eax, 1
// 00649783  64892500000000       mov dword ptr fs:[0], esp
// 0064978a  8405b05fb800         test byte ptr [0xb85fb0], al
// 00649790  752e                 jne 0x6497c0
// 00649792  0905b05fb800         or dword ptr [0xb85fb0], eax
// 00649798  68b0f4b400           push 0xb4f4b0
// 0064979d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006497a5  e8368bfeff           call 0x6322e0
// 006497aa  83c404               add esp, 4
// 006497ad  a3ac5fb800           mov dword ptr [0xb85fac], eax
// 006497b2  8b0c24               mov ecx, dword ptr [esp]
// 006497b5  64890d00000000       mov dword ptr fs:[0], ecx
// 006497bc  83c40c               add esp, 0xc
// 006497bf  c3                   ret 
// 006497c0  8b0c24               mov ecx, dword ptr [esp]
// 006497c3  a1ac5fb800           mov eax, dword ptr [0xb85fac]
// 006497c8  64890d00000000       mov dword ptr fs:[0], ecx
// 006497cf  83c40c               add esp, 0xc
// 006497d2  c3                   ret 

extern char string_00b4f4b0[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4f4b0);
    return *name;
}
