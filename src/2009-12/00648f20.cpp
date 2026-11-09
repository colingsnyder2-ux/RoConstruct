// from server: 100% by nuck16
// roc 2009-12 00648f20  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648f20  64a100000000         mov eax, dword ptr fs:[0]
// 00648f26  6aff                 push -1
// 00648f28  689e1a9400           push 0x941a9e
// 00648f2d  50                   push eax
// 00648f2e  b801000000           mov eax, 1
// 00648f33  64892500000000       mov dword ptr fs:[0], esp
// 00648f3a  8405185fb800         test byte ptr [0xb85f18], al
// 00648f40  752e                 jne 0x648f70
// 00648f42  0905185fb800         or dword ptr [0xb85f18], eax
// 00648f48  68e4a3b500           push 0xb5a3e4
// 00648f4d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648f55  e88693feff           call 0x6322e0
// 00648f5a  83c404               add esp, 4
// 00648f5d  a3145fb800           mov dword ptr [0xb85f14], eax
// 00648f62  8b0c24               mov ecx, dword ptr [esp]
// 00648f65  64890d00000000       mov dword ptr fs:[0], ecx
// 00648f6c  83c40c               add esp, 0xc
// 00648f6f  c3                   ret 
// 00648f70  8b0c24               mov ecx, dword ptr [esp]
// 00648f73  a1145fb800           mov eax, dword ptr [0xb85f14]
// 00648f78  64890d00000000       mov dword ptr fs:[0], ecx
// 00648f7f  83c40c               add esp, 0xc
// 00648f82  c3                   ret 

extern char string_00b5a3e4[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5a3e4);
    return *name;
}
