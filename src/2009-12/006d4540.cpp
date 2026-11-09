// from server: 100% by nuck16
// roc 2009-12 006d4540  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d4540  64a100000000         mov eax, dword ptr fs:[0]
// 006d4546  6aff                 push -1
// 006d4548  68cea49400           push 0x94a4ce
// 006d454d  50                   push eax
// 006d454e  b801000000           mov eax, 1
// 006d4553  64892500000000       mov dword ptr fs:[0], esp
// 006d455a  8405d42cb900         test byte ptr [0xb92cd4], al
// 006d4560  752e                 jne 0x6d4590
// 006d4562  0905d42cb900         or dword ptr [0xb92cd4], eax
// 006d4568  683c31b600           push 0xb6313c
// 006d456d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d4575  e866ddf5ff           call 0x6322e0
// 006d457a  83c404               add esp, 4
// 006d457d  a3d02cb900           mov dword ptr [0xb92cd0], eax
// 006d4582  8b0c24               mov ecx, dword ptr [esp]
// 006d4585  64890d00000000       mov dword ptr fs:[0], ecx
// 006d458c  83c40c               add esp, 0xc
// 006d458f  c3                   ret 
// 006d4590  8b0c24               mov ecx, dword ptr [esp]
// 006d4593  a1d02cb900           mov eax, dword ptr [0xb92cd0]
// 006d4598  64890d00000000       mov dword ptr fs:[0], ecx
// 006d459f  83c40c               add esp, 0xc
// 006d45a2  c3                   ret 

extern char string_00b6313c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b6313c);
    return *name;
}
