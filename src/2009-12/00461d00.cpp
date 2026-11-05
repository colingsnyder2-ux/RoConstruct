// from server: 100% by nuck16
// roc 2009-12 00461d00  unit: CRobloxWnd::PartDropTarget  size: 99 bytes
//
// 00461d00  64a100000000         mov eax, dword ptr fs:[0]
// 00461d06  6aff                 push -1
// 00461d08  688ecb9200           push 0x92cb8e
// 00461d0d  50                   push eax
// 00461d0e  b801000000           mov eax, 1
// 00461d13  64892500000000       mov dword ptr fs:[0], esp
// 00461d1a  84056cb9b700         test byte ptr [0xb7b96c], al
// 00461d20  752e                 jne 0x461d50
// 00461d22  09056cb9b700         or dword ptr [0xb7b96c], eax
// 00461d28  68dc09b400           push 0xb409dc
// 00461d2d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00461d35  e8a6051d00           call 0x6322e0
// 00461d3a  83c404               add esp, 4
// 00461d3d  a368b9b700           mov dword ptr [0xb7b968], eax
// 00461d42  8b0c24               mov ecx, dword ptr [esp]
// 00461d45  64890d00000000       mov dword ptr fs:[0], ecx
// 00461d4c  83c40c               add esp, 0xc
// 00461d4f  c3                   ret 
// 00461d50  8b0c24               mov ecx, dword ptr [esp]
// 00461d53  a168b9b700           mov eax, dword ptr [0xb7b968]
// 00461d58  64890d00000000       mov dword ptr fs:[0], ecx
// 00461d5f  83c40c               add esp, 0xc
// 00461d62  c3                   ret 

extern char string_00b409dc[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b409dc);
    return *name;
}
