// from server: 100% by nuck16
// roc 2009-12 0040aba0  unit: RBX::Reflection::Metadata::VClasses::?$FactoryProduct  size: 99 bytes
//
// 0040aba0  64a100000000         mov eax, dword ptr fs:[0]
// 0040aba6  6aff                 push -1
// 0040aba8  68be769200           push 0x9276be
// 0040abad  50                   push eax
// 0040abae  b801000000           mov eax, 1
// 0040abb3  64892500000000       mov dword ptr fs:[0], esp
// 0040abba  8405349ab700         test byte ptr [0xb79a34], al
// 0040abc0  752e                 jne 0x40abf0
// 0040abc2  0905349ab700         or dword ptr [0xb79a34], eax
// 0040abc8  68006cb000           push 0xb06c00
// 0040abcd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0040abd5  e806772200           call 0x6322e0
// 0040abda  83c404               add esp, 4
// 0040abdd  a3309ab700           mov dword ptr [0xb79a30], eax
// 0040abe2  8b0c24               mov ecx, dword ptr [esp]
// 0040abe5  64890d00000000       mov dword ptr fs:[0], ecx
// 0040abec  83c40c               add esp, 0xc
// 0040abef  c3                   ret 
// 0040abf0  8b0c24               mov ecx, dword ptr [esp]
// 0040abf3  a1309ab700           mov eax, dword ptr [0xb79a30]
// 0040abf8  64890d00000000       mov dword ptr fs:[0], ecx
// 0040abff  83c40c               add esp, 0xc
// 0040ac02  c3                   ret 

extern char string_00b06c00[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b06c00);
    return *name;
}
