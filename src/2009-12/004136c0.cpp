// from server: 100% by nuck16
// roc 2009-12 004136c0  unit: CutVerb  size: 99 bytes
//
// 004136c0  64a100000000         mov eax, dword ptr fs:[0]
// 004136c6  6aff                 push -1
// 004136c8  681e7e9200           push 0x927e1e
// 004136cd  50                   push eax
// 004136ce  b801000000           mov eax, 1
// 004136d3  64892500000000       mov dword ptr fs:[0], esp
// 004136da  8405eca0b700         test byte ptr [0xb7a0ec], al
// 004136e0  752e                 jne 0x413710
// 004136e2  0905eca0b700         or dword ptr [0xb7a0ec], eax
// 004136e8  68b453b300           push 0xb353b4
// 004136ed  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004136f5  e8e6eb2100           call 0x6322e0
// 004136fa  83c404               add esp, 4
// 004136fd  a3e8a0b700           mov dword ptr [0xb7a0e8], eax
// 00413702  8b0c24               mov ecx, dword ptr [esp]
// 00413705  64890d00000000       mov dword ptr fs:[0], ecx
// 0041370c  83c40c               add esp, 0xc
// 0041370f  c3                   ret 
// 00413710  8b0c24               mov ecx, dword ptr [esp]
// 00413713  a1e8a0b700           mov eax, dword ptr [0xb7a0e8]
// 00413718  64890d00000000       mov dword ptr fs:[0], ecx
// 0041371f  83c40c               add esp, 0xc
// 00413722  c3                   ret 

extern char string_00b353b4[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b353b4);
    return *name;
}
