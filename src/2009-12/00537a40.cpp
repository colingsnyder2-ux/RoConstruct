// from server: 100% by nuck16
// roc 2009-12 00537a40  unit: RBX::Network::Replicator  size: 99 bytes
//
// 00537a40  64a100000000         mov eax, dword ptr fs:[0]
// 00537a46  6aff                 push -1
// 00537a48  684e989300           push 0x93984e
// 00537a4d  50                   push eax
// 00537a4e  b801000000           mov eax, 1
// 00537a53  64892500000000       mov dword ptr fs:[0], esp
// 00537a5a  8405a405b800         test byte ptr [0xb805a4], al
// 00537a60  752e                 jne 0x537a90
// 00537a62  0905a405b800         or dword ptr [0xb805a4], eax
// 00537a68  6838e89d00           push 0x9de838
// 00537a6d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00537a75  e866a80f00           call 0x6322e0
// 00537a7a  83c404               add esp, 4
// 00537a7d  a3a005b800           mov dword ptr [0xb805a0], eax
// 00537a82  8b0c24               mov ecx, dword ptr [esp]
// 00537a85  64890d00000000       mov dword ptr fs:[0], ecx
// 00537a8c  83c40c               add esp, 0xc
// 00537a8f  c3                   ret 
// 00537a90  8b0c24               mov ecx, dword ptr [esp]
// 00537a93  a1a005b800           mov eax, dword ptr [0xb805a0]
// 00537a98  64890d00000000       mov dword ptr fs:[0], ecx
// 00537a9f  83c40c               add esp, 0xc
// 00537aa2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Motor");
    return *name;
}
