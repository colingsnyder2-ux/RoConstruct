// from server: 100% by nuck16
// roc 2009-12 00432f80  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 99 bytes
//
// 00432f80  64a100000000         mov eax, dword ptr fs:[0]
// 00432f86  6aff                 push -1
// 00432f88  680e9f9200           push 0x929f0e
// 00432f8d  50                   push eax
// 00432f8e  b801000000           mov eax, 1
// 00432f93  64892500000000       mov dword ptr fs:[0], esp
// 00432f9a  840560a3b700         test byte ptr [0xb7a360], al
// 00432fa0  752e                 jne 0x432fd0
// 00432fa2  090560a3b700         or dword ptr [0xb7a360], eax
// 00432fa8  68fcb8b300           push 0xb3b8fc
// 00432fad  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00432fb5  e826f31f00           call 0x6322e0
// 00432fba  83c404               add esp, 4
// 00432fbd  a35ca3b700           mov dword ptr [0xb7a35c], eax
// 00432fc2  8b0c24               mov ecx, dword ptr [esp]
// 00432fc5  64890d00000000       mov dword ptr fs:[0], ecx
// 00432fcc  83c40c               add esp, 0xc
// 00432fcf  c3                   ret 
// 00432fd0  8b0c24               mov ecx, dword ptr [esp]
// 00432fd3  a15ca3b700           mov eax, dword ptr [0xb7a35c]
// 00432fd8  64890d00000000       mov dword ptr fs:[0], ecx
// 00432fdf  83c40c               add esp, 0xc
// 00432fe2  c3                   ret 

extern char string_00b3b8fc[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3b8fc);
    return *name;
}
