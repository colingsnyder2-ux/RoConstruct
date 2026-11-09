// from server: 100% by nuck16
// roc 2009-12 00648120  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648120  64a100000000         mov eax, dword ptr fs:[0]
// 00648126  6aff                 push -1
// 00648128  689e169400           push 0x94169e
// 0064812d  50                   push eax
// 0064812e  b801000000           mov eax, 1
// 00648133  64892500000000       mov dword ptr fs:[0], esp
// 0064813a  8405185eb800         test byte ptr [0xb85e18], al
// 00648140  752e                 jne 0x648170
// 00648142  0905185eb800         or dword ptr [0xb85e18], eax
// 00648148  68dc33b500           push 0xb533dc
// 0064814d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648155  e886a1feff           call 0x6322e0
// 0064815a  83c404               add esp, 4
// 0064815d  a3145eb800           mov dword ptr [0xb85e14], eax
// 00648162  8b0c24               mov ecx, dword ptr [esp]
// 00648165  64890d00000000       mov dword ptr fs:[0], ecx
// 0064816c  83c40c               add esp, 0xc
// 0064816f  c3                   ret 
// 00648170  8b0c24               mov ecx, dword ptr [esp]
// 00648173  a1145eb800           mov eax, dword ptr [0xb85e14]
// 00648178  64890d00000000       mov dword ptr fs:[0], ecx
// 0064817f  83c40c               add esp, 0xc
// 00648182  c3                   ret 

extern char string_00b533dc[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b533dc);
    return *name;
}
