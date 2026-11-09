// from server: 100% by nuck16
// roc 2009-12 0045bb90  unit: CRobloxReportPaneView  size: 99 bytes
//
// 0045bb90  64a100000000         mov eax, dword ptr fs:[0]
// 0045bb96  6aff                 push -1
// 0045bb98  682ec39200           push 0x92c32e
// 0045bb9d  50                   push eax
// 0045bb9e  b801000000           mov eax, 1
// 0045bba3  64892500000000       mov dword ptr fs:[0], esp
// 0045bbaa  840530b8b700         test byte ptr [0xb7b830], al
// 0045bbb0  752e                 jne 0x45bbe0
// 0045bbb2  090530b8b700         or dword ptr [0xb7b830], eax
// 0045bbb8  68e4ffb300           push 0xb3ffe4
// 0045bbbd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0045bbc5  e816671d00           call 0x6322e0
// 0045bbca  83c404               add esp, 4
// 0045bbcd  a32cb8b700           mov dword ptr [0xb7b82c], eax
// 0045bbd2  8b0c24               mov ecx, dword ptr [esp]
// 0045bbd5  64890d00000000       mov dword ptr fs:[0], ecx
// 0045bbdc  83c40c               add esp, 0xc
// 0045bbdf  c3                   ret 
// 0045bbe0  8b0c24               mov ecx, dword ptr [esp]
// 0045bbe3  a12cb8b700           mov eax, dword ptr [0xb7b82c]
// 0045bbe8  64890d00000000       mov dword ptr fs:[0], ecx
// 0045bbef  83c40c               add esp, 0xc
// 0045bbf2  c3                   ret 

extern char string_00b3ffe4[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3ffe4);
    return *name;
}
