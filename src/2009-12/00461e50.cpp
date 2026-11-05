// from server: 100% by nuck16
// roc 2009-12 00461e50  unit: CRobloxWnd::PartDropTarget  size: 99 bytes
//
// 00461e50  64a100000000         mov eax, dword ptr fs:[0]
// 00461e56  6aff                 push -1
// 00461e58  68eecb9200           push 0x92cbee
// 00461e5d  50                   push eax
// 00461e5e  b801000000           mov eax, 1
// 00461e63  64892500000000       mov dword ptr fs:[0], esp
// 00461e6a  840584b9b700         test byte ptr [0xb7b984], al
// 00461e70  752e                 jne 0x461ea0
// 00461e72  090584b9b700         or dword ptr [0xb7b984], eax
// 00461e78  68b815b400           push 0xb415b8
// 00461e7d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00461e85  e856041d00           call 0x6322e0
// 00461e8a  83c404               add esp, 4
// 00461e8d  a380b9b700           mov dword ptr [0xb7b980], eax
// 00461e92  8b0c24               mov ecx, dword ptr [esp]
// 00461e95  64890d00000000       mov dword ptr fs:[0], ecx
// 00461e9c  83c40c               add esp, 0xc
// 00461e9f  c3                   ret 
// 00461ea0  8b0c24               mov ecx, dword ptr [esp]
// 00461ea3  a180b9b700           mov eax, dword ptr [0xb7b980]
// 00461ea8  64890d00000000       mov dword ptr fs:[0], ecx
// 00461eaf  83c40c               add esp, 0xc
// 00461eb2  c3                   ret 

extern char string_00b415b8[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b415b8);
    return *name;
}
