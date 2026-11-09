// from server: 100% by nuck16
// roc 2009-12 006d4690  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d4690  64a100000000         mov eax, dword ptr fs:[0]
// 006d4696  6aff                 push -1
// 006d4698  682ea59400           push 0x94a52e
// 006d469d  50                   push eax
// 006d469e  b801000000           mov eax, 1
// 006d46a3  64892500000000       mov dword ptr fs:[0], esp
// 006d46aa  8405ec2cb900         test byte ptr [0xb92cec], al
// 006d46b0  752e                 jne 0x6d46e0
// 006d46b2  0905ec2cb900         or dword ptr [0xb92cec], eax
// 006d46b8  683423b600           push 0xb62334
// 006d46bd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d46c5  e816dcf5ff           call 0x6322e0
// 006d46ca  83c404               add esp, 4
// 006d46cd  a3e82cb900           mov dword ptr [0xb92ce8], eax
// 006d46d2  8b0c24               mov ecx, dword ptr [esp]
// 006d46d5  64890d00000000       mov dword ptr fs:[0], ecx
// 006d46dc  83c40c               add esp, 0xc
// 006d46df  c3                   ret 
// 006d46e0  8b0c24               mov ecx, dword ptr [esp]
// 006d46e3  a1e82cb900           mov eax, dword ptr [0xb92ce8]
// 006d46e8  64890d00000000       mov dword ptr fs:[0], ecx
// 006d46ef  83c40c               add esp, 0xc
// 006d46f2  c3                   ret 

extern char string_00b62334[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b62334);
    return *name;
}
