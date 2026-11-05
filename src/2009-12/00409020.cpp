// from server: 100% by nuck16
// roc 2009-12 00409020  unit: RBX::Network::VPlayer::?$FactoryProduct::Creator  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00409020
//
// 00409020  64a100000000         mov eax, dword ptr fs:[0]
// 00409026  6aff                 push -1
// 00409028  68fe739200           push 0x9273fe
// 0040902d  50                   push eax
// 0040902e  b801000000           mov eax, 1
// 00409033  64892500000000       mov dword ptr fs:[0], esp
// 0040903a  8405cc95b700         test byte ptr [0xb795cc], al
// 00409040  752e                 jne 0x409070
// 00409042  0905cc95b700         or dword ptr [0xb795cc], eax
// 00409048  68e46bb000           push 0xb06be4
// 0040904d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00409055  e886922200           call 0x6322e0
// 0040905a  83c404               add esp, 4
// 0040905d  a3c895b700           mov dword ptr [0xb795c8], eax
// 00409062  8b0c24               mov ecx, dword ptr [esp]
// 00409065  64890d00000000       mov dword ptr fs:[0], ecx
// 0040906c  83c40c               add esp, 0xc
// 0040906f  c3                   ret 
// 00409070  8b0c24               mov ecx, dword ptr [esp]
// 00409073  a1c895b700           mov eax, dword ptr [0xb795c8]
// 00409078  64890d00000000       mov dword ptr fs:[0], ecx
// 0040907f  83c40c               add esp, 0xc
// 00409082  c3                   ret 

extern char string_00b06be4[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b06be4);
    return *name;
}
