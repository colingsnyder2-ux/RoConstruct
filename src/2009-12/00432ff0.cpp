// from server: 100% by nuck16
// roc 2009-12 00432ff0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 99 bytes
//
// 00432ff0  64a100000000         mov eax, dword ptr fs:[0]
// 00432ff6  6aff                 push -1
// 00432ff8  682e9f9200           push 0x929f2e
// 00432ffd  50                   push eax
// 00432ffe  b801000000           mov eax, 1
// 00433003  64892500000000       mov dword ptr fs:[0], esp
// 0043300a  840568a3b700         test byte ptr [0xb7a368], al
// 00433010  752e                 jne 0x433040
// 00433012  090568a3b700         or dword ptr [0xb7a368], eax
// 00433018  6804b9b300           push 0xb3b904
// 0043301d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00433025  e8b6f21f00           call 0x6322e0
// 0043302a  83c404               add esp, 4
// 0043302d  a364a3b700           mov dword ptr [0xb7a364], eax
// 00433032  8b0c24               mov ecx, dword ptr [esp]
// 00433035  64890d00000000       mov dword ptr fs:[0], ecx
// 0043303c  83c40c               add esp, 0xc
// 0043303f  c3                   ret 
// 00433040  8b0c24               mov ecx, dword ptr [esp]
// 00433043  a164a3b700           mov eax, dword ptr [0xb7a364]
// 00433048  64890d00000000       mov dword ptr fs:[0], ecx
// 0043304f  83c40c               add esp, 0xc
// 00433052  c3                   ret 

extern char string_00b3b904[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3b904);
    return *name;
}
