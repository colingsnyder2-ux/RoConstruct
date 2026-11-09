// from server: 100% by nuck16
// roc 2009-12 006485f0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006485f0  64a100000000         mov eax, dword ptr fs:[0]
// 006485f6  6aff                 push -1
// 006485f8  68fe179400           push 0x9417fe
// 006485fd  50                   push eax
// 006485fe  b801000000           mov eax, 1
// 00648603  64892500000000       mov dword ptr fs:[0], esp
// 0064860a  8405705eb800         test byte ptr [0xb85e70], al
// 00648610  752e                 jne 0x648640
// 00648612  0905705eb800         or dword ptr [0xb85e70], eax
// 00648618  6848349e00           push 0x9e3448
// 0064861d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648625  e8b69cfeff           call 0x6322e0
// 0064862a  83c404               add esp, 4
// 0064862d  a36c5eb800           mov dword ptr [0xb85e6c], eax
// 00648632  8b0c24               mov ecx, dword ptr [esp]
// 00648635  64890d00000000       mov dword ptr fs:[0], ecx
// 0064863c  83c40c               add esp, 0xc
// 0064863f  c3                   ret 
// 00648640  8b0c24               mov ecx, dword ptr [esp]
// 00648643  a16c5eb800           mov eax, dword ptr [0xb85e6c]
// 00648648  64890d00000000       mov dword ptr fs:[0], ecx
// 0064864f  83c40c               add esp, 0xc
// 00648652  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("FlagStandService");
    return *name;
}
