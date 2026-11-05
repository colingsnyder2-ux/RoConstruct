// from server: 100% by nuck16
// roc 2009-12 00401330  unit: CAboutRobloxDialog  size: 99 bytes
//
// 00401330  64a100000000         mov eax, dword ptr fs:[0]
// 00401336  6aff                 push -1
// 00401338  682e6f9200           push 0x926f2e
// 0040133d  50                   push eax
// 0040133e  b801000000           mov eax, 1
// 00401343  64892500000000       mov dword ptr fs:[0], esp
// 0040134a  84050c94b700         test byte ptr [0xb7940c], al
// 00401350  752e                 jne 0x401380
// 00401352  09050c94b700         or dword ptr [0xb7940c], eax
// 00401358  68b8ac9c00           push 0x9cacb8
// 0040135d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00401365  e8760f2300           call 0x6322e0
// 0040136a  83c404               add esp, 4
// 0040136d  a30894b700           mov dword ptr [0xb79408], eax
// 00401372  8b0c24               mov ecx, dword ptr [esp]
// 00401375  64890d00000000       mov dword ptr fs:[0], ecx
// 0040137c  83c40c               add esp, 0xc
// 0040137f  c3                   ret 
// 00401380  8b0c24               mov ecx, dword ptr [esp]
// 00401383  a10894b700           mov eax, dword ptr [0xb79408]
// 00401388  64890d00000000       mov dword ptr fs:[0], ecx
// 0040138f  83c40c               add esp, 0xc
// 00401392  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("DebugSettings");
    return *name;
}
