// from server: 100% by nuck16
// roc 2009-12 005378f0  unit: RBX::Network::Replicator  size: 99 bytes
//
// 005378f0  64a100000000         mov eax, dword ptr fs:[0]
// 005378f6  6aff                 push -1
// 005378f8  68ee979300           push 0x9397ee
// 005378fd  50                   push eax
// 005378fe  b801000000           mov eax, 1
// 00537903  64892500000000       mov dword ptr fs:[0], esp
// 0053790a  84058c05b800         test byte ptr [0xb8058c], al
// 00537910  752e                 jne 0x537940
// 00537912  09058c05b800         or dword ptr [0xb8058c], eax
// 00537918  6810e89d00           push 0x9de810
// 0053791d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00537925  e8b6a90f00           call 0x6322e0
// 0053792a  83c404               add esp, 4
// 0053792d  a38805b800           mov dword ptr [0xb80588], eax
// 00537932  8b0c24               mov ecx, dword ptr [esp]
// 00537935  64890d00000000       mov dword ptr fs:[0], ecx
// 0053793c  83c40c               add esp, 0xc
// 0053793f  c3                   ret 
// 00537940  8b0c24               mov ecx, dword ptr [esp]
// 00537943  a18805b800           mov eax, dword ptr [0xb80588]
// 00537948  64890d00000000       mov dword ptr fs:[0], ecx
// 0053794f  83c40c               add esp, 0xc
// 00537952  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Rotate");
    return *name;
}
