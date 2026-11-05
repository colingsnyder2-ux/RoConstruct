// from server: 100% by nuck16
// roc 2009-12 00476ac0  unit: VCWorkspace::?$CComObject  size: 99 bytes
//
// 00476ac0  64a100000000         mov eax, dword ptr fs:[0]
// 00476ac6  6aff                 push -1
// 00476ac8  682edf9200           push 0x92df2e
// 00476acd  50                   push eax
// 00476ace  b801000000           mov eax, 1
// 00476ad3  64892500000000       mov dword ptr fs:[0], esp
// 00476ada  840508cab700         test byte ptr [0xb7ca08], al
// 00476ae0  752e                 jne 0x476b10
// 00476ae2  090508cab700         or dword ptr [0xb7ca08], eax
// 00476ae8  68fc24b400           push 0xb424fc
// 00476aed  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00476af5  e8e6b71b00           call 0x6322e0
// 00476afa  83c404               add esp, 4
// 00476afd  a304cab700           mov dword ptr [0xb7ca04], eax
// 00476b02  8b0c24               mov ecx, dword ptr [esp]
// 00476b05  64890d00000000       mov dword ptr fs:[0], ecx
// 00476b0c  83c40c               add esp, 0xc
// 00476b0f  c3                   ret 
// 00476b10  8b0c24               mov ecx, dword ptr [esp]
// 00476b13  a104cab700           mov eax, dword ptr [0xb7ca04]
// 00476b18  64890d00000000       mov dword ptr fs:[0], ecx
// 00476b1f  83c40c               add esp, 0xc
// 00476b22  c3                   ret 

extern char string_00b424fc[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b424fc);
    return *name;
}
