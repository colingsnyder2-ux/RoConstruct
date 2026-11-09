// from server: 100% by nuck16
// roc 2009-12 004f5950  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f5950  64a100000000         mov eax, dword ptr fs:[0]
// 004f5956  6aff                 push -1
// 004f5958  68ce569300           push 0x9356ce
// 004f595d  50                   push eax
// 004f595e  b801000000           mov eax, 1
// 004f5963  64892500000000       mov dword ptr fs:[0], esp
// 004f596a  8405e0ddb700         test byte ptr [0xb7dde0], al
// 004f5970  752e                 jne 0x4f59a0
// 004f5972  0905e0ddb700         or dword ptr [0xb7dde0], eax
// 004f5978  68e0d09d00           push 0x9dd0e0
// 004f597d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f5985  e856c91300           call 0x6322e0
// 004f598a  83c404               add esp, 4
// 004f598d  a3dcddb700           mov dword ptr [0xb7dddc], eax
// 004f5992  8b0c24               mov ecx, dword ptr [esp]
// 004f5995  64890d00000000       mov dword ptr fs:[0], ecx
// 004f599c  83c40c               add esp, 0xc
// 004f599f  c3                   ret 
// 004f59a0  8b0c24               mov ecx, dword ptr [esp]
// 004f59a3  a1dcddb700           mov eax, dword ptr [0xb7dddc]
// 004f59a8  64890d00000000       mov dword ptr fs:[0], ecx
// 004f59af  83c40c               add esp, 0xc
// 004f59b2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("SpawnerService");
    return *name;
}
