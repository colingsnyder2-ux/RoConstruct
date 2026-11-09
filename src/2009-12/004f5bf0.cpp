// from server: 100% by nuck16
// roc 2009-12 004f5bf0  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f5bf0  64a100000000         mov eax, dword ptr fs:[0]
// 004f5bf6  6aff                 push -1
// 004f5bf8  688e579300           push 0x93578e
// 004f5bfd  50                   push eax
// 004f5bfe  b801000000           mov eax, 1
// 004f5c03  64892500000000       mov dword ptr fs:[0], esp
// 004f5c0a  840510deb700         test byte ptr [0xb7de10], al
// 004f5c10  752e                 jne 0x4f5c40
// 004f5c12  090510deb700         or dword ptr [0xb7de10], eax
// 004f5c18  6818dc9d00           push 0x9ddc18
// 004f5c1d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f5c25  e8b6c61300           call 0x6322e0
// 004f5c2a  83c404               add esp, 4
// 004f5c2d  a30cdeb700           mov dword ptr [0xb7de0c], eax
// 004f5c32  8b0c24               mov ecx, dword ptr [esp]
// 004f5c35  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5c3c  83c40c               add esp, 0xc
// 004f5c3f  c3                   ret 
// 004f5c40  8b0c24               mov ecx, dword ptr [esp]
// 004f5c43  a10cdeb700           mov eax, dword ptr [0xb7de0c]
// 004f5c48  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5c4f  83c40c               add esp, 0xc
// 004f5c52  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Teams");
    return *name;
}
