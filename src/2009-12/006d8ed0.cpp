// from server: 100% by nuck16
// roc 2009-12 006d8ed0  unit: RBX::Stats::TypedMemItem  size: 99 bytes
//
// 006d8ed0  64a100000000         mov eax, dword ptr fs:[0]
// 006d8ed6  6aff                 push -1
// 006d8ed8  683eaa9400           push 0x94aa3e
// 006d8edd  50                   push eax
// 006d8ede  b801000000           mov eax, 1
// 006d8ee3  64892500000000       mov dword ptr fs:[0], esp
// 006d8eea  84059c30b900         test byte ptr [0xb9309c], al
// 006d8ef0  752e                 jne 0x6d8f20
// 006d8ef2  09059c30b900         or dword ptr [0xb9309c], eax
// 006d8ef8  6838919d00           push 0x9d9138
// 006d8efd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d8f05  e8d693f5ff           call 0x6322e0
// 006d8f0a  83c404               add esp, 4
// 006d8f0d  a39830b900           mov dword ptr [0xb93098], eax
// 006d8f12  8b0c24               mov ecx, dword ptr [esp]
// 006d8f15  64890d00000000       mov dword ptr fs:[0], ecx
// 006d8f1c  83c40c               add esp, 0xc
// 006d8f1f  c3                   ret 
// 006d8f20  8b0c24               mov ecx, dword ptr [esp]
// 006d8f23  a19830b900           mov eax, dword ptr [0xb93098]
// 006d8f28  64890d00000000       mov dword ptr fs:[0], ecx
// 006d8f2f  83c40c               add esp, 0xc
// 006d8f32  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("RunningAverageItemInt");
    return *name;
}
