// from server: 100% by nuck16
// roc 2009-12 00408fb0  unit: RBX::Network::VPlayer::?$FactoryProduct::Creator  size: 99 bytes
//
// 00408fb0  64a100000000         mov eax, dword ptr fs:[0]
// 00408fb6  6aff                 push -1
// 00408fb8  68de739200           push 0x9273de
// 00408fbd  50                   push eax
// 00408fbe  b801000000           mov eax, 1
// 00408fc3  64892500000000       mov dword ptr fs:[0], esp
// 00408fca  8405c495b700         test byte ptr [0xb795c4], al
// 00408fd0  752e                 jne 0x409000
// 00408fd2  0905c495b700         or dword ptr [0xb795c4], eax
// 00408fd8  68d06bb000           push 0xb06bd0
// 00408fdd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00408fe5  e8f6922200           call 0x6322e0
// 00408fea  83c404               add esp, 4
// 00408fed  a3c095b700           mov dword ptr [0xb795c0], eax
// 00408ff2  8b0c24               mov ecx, dword ptr [esp]
// 00408ff5  64890d00000000       mov dword ptr fs:[0], ecx
// 00408ffc  83c40c               add esp, 0xc
// 00408fff  c3                   ret 
// 00409000  8b0c24               mov ecx, dword ptr [esp]
// 00409003  a1c095b700           mov eax, dword ptr [0xb795c0]
// 00409008  64890d00000000       mov dword ptr fs:[0], ecx
// 0040900f  83c40c               add esp, 0xc
// 00409012  c3                   ret 

extern char string_00b06bd0[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b06bd0);
    return *name;
}
