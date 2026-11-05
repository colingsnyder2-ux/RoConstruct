// from server: 100% by nuck16
// roc 2009-12 00696140  unit: RBX::Workspace  size: 99 bytes
//
// 00696140  64a100000000         mov eax, dword ptr fs:[0]
// 00696146  6aff                 push -1
// 00696148  688e6e9400           push 0x946e8e
// 0069614d  50                   push eax
// 0069614e  b801000000           mov eax, 1
// 00696153  64892500000000       mov dword ptr fs:[0], esp
// 0069615a  84054016b900         test byte ptr [0xb91640], al
// 00696160  752e                 jne 0x696190
// 00696162  09054016b900         or dword ptr [0xb91640], eax
// 00696168  68ac22b600           push 0xb622ac
// 0069616d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00696175  e866c1f9ff           call 0x6322e0
// 0069617a  83c404               add esp, 4
// 0069617d  a33c16b900           mov dword ptr [0xb9163c], eax
// 00696182  8b0c24               mov ecx, dword ptr [esp]
// 00696185  64890d00000000       mov dword ptr fs:[0], ecx
// 0069618c  83c40c               add esp, 0xc
// 0069618f  c3                   ret 
// 00696190  8b0c24               mov ecx, dword ptr [esp]
// 00696193  a13c16b900           mov eax, dword ptr [0xb9163c]
// 00696198  64890d00000000       mov dword ptr fs:[0], ecx
// 0069619f  83c40c               add esp, 0xc
// 006961a2  c3                   ret 

extern char string_00b622ac[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b622ac);
    return *name;
}
