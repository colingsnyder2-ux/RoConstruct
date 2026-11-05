// from server: 100% by nuck16
// roc 2009-12 006d40e0  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d40e0  64a100000000         mov eax, dword ptr fs:[0]
// 006d40e6  6aff                 push -1
// 006d40e8  688ea39400           push 0x94a38e
// 006d40ed  50                   push eax
// 006d40ee  b801000000           mov eax, 1
// 006d40f3  64892500000000       mov dword ptr fs:[0], esp
// 006d40fa  8405842cb900         test byte ptr [0xb92c84], al
// 006d4100  752e                 jne 0x6d4130
// 006d4102  0905842cb900         or dword ptr [0xb92c84], eax
// 006d4108  684024b600           push 0xb62440
// 006d410d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d4115  e8c6e1f5ff           call 0x6322e0
// 006d411a  83c404               add esp, 4
// 006d411d  a3802cb900           mov dword ptr [0xb92c80], eax
// 006d4122  8b0c24               mov ecx, dword ptr [esp]
// 006d4125  64890d00000000       mov dword ptr fs:[0], ecx
// 006d412c  83c40c               add esp, 0xc
// 006d412f  c3                   ret 
// 006d4130  8b0c24               mov ecx, dword ptr [esp]
// 006d4133  a1802cb900           mov eax, dword ptr [0xb92c80]
// 006d4138  64890d00000000       mov dword ptr fs:[0], ecx
// 006d413f  83c40c               add esp, 0xc
// 006d4142  c3                   ret 

extern char string_00b62440[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b62440);
    return *name;
}
