// from server: 100% by nuck16
// roc 2009-12 00461c20  unit: CRobloxWnd::PartDropTarget  size: 99 bytes
//
// 00461c20  64a100000000         mov eax, dword ptr fs:[0]
// 00461c26  6aff                 push -1
// 00461c28  684ecb9200           push 0x92cb4e
// 00461c2d  50                   push eax
// 00461c2e  b801000000           mov eax, 1
// 00461c33  64892500000000       mov dword ptr fs:[0], esp
// 00461c3a  84055cb9b700         test byte ptr [0xb7b95c], al
// 00461c40  752e                 jne 0x461c70
// 00461c42  09055cb9b700         or dword ptr [0xb7b95c], eax
// 00461c48  68b409b400           push 0xb409b4
// 00461c4d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00461c55  e886061d00           call 0x6322e0
// 00461c5a  83c404               add esp, 4
// 00461c5d  a358b9b700           mov dword ptr [0xb7b958], eax
// 00461c62  8b0c24               mov ecx, dword ptr [esp]
// 00461c65  64890d00000000       mov dword ptr fs:[0], ecx
// 00461c6c  83c40c               add esp, 0xc
// 00461c6f  c3                   ret 
// 00461c70  8b0c24               mov ecx, dword ptr [esp]
// 00461c73  a158b9b700           mov eax, dword ptr [0xb7b958]
// 00461c78  64890d00000000       mov dword ptr fs:[0], ecx
// 00461c7f  83c40c               add esp, 0xc
// 00461c82  c3                   ret 

extern char string_00b409b4[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b409b4);
    return *name;
}
