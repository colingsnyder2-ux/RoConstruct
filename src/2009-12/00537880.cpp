// from server: 100% by nuck16
// roc 2009-12 00537880  unit: RBX::Network::Replicator  size: 99 bytes
//
// 00537880  64a100000000         mov eax, dword ptr fs:[0]
// 00537886  6aff                 push -1
// 00537888  68ce979300           push 0x9397ce
// 0053788d  50                   push eax
// 0053788e  b801000000           mov eax, 1
// 00537893  64892500000000       mov dword ptr fs:[0], esp
// 0053789a  84058405b800         test byte ptr [0xb80584], al
// 005378a0  752e                 jne 0x5378d0
// 005378a2  09058405b800         or dword ptr [0xb80584], eax
// 005378a8  6808e89d00           push 0x9de808
// 005378ad  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 005378b5  e826aa0f00           call 0x6322e0
// 005378ba  83c404               add esp, 4
// 005378bd  a38005b800           mov dword ptr [0xb80580], eax
// 005378c2  8b0c24               mov ecx, dword ptr [esp]
// 005378c5  64890d00000000       mov dword ptr fs:[0], ecx
// 005378cc  83c40c               add esp, 0xc
// 005378cf  c3                   ret 
// 005378d0  8b0c24               mov ecx, dword ptr [esp]
// 005378d3  a18005b800           mov eax, dword ptr [0xb80580]
// 005378d8  64890d00000000       mov dword ptr fs:[0], ecx
// 005378df  83c40c               add esp, 0xc
// 005378e2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Glue");
    return *name;
}
