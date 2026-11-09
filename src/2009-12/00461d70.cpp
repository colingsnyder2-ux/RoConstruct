// from server: 100% by nuck16
// roc 2009-12 00461d70  unit: CRobloxWnd::PartDropTarget  size: 99 bytes
//
// 00461d70  64a100000000         mov eax, dword ptr fs:[0]
// 00461d76  6aff                 push -1
// 00461d78  68aecb9200           push 0x92cbae
// 00461d7d  50                   push eax
// 00461d7e  b801000000           mov eax, 1
// 00461d83  64892500000000       mov dword ptr fs:[0], esp
// 00461d8a  840574b9b700         test byte ptr [0xb7b974], al
// 00461d90  752e                 jne 0x461dc0
// 00461d92  090574b9b700         or dword ptr [0xb7b974], eax
// 00461d98  68ecffb300           push 0xb3ffec
// 00461d9d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00461da5  e836051d00           call 0x6322e0
// 00461daa  83c404               add esp, 4
// 00461dad  a370b9b700           mov dword ptr [0xb7b970], eax
// 00461db2  8b0c24               mov ecx, dword ptr [esp]
// 00461db5  64890d00000000       mov dword ptr fs:[0], ecx
// 00461dbc  83c40c               add esp, 0xc
// 00461dbf  c3                   ret 
// 00461dc0  8b0c24               mov ecx, dword ptr [esp]
// 00461dc3  a170b9b700           mov eax, dword ptr [0xb7b970]
// 00461dc8  64890d00000000       mov dword ptr fs:[0], ecx
// 00461dcf  83c40c               add esp, 0xc
// 00461dd2  c3                   ret 

extern char string_00b3ffec[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3ffec);
    return *name;
}
