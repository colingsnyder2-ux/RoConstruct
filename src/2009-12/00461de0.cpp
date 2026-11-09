// from server: 100% by nuck16
// roc 2009-12 00461de0  unit: CRobloxWnd::PartDropTarget  size: 99 bytes
//
// 00461de0  64a100000000         mov eax, dword ptr fs:[0]
// 00461de6  6aff                 push -1
// 00461de8  68cecb9200           push 0x92cbce
// 00461ded  50                   push eax
// 00461dee  b801000000           mov eax, 1
// 00461df3  64892500000000       mov dword ptr fs:[0], esp
// 00461dfa  84057cb9b700         test byte ptr [0xb7b97c], al
// 00461e00  752e                 jne 0x461e30
// 00461e02  09057cb9b700         or dword ptr [0xb7b97c], eax
// 00461e08  685c0fb400           push 0xb40f5c
// 00461e0d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00461e15  e8c6041d00           call 0x6322e0
// 00461e1a  83c404               add esp, 4
// 00461e1d  a378b9b700           mov dword ptr [0xb7b978], eax
// 00461e22  8b0c24               mov ecx, dword ptr [esp]
// 00461e25  64890d00000000       mov dword ptr fs:[0], ecx
// 00461e2c  83c40c               add esp, 0xc
// 00461e2f  c3                   ret 
// 00461e30  8b0c24               mov ecx, dword ptr [esp]
// 00461e33  a178b9b700           mov eax, dword ptr [0xb7b978]
// 00461e38  64890d00000000       mov dword ptr fs:[0], ecx
// 00461e3f  83c40c               add esp, 0xc
// 00461e42  c3                   ret 

extern char string_00b40f5c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b40f5c);
    return *name;
}
