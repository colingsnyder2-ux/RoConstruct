// from server: 100% by nuck16
// roc 2009-12 006491c0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006491c0  64a100000000         mov eax, dword ptr fs:[0]
// 006491c6  6aff                 push -1
// 006491c8  685e1b9400           push 0x941b5e
// 006491cd  50                   push eax
// 006491ce  b801000000           mov eax, 1
// 006491d3  64892500000000       mov dword ptr fs:[0], esp
// 006491da  8405485fb800         test byte ptr [0xb85f48], al
// 006491e0  752e                 jne 0x649210
// 006491e2  0905485fb800         or dword ptr [0xb85f48], eax
// 006491e8  68d8bdb500           push 0xb5bdd8
// 006491ed  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006491f5  e8e690feff           call 0x6322e0
// 006491fa  83c404               add esp, 4
// 006491fd  a3445fb800           mov dword ptr [0xb85f44], eax
// 00649202  8b0c24               mov ecx, dword ptr [esp]
// 00649205  64890d00000000       mov dword ptr fs:[0], ecx
// 0064920c  83c40c               add esp, 0xc
// 0064920f  c3                   ret 
// 00649210  8b0c24               mov ecx, dword ptr [esp]
// 00649213  a1445fb800           mov eax, dword ptr [0xb85f44]
// 00649218  64890d00000000       mov dword ptr fs:[0], ecx
// 0064921f  83c40c               add esp, 0xc
// 00649222  c3                   ret 

extern char string_00b5bdd8[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5bdd8);
    return *name;
}
