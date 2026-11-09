// from server: 100% by nuck16
// roc 2009-12 00716b20  unit: RBX::JointInstance  size: 99 bytes
//
// 00716b20  64a100000000         mov eax, dword ptr fs:[0]
// 00716b26  6aff                 push -1
// 00716b28  680edf9400           push 0x94df0e
// 00716b2d  50                   push eax
// 00716b2e  b801000000           mov eax, 1
// 00716b33  64892500000000       mov dword ptr fs:[0], esp
// 00716b3a  84054056b900         test byte ptr [0xb95640], al
// 00716b40  752e                 jne 0x716b70
// 00716b42  09054056b900         or dword ptr [0xb95640], eax
// 00716b48  6818e89d00           push 0x9de818
// 00716b4d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00716b55  e886b7f1ff           call 0x6322e0
// 00716b5a  83c404               add esp, 4
// 00716b5d  a33c56b900           mov dword ptr [0xb9563c], eax
// 00716b62  8b0c24               mov ecx, dword ptr [esp]
// 00716b65  64890d00000000       mov dword ptr fs:[0], ecx
// 00716b6c  83c40c               add esp, 0xc
// 00716b6f  c3                   ret 
// 00716b70  8b0c24               mov ecx, dword ptr [esp]
// 00716b73  a13c56b900           mov eax, dword ptr [0xb9563c]
// 00716b78  64890d00000000       mov dword ptr fs:[0], ecx
// 00716b7f  83c40c               add esp, 0xc
// 00716b82  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("DynamicRotate");
    return *name;
}
