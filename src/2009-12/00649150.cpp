// from server: 100% by nuck16
// roc 2009-12 00649150  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00649150  64a100000000         mov eax, dword ptr fs:[0]
// 00649156  6aff                 push -1
// 00649158  683e1b9400           push 0x941b3e
// 0064915d  50                   push eax
// 0064915e  b801000000           mov eax, 1
// 00649163  64892500000000       mov dword ptr fs:[0], esp
// 0064916a  8405405fb800         test byte ptr [0xb85f40], al
// 00649170  752e                 jne 0x6491a0
// 00649172  0905405fb800         or dword ptr [0xb85f40], eax
// 00649178  68ccb3b500           push 0xb5b3cc
// 0064917d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00649185  e85691feff           call 0x6322e0
// 0064918a  83c404               add esp, 4
// 0064918d  a33c5fb800           mov dword ptr [0xb85f3c], eax
// 00649192  8b0c24               mov ecx, dword ptr [esp]
// 00649195  64890d00000000       mov dword ptr fs:[0], ecx
// 0064919c  83c40c               add esp, 0xc
// 0064919f  c3                   ret 
// 006491a0  8b0c24               mov ecx, dword ptr [esp]
// 006491a3  a13c5fb800           mov eax, dword ptr [0xb85f3c]
// 006491a8  64890d00000000       mov dword ptr fs:[0], ecx
// 006491af  83c40c               add esp, 0xc
// 006491b2  c3                   ret 

extern char string_00b5b3cc[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5b3cc);
    return *name;
}
