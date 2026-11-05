// from server: 100% by nuck16
// roc 2009-12 00648820  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648820  64a100000000         mov eax, dword ptr fs:[0]
// 00648826  6aff                 push -1
// 00648828  689e189400           push 0x94189e
// 0064882d  50                   push eax
// 0064882e  b801000000           mov eax, 1
// 00648833  64892500000000       mov dword ptr fs:[0], esp
// 0064883a  8405985eb800         test byte ptr [0xb85e98], al
// 00648840  752e                 jne 0x648870
// 00648842  0905985eb800         or dword ptr [0xb85e98], eax
// 00648848  685c1fb500           push 0xb51f5c
// 0064884d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648855  e8869afeff           call 0x6322e0
// 0064885a  83c404               add esp, 4
// 0064885d  a3945eb800           mov dword ptr [0xb85e94], eax
// 00648862  8b0c24               mov ecx, dword ptr [esp]
// 00648865  64890d00000000       mov dword ptr fs:[0], ecx
// 0064886c  83c40c               add esp, 0xc
// 0064886f  c3                   ret 
// 00648870  8b0c24               mov ecx, dword ptr [esp]
// 00648873  a1945eb800           mov eax, dword ptr [0xb85e94]
// 00648878  64890d00000000       mov dword ptr fs:[0], ecx
// 0064887f  83c40c               add esp, 0xc
// 00648882  c3                   ret 

extern char string_00b51f5c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b51f5c);
    return *name;
}
