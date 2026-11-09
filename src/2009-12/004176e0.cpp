// from server: 100% by nuck16
// roc 2009-12 004176e0  unit: VCContent::?$CComObject  size: 99 bytes
//
// 004176e0  64a100000000         mov eax, dword ptr fs:[0]
// 004176e6  6aff                 push -1
// 004176e8  68fe819200           push 0x9281fe
// 004176ed  50                   push eax
// 004176ee  b801000000           mov eax, 1
// 004176f3  64892500000000       mov dword ptr fs:[0], esp
// 004176fa  8405b0a1b700         test byte ptr [0xb7a1b0], al
// 00417700  752e                 jne 0x417730
// 00417702  0905b0a1b700         or dword ptr [0xb7a1b0], eax
// 00417708  6820119d00           push 0x9d1120
// 0041770d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00417715  e8c6ab2100           call 0x6322e0
// 0041771a  83c404               add esp, 4
// 0041771d  a3aca1b700           mov dword ptr [0xb7a1ac], eax
// 00417722  8b0c24               mov ecx, dword ptr [esp]
// 00417725  64890d00000000       mov dword ptr fs:[0], ecx
// 0041772c  83c40c               add esp, 0xc
// 0041772f  c3                   ret 
// 00417730  8b0c24               mov ecx, dword ptr [esp]
// 00417733  a1aca1b700           mov eax, dword ptr [0xb7a1ac]
// 00417738  64890d00000000       mov dword ptr fs:[0], ecx
// 0041773f  83c40c               add esp, 0xc
// 00417742  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("StarterGear");
    return *name;
}
