// from server: 100% by nuck16
// roc 2009-12 00432f10  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 99 bytes
//
// 00432f10  64a100000000         mov eax, dword ptr fs:[0]
// 00432f16  6aff                 push -1
// 00432f18  68ee9e9200           push 0x929eee
// 00432f1d  50                   push eax
// 00432f1e  b801000000           mov eax, 1
// 00432f23  64892500000000       mov dword ptr fs:[0], esp
// 00432f2a  840558a3b700         test byte ptr [0xb7a358], al
// 00432f30  752e                 jne 0x432f60
// 00432f32  090558a3b700         or dword ptr [0xb7a358], eax
// 00432f38  6868a7b300           push 0xb3a768
// 00432f3d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00432f45  e896f31f00           call 0x6322e0
// 00432f4a  83c404               add esp, 4
// 00432f4d  a354a3b700           mov dword ptr [0xb7a354], eax
// 00432f52  8b0c24               mov ecx, dword ptr [esp]
// 00432f55  64890d00000000       mov dword ptr fs:[0], ecx
// 00432f5c  83c40c               add esp, 0xc
// 00432f5f  c3                   ret 
// 00432f60  8b0c24               mov ecx, dword ptr [esp]
// 00432f63  a154a3b700           mov eax, dword ptr [0xb7a354]
// 00432f68  64890d00000000       mov dword ptr fs:[0], ecx
// 00432f6f  83c40c               add esp, 0xc
// 00432f72  c3                   ret 

extern char string_00b3a768[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3a768);
    return *name;
}
