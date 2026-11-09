// from server: 100% by nuck16
// roc 2009-12 00417590  unit: VCContent::?$CComObject  size: 99 bytes
//
// 00417590  64a100000000         mov eax, dword ptr fs:[0]
// 00417596  6aff                 push -1
// 00417598  689e819200           push 0x92819e
// 0041759d  50                   push eax
// 0041759e  b801000000           mov eax, 1
// 004175a3  64892500000000       mov dword ptr fs:[0], esp
// 004175aa  840598a1b700         test byte ptr [0xb7a198], al
// 004175b0  752e                 jne 0x4175e0
// 004175b2  090598a1b700         or dword ptr [0xb7a198], eax
// 004175b8  6800119d00           push 0x9d1100
// 004175bd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004175c5  e816ad2100           call 0x6322e0
// 004175ca  83c404               add esp, 4
// 004175cd  a394a1b700           mov dword ptr [0xb7a194], eax
// 004175d2  8b0c24               mov ecx, dword ptr [esp]
// 004175d5  64890d00000000       mov dword ptr fs:[0], ecx
// 004175dc  83c40c               add esp, 0xc
// 004175df  c3                   ret 
// 004175e0  8b0c24               mov ecx, dword ptr [esp]
// 004175e3  a194a1b700           mov eax, dword ptr [0xb7a194]
// 004175e8  64890d00000000       mov dword ptr fs:[0], ecx
// 004175ef  83c40c               add esp, 0xc
// 004175f2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("HopperBin");
    return *name;
}
