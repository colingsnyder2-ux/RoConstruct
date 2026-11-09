// from server: 100% by nuck16
// roc 2009-12 006d4770  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d4770  64a100000000         mov eax, dword ptr fs:[0]
// 006d4776  6aff                 push -1
// 006d4778  686ea59400           push 0x94a56e
// 006d477d  50                   push eax
// 006d477e  b801000000           mov eax, 1
// 006d4783  64892500000000       mov dword ptr fs:[0], esp
// 006d478a  8405fc2cb900         test byte ptr [0xb92cfc], al
// 006d4790  752e                 jne 0x6d47c0
// 006d4792  0905fc2cb900         or dword ptr [0xb92cfc], eax
// 006d4798  684032b600           push 0xb63240
// 006d479d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d47a5  e836dbf5ff           call 0x6322e0
// 006d47aa  83c404               add esp, 4
// 006d47ad  a3f82cb900           mov dword ptr [0xb92cf8], eax
// 006d47b2  8b0c24               mov ecx, dword ptr [esp]
// 006d47b5  64890d00000000       mov dword ptr fs:[0], ecx
// 006d47bc  83c40c               add esp, 0xc
// 006d47bf  c3                   ret 
// 006d47c0  8b0c24               mov ecx, dword ptr [esp]
// 006d47c3  a1f82cb900           mov eax, dword ptr [0xb92cf8]
// 006d47c8  64890d00000000       mov dword ptr fs:[0], ecx
// 006d47cf  83c40c               add esp, 0xc
// 006d47d2  c3                   ret 

extern char string_00b63240[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b63240);
    return *name;
}
