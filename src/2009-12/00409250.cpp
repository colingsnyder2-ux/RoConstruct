// from server: 100% by nuck16
// roc 2009-12 00409250  unit: RBX::Network::VPlayer::?$FactoryProduct::Creator  size: 99 bytes
//
// 00409250  64a100000000         mov eax, dword ptr fs:[0]
// 00409256  6aff                 push -1
// 00409258  689e749200           push 0x92749e
// 0040925d  50                   push eax
// 0040925e  b801000000           mov eax, 1
// 00409263  64892500000000       mov dword ptr fs:[0], esp
// 0040926a  8405f495b700         test byte ptr [0xb795f4], al
// 00409270  752e                 jne 0x4092a0
// 00409272  0905f495b700         or dword ptr [0xb795f4], eax
// 00409278  68886cb000           push 0xb06c88
// 0040927d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00409285  e856902200           call 0x6322e0
// 0040928a  83c404               add esp, 4
// 0040928d  a3f095b700           mov dword ptr [0xb795f0], eax
// 00409292  8b0c24               mov ecx, dword ptr [esp]
// 00409295  64890d00000000       mov dword ptr fs:[0], ecx
// 0040929c  83c40c               add esp, 0xc
// 0040929f  c3                   ret 
// 004092a0  8b0c24               mov ecx, dword ptr [esp]
// 004092a3  a1f095b700           mov eax, dword ptr [0xb795f0]
// 004092a8  64890d00000000       mov dword ptr fs:[0], ecx
// 004092af  83c40c               add esp, 0xc
// 004092b2  c3                   ret 

extern char string_00b06c88[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b06c88);
    return *name;
}
