// from server: 100% by nuck16
// roc 2009-12 006d4000  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d4000  64a100000000         mov eax, dword ptr fs:[0]
// 006d4006  6aff                 push -1
// 006d4008  684ea39400           push 0x94a34e
// 006d400d  50                   push eax
// 006d400e  b801000000           mov eax, 1
// 006d4013  64892500000000       mov dword ptr fs:[0], esp
// 006d401a  8405742cb900         test byte ptr [0xb92c74], al
// 006d4020  752e                 jne 0x6d4050
// 006d4022  0905742cb900         or dword ptr [0xb92c74], eax
// 006d4028  682c24b600           push 0xb6242c
// 006d402d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d4035  e8a6e2f5ff           call 0x6322e0
// 006d403a  83c404               add esp, 4
// 006d403d  a3702cb900           mov dword ptr [0xb92c70], eax
// 006d4042  8b0c24               mov ecx, dword ptr [esp]
// 006d4045  64890d00000000       mov dword ptr fs:[0], ecx
// 006d404c  83c40c               add esp, 0xc
// 006d404f  c3                   ret 
// 006d4050  8b0c24               mov ecx, dword ptr [esp]
// 006d4053  a1702cb900           mov eax, dword ptr [0xb92c70]
// 006d4058  64890d00000000       mov dword ptr fs:[0], ecx
// 006d405f  83c40c               add esp, 0xc
// 006d4062  c3                   ret 

extern char string_00b6242c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b6242c);
    return *name;
}
