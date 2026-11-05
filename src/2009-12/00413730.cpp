// from server: 100% by nuck16
// roc 2009-12 00413730  unit: CutVerb  size: 99 bytes
//
// 00413730  64a100000000         mov eax, dword ptr fs:[0]
// 00413736  6aff                 push -1
// 00413738  683e7e9200           push 0x927e3e
// 0041373d  50                   push eax
// 0041373e  b801000000           mov eax, 1
// 00413743  64892500000000       mov dword ptr fs:[0], esp
// 0041374a  8405f4a0b700         test byte ptr [0xb7a0f4], al
// 00413750  752e                 jne 0x413780
// 00413752  0905f4a0b700         or dword ptr [0xb7a0f4], eax
// 00413758  687059b300           push 0xb35970
// 0041375d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00413765  e876eb2100           call 0x6322e0
// 0041376a  83c404               add esp, 4
// 0041376d  a3f0a0b700           mov dword ptr [0xb7a0f0], eax
// 00413772  8b0c24               mov ecx, dword ptr [esp]
// 00413775  64890d00000000       mov dword ptr fs:[0], ecx
// 0041377c  83c40c               add esp, 0xc
// 0041377f  c3                   ret 
// 00413780  8b0c24               mov ecx, dword ptr [esp]
// 00413783  a1f0a0b700           mov eax, dword ptr [0xb7a0f0]
// 00413788  64890d00000000       mov dword ptr fs:[0], ecx
// 0041378f  83c40c               add esp, 0xc
// 00413792  c3                   ret 

extern char string_00b35970[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b35970);
    return *name;
}
