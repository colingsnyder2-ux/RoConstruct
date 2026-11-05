// from server: 100% by nuck16
// roc 2009-12 005377a0  unit: RBX::Network::Replicator  size: 99 bytes
//
// 005377a0  64a100000000         mov eax, dword ptr fs:[0]
// 005377a6  6aff                 push -1
// 005377a8  688e979300           push 0x93978e
// 005377ad  50                   push eax
// 005377ae  b801000000           mov eax, 1
// 005377b3  64892500000000       mov dword ptr fs:[0], esp
// 005377ba  84057405b800         test byte ptr [0xb80574], al
// 005377c0  752e                 jne 0x5377f0
// 005377c2  09057405b800         or dword ptr [0xb80574], eax
// 005377c8  68f8e79d00           push 0x9de7f8
// 005377cd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 005377d5  e806ab0f00           call 0x6322e0
// 005377da  83c404               add esp, 4
// 005377dd  a37005b800           mov dword ptr [0xb80570], eax
// 005377e2  8b0c24               mov ecx, dword ptr [esp]
// 005377e5  64890d00000000       mov dword ptr fs:[0], ecx
// 005377ec  83c40c               add esp, 0xc
// 005377ef  c3                   ret 
// 005377f0  8b0c24               mov ecx, dword ptr [esp]
// 005377f3  a17005b800           mov eax, dword ptr [0xb80570]
// 005377f8  64890d00000000       mov dword ptr fs:[0], ecx
// 005377ff  83c40c               add esp, 0xc
// 00537802  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Snap");
    return *name;
}
