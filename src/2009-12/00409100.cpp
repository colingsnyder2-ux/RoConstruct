// from server: 100% by nuck16
// roc 2009-12 00409100  unit: RBX::Network::VPlayer::?$FactoryProduct::Creator  size: 99 bytes
//
// 00409100  64a100000000         mov eax, dword ptr fs:[0]
// 00409106  6aff                 push -1
// 00409108  683e749200           push 0x92743e
// 0040910d  50                   push eax
// 0040910e  b801000000           mov eax, 1
// 00409113  64892500000000       mov dword ptr fs:[0], esp
// 0040911a  8405dc95b700         test byte ptr [0xb795dc], al
// 00409120  752e                 jne 0x409150
// 00409122  0905dc95b700         or dword ptr [0xb795dc], eax
// 00409128  68306cb000           push 0xb06c30
// 0040912d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00409135  e8a6912200           call 0x6322e0
// 0040913a  83c404               add esp, 4
// 0040913d  a3d895b700           mov dword ptr [0xb795d8], eax
// 00409142  8b0c24               mov ecx, dword ptr [esp]
// 00409145  64890d00000000       mov dword ptr fs:[0], ecx
// 0040914c  83c40c               add esp, 0xc
// 0040914f  c3                   ret 
// 00409150  8b0c24               mov ecx, dword ptr [esp]
// 00409153  a1d895b700           mov eax, dword ptr [0xb795d8]
// 00409158  64890d00000000       mov dword ptr fs:[0], ecx
// 0040915f  83c40c               add esp, 0xc
// 00409162  c3                   ret 

extern char string_00b06c30[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b06c30);
    return *name;
}
