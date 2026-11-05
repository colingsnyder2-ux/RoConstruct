// from server: 100% by nuck16
// roc 2009-12 0044bd10  unit: CRobloxApp  size: 99 bytes
//
// 0044bd10  64a100000000         mov eax, dword ptr fs:[0]
// 0044bd16  6aff                 push -1
// 0044bd18  68eead9200           push 0x92adee
// 0044bd1d  50                   push eax
// 0044bd1e  b801000000           mov eax, 1
// 0044bd23  64892500000000       mov dword ptr fs:[0], esp
// 0044bd2a  84056cb4b700         test byte ptr [0xb7b46c], al
// 0044bd30  752e                 jne 0x44bd60
// 0044bd32  09056cb4b700         or dword ptr [0xb7b46c], eax
// 0044bd38  68b0cdb300           push 0xb3cdb0
// 0044bd3d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0044bd45  e896651e00           call 0x6322e0
// 0044bd4a  83c404               add esp, 4
// 0044bd4d  a368b4b700           mov dword ptr [0xb7b468], eax
// 0044bd52  8b0c24               mov ecx, dword ptr [esp]
// 0044bd55  64890d00000000       mov dword ptr fs:[0], ecx
// 0044bd5c  83c40c               add esp, 0xc
// 0044bd5f  c3                   ret 
// 0044bd60  8b0c24               mov ecx, dword ptr [esp]
// 0044bd63  a168b4b700           mov eax, dword ptr [0xb7b468]
// 0044bd68  64890d00000000       mov dword ptr fs:[0], ecx
// 0044bd6f  83c40c               add esp, 0xc
// 0044bd72  c3                   ret 

extern char string_00b3cdb0[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3cdb0);
    return *name;
}
