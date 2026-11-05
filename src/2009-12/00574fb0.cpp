// from server: 100% by nuck16
// roc 2009-12 00574fb0  unit: RBX::ViewRbxGfx  size: 99 bytes
//
// 00574fb0  64a100000000         mov eax, dword ptr fs:[0]
// 00574fb6  6aff                 push -1
// 00574fb8  689ebc9300           push 0x93bc9e
// 00574fbd  50                   push eax
// 00574fbe  b801000000           mov eax, 1
// 00574fc3  64892500000000       mov dword ptr fs:[0], esp
// 00574fca  84052c27b800         test byte ptr [0xb8272c], al
// 00574fd0  752e                 jne 0x575000
// 00574fd2  09052c27b800         or dword ptr [0xb8272c], eax
// 00574fd8  68ecd5b400           push 0xb4d5ec
// 00574fdd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00574fe5  e8f6d20b00           call 0x6322e0
// 00574fea  83c404               add esp, 4
// 00574fed  a32827b800           mov dword ptr [0xb82728], eax
// 00574ff2  8b0c24               mov ecx, dword ptr [esp]
// 00574ff5  64890d00000000       mov dword ptr fs:[0], ecx
// 00574ffc  83c40c               add esp, 0xc
// 00574fff  c3                   ret 
// 00575000  8b0c24               mov ecx, dword ptr [esp]
// 00575003  a12827b800           mov eax, dword ptr [0xb82728]
// 00575008  64890d00000000       mov dword ptr fs:[0], ecx
// 0057500f  83c40c               add esp, 0xc
// 00575012  c3                   ret 

extern char string_00b4d5ec[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4d5ec);
    return *name;
}
