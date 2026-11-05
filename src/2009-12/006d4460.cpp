// from server: 100% by nuck16
// roc 2009-12 006d4460  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d4460  64a100000000         mov eax, dword ptr fs:[0]
// 006d4466  6aff                 push -1
// 006d4468  688ea49400           push 0x94a48e
// 006d446d  50                   push eax
// 006d446e  b801000000           mov eax, 1
// 006d4473  64892500000000       mov dword ptr fs:[0], esp
// 006d447a  8405c42cb900         test byte ptr [0xb92cc4], al
// 006d4480  752e                 jne 0x6d44b0
// 006d4482  0905c42cb900         or dword ptr [0xb92cc4], eax
// 006d4488  682431b600           push 0xb63124
// 006d448d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d4495  e846def5ff           call 0x6322e0
// 006d449a  83c404               add esp, 4
// 006d449d  a3c02cb900           mov dword ptr [0xb92cc0], eax
// 006d44a2  8b0c24               mov ecx, dword ptr [esp]
// 006d44a5  64890d00000000       mov dword ptr fs:[0], ecx
// 006d44ac  83c40c               add esp, 0xc
// 006d44af  c3                   ret 
// 006d44b0  8b0c24               mov ecx, dword ptr [esp]
// 006d44b3  a1c02cb900           mov eax, dword ptr [0xb92cc0]
// 006d44b8  64890d00000000       mov dword ptr fs:[0], ecx
// 006d44bf  83c40c               add esp, 0xc
// 006d44c2  c3                   ret 

extern char string_00b63124[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b63124);
    return *name;
}
