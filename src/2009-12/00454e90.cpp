// from server: 100% by nuck16
// roc 2009-12 00454e90  unit: VCWorkspace::?$CComObject  size: 99 bytes
//
// 00454e90  64a100000000         mov eax, dword ptr fs:[0]
// 00454e96  6aff                 push -1
// 00454e98  683eb69200           push 0x92b63e
// 00454e9d  50                   push eax
// 00454e9e  b801000000           mov eax, 1
// 00454ea3  64892500000000       mov dword ptr fs:[0], esp
// 00454eaa  8405ccb7b700         test byte ptr [0xb7b7cc], al
// 00454eb0  752e                 jne 0x454ee0
// 00454eb2  0905ccb7b700         or dword ptr [0xb7b7cc], eax
// 00454eb8  6884e8b300           push 0xb3e884
// 00454ebd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00454ec5  e816d41d00           call 0x6322e0
// 00454eca  83c404               add esp, 4
// 00454ecd  a3c8b7b700           mov dword ptr [0xb7b7c8], eax
// 00454ed2  8b0c24               mov ecx, dword ptr [esp]
// 00454ed5  64890d00000000       mov dword ptr fs:[0], ecx
// 00454edc  83c40c               add esp, 0xc
// 00454edf  c3                   ret 
// 00454ee0  8b0c24               mov ecx, dword ptr [esp]
// 00454ee3  a1c8b7b700           mov eax, dword ptr [0xb7b7c8]
// 00454ee8  64890d00000000       mov dword ptr fs:[0], ecx
// 00454eef  83c40c               add esp, 0xc
// 00454ef2  c3                   ret 

extern char string_00b3e884[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3e884);
    return *name;
}
