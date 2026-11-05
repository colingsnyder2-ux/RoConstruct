// from server: 100% by nuck16
// roc 2009-12 00413810  unit: CutVerb  size: 99 bytes
//
// 00413810  64a100000000         mov eax, dword ptr fs:[0]
// 00413816  6aff                 push -1
// 00413818  687e7e9200           push 0x927e7e
// 0041381d  50                   push eax
// 0041381e  b801000000           mov eax, 1
// 00413823  64892500000000       mov dword ptr fs:[0], esp
// 0041382a  840504a1b700         test byte ptr [0xb7a104], al
// 00413830  752e                 jne 0x413860
// 00413832  090504a1b700         or dword ptr [0xb7a104], eax
// 00413838  686c60b300           push 0xb3606c
// 0041383d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00413845  e896ea2100           call 0x6322e0
// 0041384a  83c404               add esp, 4
// 0041384d  a300a1b700           mov dword ptr [0xb7a100], eax
// 00413852  8b0c24               mov ecx, dword ptr [esp]
// 00413855  64890d00000000       mov dword ptr fs:[0], ecx
// 0041385c  83c40c               add esp, 0xc
// 0041385f  c3                   ret 
// 00413860  8b0c24               mov ecx, dword ptr [esp]
// 00413863  a100a1b700           mov eax, dword ptr [0xb7a100]
// 00413868  64890d00000000       mov dword ptr fs:[0], ecx
// 0041386f  83c40c               add esp, 0xc
// 00413872  c3                   ret 

extern char string_00b3606c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3606c);
    return *name;
}
