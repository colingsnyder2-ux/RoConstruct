// from server: 100% by nuck16
// roc 2009-12 00648d60  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648d60  64a100000000         mov eax, dword ptr fs:[0]
// 00648d66  6aff                 push -1
// 00648d68  681e1a9400           push 0x941a1e
// 00648d6d  50                   push eax
// 00648d6e  b801000000           mov eax, 1
// 00648d73  64892500000000       mov dword ptr fs:[0], esp
// 00648d7a  8405f85eb800         test byte ptr [0xb85ef8], al
// 00648d80  752e                 jne 0x648db0
// 00648d82  0905f85eb800         or dword ptr [0xb85ef8], eax
// 00648d88  681c98b500           push 0xb5981c
// 00648d8d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648d95  e84695feff           call 0x6322e0
// 00648d9a  83c404               add esp, 4
// 00648d9d  a3f45eb800           mov dword ptr [0xb85ef4], eax
// 00648da2  8b0c24               mov ecx, dword ptr [esp]
// 00648da5  64890d00000000       mov dword ptr fs:[0], ecx
// 00648dac  83c40c               add esp, 0xc
// 00648daf  c3                   ret 
// 00648db0  8b0c24               mov ecx, dword ptr [esp]
// 00648db3  a1f45eb800           mov eax, dword ptr [0xb85ef4]
// 00648db8  64890d00000000       mov dword ptr fs:[0], ecx
// 00648dbf  83c40c               add esp, 0xc
// 00648dc2  c3                   ret 

extern char string_00b5981c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5981c);
    return *name;
}
