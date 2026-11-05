// from server: 100% by nuck16
// roc 2009-12 0075f180  unit: RBX::VDataModel::?$BoundFuncDesc  size: 99 bytes
//
// 0075f180  64a100000000         mov eax, dword ptr fs:[0]
// 0075f186  6aff                 push -1
// 0075f188  68ee1a9500           push 0x951aee
// 0075f18d  50                   push eax
// 0075f18e  b801000000           mov eax, 1
// 0075f193  64892500000000       mov dword ptr fs:[0], esp
// 0075f19a  8405bc79b900         test byte ptr [0xb979bc], al
// 0075f1a0  752e                 jne 0x75f1d0
// 0075f1a2  0905bc79b900         or dword ptr [0xb979bc], eax
// 0075f1a8  680cdcb500           push 0xb5dc0c
// 0075f1ad  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0075f1b5  e82631edff           call 0x6322e0
// 0075f1ba  83c404               add esp, 4
// 0075f1bd  a3b879b900           mov dword ptr [0xb979b8], eax
// 0075f1c2  8b0c24               mov ecx, dword ptr [esp]
// 0075f1c5  64890d00000000       mov dword ptr fs:[0], ecx
// 0075f1cc  83c40c               add esp, 0xc
// 0075f1cf  c3                   ret 
// 0075f1d0  8b0c24               mov ecx, dword ptr [esp]
// 0075f1d3  a1b879b900           mov eax, dword ptr [0xb979b8]
// 0075f1d8  64890d00000000       mov dword ptr fs:[0], ecx
// 0075f1df  83c40c               add esp, 0xc
// 0075f1e2  c3                   ret 

extern char string_00b5dc0c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5dc0c);
    return *name;
}
