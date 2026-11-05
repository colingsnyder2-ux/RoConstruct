// from server: 100% by nuck16
// roc 2009-12 00461f30  unit: CRobloxWnd::PartDropTarget  size: 99 bytes
//
// 00461f30  64a100000000         mov eax, dword ptr fs:[0]
// 00461f36  6aff                 push -1
// 00461f38  682ecc9200           push 0x92cc2e
// 00461f3d  50                   push eax
// 00461f3e  b801000000           mov eax, 1
// 00461f43  64892500000000       mov dword ptr fs:[0], esp
// 00461f4a  840594b9b700         test byte ptr [0xb7b994], al
// 00461f50  752e                 jne 0x461f80
// 00461f52  090594b9b700         or dword ptr [0xb7b994], eax
// 00461f58  680c1eb400           push 0xb41e0c
// 00461f5d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00461f65  e876031d00           call 0x6322e0
// 00461f6a  83c404               add esp, 4
// 00461f6d  a390b9b700           mov dword ptr [0xb7b990], eax
// 00461f72  8b0c24               mov ecx, dword ptr [esp]
// 00461f75  64890d00000000       mov dword ptr fs:[0], ecx
// 00461f7c  83c40c               add esp, 0xc
// 00461f7f  c3                   ret 
// 00461f80  8b0c24               mov ecx, dword ptr [esp]
// 00461f83  a190b9b700           mov eax, dword ptr [0xb7b990]
// 00461f88  64890d00000000       mov dword ptr fs:[0], ecx
// 00461f8f  83c40c               add esp, 0xc
// 00461f92  c3                   ret 

extern char string_00b41e0c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b41e0c);
    return *name;
}
