// from server: 100% by nuck16
// roc 2009-12 004092c0  unit: RBX::Network::VPlayer::?$FactoryProduct::Creator  size: 99 bytes
//
// 004092c0  64a100000000         mov eax, dword ptr fs:[0]
// 004092c6  6aff                 push -1
// 004092c8  68be749200           push 0x9274be
// 004092cd  50                   push eax
// 004092ce  b801000000           mov eax, 1
// 004092d3  64892500000000       mov dword ptr fs:[0], esp
// 004092da  8405fc95b700         test byte ptr [0xb795fc], al
// 004092e0  752e                 jne 0x409310
// 004092e2  0905fc95b700         or dword ptr [0xb795fc], eax
// 004092e8  6860fd9900           push 0x99fd60
// 004092ed  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004092f5  e8e68f2200           call 0x6322e0
// 004092fa  83c404               add esp, 4
// 004092fd  a3f895b700           mov dword ptr [0xb795f8], eax
// 00409302  8b0c24               mov ecx, dword ptr [esp]
// 00409305  64890d00000000       mov dword ptr fs:[0], ecx
// 0040930c  83c40c               add esp, 0xc
// 0040930f  c3                   ret 
// 00409310  8b0c24               mov ecx, dword ptr [esp]
// 00409313  a1f895b700           mov eax, dword ptr [0xb795f8]
// 00409318  64890d00000000       mov dword ptr fs:[0], ecx
// 0040931f  83c40c               add esp, 0xc
// 00409322  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Authoring");
    return *name;
}
