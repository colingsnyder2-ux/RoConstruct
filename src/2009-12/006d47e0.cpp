// from server: 100% by nuck16
// roc 2009-12 006d47e0  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d47e0  64a100000000         mov eax, dword ptr fs:[0]
// 006d47e6  6aff                 push -1
// 006d47e8  688ea59400           push 0x94a58e
// 006d47ed  50                   push eax
// 006d47ee  b801000000           mov eax, 1
// 006d47f3  64892500000000       mov dword ptr fs:[0], esp
// 006d47fa  8405042db900         test byte ptr [0xb92d04], al
// 006d4800  752e                 jne 0x6d4830
// 006d4802  0905042db900         or dword ptr [0xb92d04], eax
// 006d4808  685032b600           push 0xb63250
// 006d480d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d4815  e8c6daf5ff           call 0x6322e0
// 006d481a  83c404               add esp, 4
// 006d481d  a3002db900           mov dword ptr [0xb92d00], eax
// 006d4822  8b0c24               mov ecx, dword ptr [esp]
// 006d4825  64890d00000000       mov dword ptr fs:[0], ecx
// 006d482c  83c40c               add esp, 0xc
// 006d482f  c3                   ret 
// 006d4830  8b0c24               mov ecx, dword ptr [esp]
// 006d4833  a1002db900           mov eax, dword ptr [0xb92d00]
// 006d4838  64890d00000000       mov dword ptr fs:[0], ecx
// 006d483f  83c40c               add esp, 0xc
// 006d4842  c3                   ret 

extern char string_00b63250[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b63250);
    return *name;
}
