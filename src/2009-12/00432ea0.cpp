// from server: 100% by nuck16
// roc 2009-12 00432ea0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 99 bytes
//
// 00432ea0  64a100000000         mov eax, dword ptr fs:[0]
// 00432ea6  6aff                 push -1
// 00432ea8  68ce9e9200           push 0x929ece
// 00432ead  50                   push eax
// 00432eae  b801000000           mov eax, 1
// 00432eb3  64892500000000       mov dword ptr fs:[0], esp
// 00432eba  840550a3b700         test byte ptr [0xb7a350], al
// 00432ec0  752e                 jne 0x432ef0
// 00432ec2  090550a3b700         or dword ptr [0xb7a350], eax
// 00432ec8  684ca7b300           push 0xb3a74c
// 00432ecd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00432ed5  e806f41f00           call 0x6322e0
// 00432eda  83c404               add esp, 4
// 00432edd  a34ca3b700           mov dword ptr [0xb7a34c], eax
// 00432ee2  8b0c24               mov ecx, dword ptr [esp]
// 00432ee5  64890d00000000       mov dword ptr fs:[0], ecx
// 00432eec  83c40c               add esp, 0xc
// 00432eef  c3                   ret 
// 00432ef0  8b0c24               mov ecx, dword ptr [esp]
// 00432ef3  a14ca3b700           mov eax, dword ptr [0xb7a34c]
// 00432ef8  64890d00000000       mov dword ptr fs:[0], ecx
// 00432eff  83c40c               add esp, 0xc
// 00432f02  c3                   ret 

extern char string_00b3a74c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3a74c);
    return *name;
}
