// from server: 100% by nuck16
// roc 2009-12 00461fa0  unit: CRobloxWnd::PartDropTarget  size: 99 bytes
//
// 00461fa0  64a100000000         mov eax, dword ptr fs:[0]
// 00461fa6  6aff                 push -1
// 00461fa8  684ecc9200           push 0x92cc4e
// 00461fad  50                   push eax
// 00461fae  b801000000           mov eax, 1
// 00461fb3  64892500000000       mov dword ptr fs:[0], esp
// 00461fba  84059cb9b700         test byte ptr [0xb7b99c], al
// 00461fc0  752e                 jne 0x461ff0
// 00461fc2  09059cb9b700         or dword ptr [0xb7b99c], eax
// 00461fc8  681822b400           push 0xb42218
// 00461fcd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00461fd5  e806031d00           call 0x6322e0
// 00461fda  83c404               add esp, 4
// 00461fdd  a398b9b700           mov dword ptr [0xb7b998], eax
// 00461fe2  8b0c24               mov ecx, dword ptr [esp]
// 00461fe5  64890d00000000       mov dword ptr fs:[0], ecx
// 00461fec  83c40c               add esp, 0xc
// 00461fef  c3                   ret 
// 00461ff0  8b0c24               mov ecx, dword ptr [esp]
// 00461ff3  a198b9b700           mov eax, dword ptr [0xb7b998]
// 00461ff8  64890d00000000       mov dword ptr fs:[0], ecx
// 00461fff  83c40c               add esp, 0xc
// 00462002  c3                   ret 

extern char string_00b42218[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b42218);
    return *name;
}
