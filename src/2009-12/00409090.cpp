// from server: 100% by nuck16
// roc 2009-12 00409090  unit: RBX::Network::VPlayer::?$FactoryProduct::Creator  size: 99 bytes
//
// 00409090  64a100000000         mov eax, dword ptr fs:[0]
// 00409096  6aff                 push -1
// 00409098  681e749200           push 0x92741e
// 0040909d  50                   push eax
// 0040909e  b801000000           mov eax, 1
// 004090a3  64892500000000       mov dword ptr fs:[0], esp
// 004090aa  8405d495b700         test byte ptr [0xb795d4], al
// 004090b0  752e                 jne 0x4090e0
// 004090b2  0905d495b700         or dword ptr [0xb795d4], eax
// 004090b8  68186cb000           push 0xb06c18
// 004090bd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004090c5  e816922200           call 0x6322e0
// 004090ca  83c404               add esp, 4
// 004090cd  a3d095b700           mov dword ptr [0xb795d0], eax
// 004090d2  8b0c24               mov ecx, dword ptr [esp]
// 004090d5  64890d00000000       mov dword ptr fs:[0], ecx
// 004090dc  83c40c               add esp, 0xc
// 004090df  c3                   ret 
// 004090e0  8b0c24               mov ecx, dword ptr [esp]
// 004090e3  a1d095b700           mov eax, dword ptr [0xb795d0]
// 004090e8  64890d00000000       mov dword ptr fs:[0], ecx
// 004090ef  83c40c               add esp, 0xc
// 004090f2  c3                   ret 

extern char string_00b06c18[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b06c18);
    return *name;
}
