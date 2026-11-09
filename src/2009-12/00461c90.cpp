// from server: 100% by nuck16
// roc 2009-12 00461c90  unit: CRobloxWnd::PartDropTarget  size: 99 bytes
//
// 00461c90  64a100000000         mov eax, dword ptr fs:[0]
// 00461c96  6aff                 push -1
// 00461c98  686ecb9200           push 0x92cb6e
// 00461c9d  50                   push eax
// 00461c9e  b801000000           mov eax, 1
// 00461ca3  64892500000000       mov dword ptr fs:[0], esp
// 00461caa  840564b9b700         test byte ptr [0xb7b964], al
// 00461cb0  752e                 jne 0x461ce0
// 00461cb2  090564b9b700         or dword ptr [0xb7b964], eax
// 00461cb8  68c809b400           push 0xb409c8
// 00461cbd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00461cc5  e816061d00           call 0x6322e0
// 00461cca  83c404               add esp, 4
// 00461ccd  a360b9b700           mov dword ptr [0xb7b960], eax
// 00461cd2  8b0c24               mov ecx, dword ptr [esp]
// 00461cd5  64890d00000000       mov dword ptr fs:[0], ecx
// 00461cdc  83c40c               add esp, 0xc
// 00461cdf  c3                   ret 
// 00461ce0  8b0c24               mov ecx, dword ptr [esp]
// 00461ce3  a160b9b700           mov eax, dword ptr [0xb7b960]
// 00461ce8  64890d00000000       mov dword ptr fs:[0], ecx
// 00461cef  83c40c               add esp, 0xc
// 00461cf2  c3                   ret 

extern char string_00b409c8[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b409c8);
    return *name;
}
