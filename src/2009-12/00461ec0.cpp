// from server: 100% by nuck16
// roc 2009-12 00461ec0  unit: CRobloxWnd::PartDropTarget  size: 99 bytes
//
// 00461ec0  64a100000000         mov eax, dword ptr fs:[0]
// 00461ec6  6aff                 push -1
// 00461ec8  680ecc9200           push 0x92cc0e
// 00461ecd  50                   push eax
// 00461ece  b801000000           mov eax, 1
// 00461ed3  64892500000000       mov dword ptr fs:[0], esp
// 00461eda  84058cb9b700         test byte ptr [0xb7b98c], al
// 00461ee0  752e                 jne 0x461f10
// 00461ee2  09058cb9b700         or dword ptr [0xb7b98c], eax
// 00461ee8  68841ab400           push 0xb41a84
// 00461eed  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00461ef5  e8e6031d00           call 0x6322e0
// 00461efa  83c404               add esp, 4
// 00461efd  a388b9b700           mov dword ptr [0xb7b988], eax
// 00461f02  8b0c24               mov ecx, dword ptr [esp]
// 00461f05  64890d00000000       mov dword ptr fs:[0], ecx
// 00461f0c  83c40c               add esp, 0xc
// 00461f0f  c3                   ret 
// 00461f10  8b0c24               mov ecx, dword ptr [esp]
// 00461f13  a188b9b700           mov eax, dword ptr [0xb7b988]
// 00461f18  64890d00000000       mov dword ptr fs:[0], ecx
// 00461f1f  83c40c               add esp, 0xc
// 00461f22  c3                   ret 

extern char string_00b41a84[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b41a84);
    return *name;
}
