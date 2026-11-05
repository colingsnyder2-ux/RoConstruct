// from server: 100% by nuck16
// roc 2009-12 005379d0  unit: RBX::Network::Replicator  size: 99 bytes
//
// 005379d0  64a100000000         mov eax, dword ptr fs:[0]
// 005379d6  6aff                 push -1
// 005379d8  682e989300           push 0x93982e
// 005379dd  50                   push eax
// 005379de  b801000000           mov eax, 1
// 005379e3  64892500000000       mov dword ptr fs:[0], esp
// 005379ea  84059c05b800         test byte ptr [0xb8059c], al
// 005379f0  752e                 jne 0x537a20
// 005379f2  09059c05b800         or dword ptr [0xb8059c], eax
// 005379f8  6830e89d00           push 0x9de830
// 005379fd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00537a05  e8d6a80f00           call 0x6322e0
// 00537a0a  83c404               add esp, 4
// 00537a0d  a39805b800           mov dword ptr [0xb80598], eax
// 00537a12  8b0c24               mov ecx, dword ptr [esp]
// 00537a15  64890d00000000       mov dword ptr fs:[0], ecx
// 00537a1c  83c40c               add esp, 0xc
// 00537a1f  c3                   ret 
// 00537a20  8b0c24               mov ecx, dword ptr [esp]
// 00537a23  a19805b800           mov eax, dword ptr [0xb80598]
// 00537a28  64890d00000000       mov dword ptr fs:[0], ecx
// 00537a2f  83c40c               add esp, 0xc
// 00537a32  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("RotateV");
    return *name;
}
