// from server: 100% by nuck16
// roc 2009-12 00409170  unit: RBX::Network::VPlayer::?$FactoryProduct::Creator  size: 99 bytes
//
// 00409170  64a100000000         mov eax, dword ptr fs:[0]
// 00409176  6aff                 push -1
// 00409178  685e749200           push 0x92745e
// 0040917d  50                   push eax
// 0040917e  b801000000           mov eax, 1
// 00409183  64892500000000       mov dword ptr fs:[0], esp
// 0040918a  8405e495b700         test byte ptr [0xb795e4], al
// 00409190  752e                 jne 0x4091c0
// 00409192  0905e495b700         or dword ptr [0xb795e4], eax
// 00409198  68506cb000           push 0xb06c50
// 0040919d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004091a5  e836912200           call 0x6322e0
// 004091aa  83c404               add esp, 4
// 004091ad  a3e095b700           mov dword ptr [0xb795e0], eax
// 004091b2  8b0c24               mov ecx, dword ptr [esp]
// 004091b5  64890d00000000       mov dword ptr fs:[0], ecx
// 004091bc  83c40c               add esp, 0xc
// 004091bf  c3                   ret 
// 004091c0  8b0c24               mov ecx, dword ptr [esp]
// 004091c3  a1e095b700           mov eax, dword ptr [0xb795e0]
// 004091c8  64890d00000000       mov dword ptr fs:[0], ecx
// 004091cf  83c40c               add esp, 0xc
// 004091d2  c3                   ret 

extern char string_00b06c50[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b06c50);
    return *name;
}
