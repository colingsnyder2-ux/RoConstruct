// from server: 100% by nuck16
// roc 2009-12 004091e0  unit: RBX::Network::VPlayer::?$FactoryProduct::Creator  size: 99 bytes
//
// 004091e0  64a100000000         mov eax, dword ptr fs:[0]
// 004091e6  6aff                 push -1
// 004091e8  687e749200           push 0x92747e
// 004091ed  50                   push eax
// 004091ee  b801000000           mov eax, 1
// 004091f3  64892500000000       mov dword ptr fs:[0], esp
// 004091fa  8405ec95b700         test byte ptr [0xb795ec], al
// 00409200  752e                 jne 0x409230
// 00409202  0905ec95b700         or dword ptr [0xb795ec], eax
// 00409208  686c6cb000           push 0xb06c6c
// 0040920d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00409215  e8c6902200           call 0x6322e0
// 0040921a  83c404               add esp, 4
// 0040921d  a3e895b700           mov dword ptr [0xb795e8], eax
// 00409222  8b0c24               mov ecx, dword ptr [esp]
// 00409225  64890d00000000       mov dword ptr fs:[0], ecx
// 0040922c  83c40c               add esp, 0xc
// 0040922f  c3                   ret 
// 00409230  8b0c24               mov ecx, dword ptr [esp]
// 00409233  a1e895b700           mov eax, dword ptr [0xb795e8]
// 00409238  64890d00000000       mov dword ptr fs:[0], ecx
// 0040923f  83c40c               add esp, 0xc
// 00409242  c3                   ret 

extern char string_00b06c6c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b06c6c);
    return *name;
}
