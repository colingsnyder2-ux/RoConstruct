// from server: 100% by nuck16
// roc 2009-12 006d41c0  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d41c0  64a100000000         mov eax, dword ptr fs:[0]
// 006d41c6  6aff                 push -1
// 006d41c8  68cea39400           push 0x94a3ce
// 006d41cd  50                   push eax
// 006d41ce  b801000000           mov eax, 1
// 006d41d3  64892500000000       mov dword ptr fs:[0], esp
// 006d41da  8405942cb900         test byte ptr [0xb92c94], al
// 006d41e0  752e                 jne 0x6d4210
// 006d41e2  0905942cb900         or dword ptr [0xb92c94], eax
// 006d41e8  685824b600           push 0xb62458
// 006d41ed  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d41f5  e8e6e0f5ff           call 0x6322e0
// 006d41fa  83c404               add esp, 4
// 006d41fd  a3902cb900           mov dword ptr [0xb92c90], eax
// 006d4202  8b0c24               mov ecx, dword ptr [esp]
// 006d4205  64890d00000000       mov dword ptr fs:[0], ecx
// 006d420c  83c40c               add esp, 0xc
// 006d420f  c3                   ret 
// 006d4210  8b0c24               mov ecx, dword ptr [esp]
// 006d4213  a1902cb900           mov eax, dword ptr [0xb92c90]
// 006d4218  64890d00000000       mov dword ptr fs:[0], ecx
// 006d421f  83c40c               add esp, 0xc
// 006d4222  c3                   ret 

extern char string_00b62458[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b62458);
    return *name;
}
