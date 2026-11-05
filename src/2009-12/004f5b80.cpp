// from server: 100% by nuck16
// roc 2009-12 004f5b80  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f5b80  64a100000000         mov eax, dword ptr fs:[0]
// 004f5b86  6aff                 push -1
// 004f5b88  686e579300           push 0x93576e
// 004f5b8d  50                   push eax
// 004f5b8e  b801000000           mov eax, 1
// 004f5b93  64892500000000       mov dword ptr fs:[0], esp
// 004f5b9a  840508deb700         test byte ptr [0xb7de08], al
// 004f5ba0  752e                 jne 0x4f5bd0
// 004f5ba2  090508deb700         or dword ptr [0xb7de08], eax
// 004f5ba8  68ecd59d00           push 0x9dd5ec
// 004f5bad  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f5bb5  e826c71300           call 0x6322e0
// 004f5bba  83c404               add esp, 4
// 004f5bbd  a304deb700           mov dword ptr [0xb7de04], eax
// 004f5bc2  8b0c24               mov ecx, dword ptr [esp]
// 004f5bc5  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5bcc  83c40c               add esp, 0xc
// 004f5bcf  c3                   ret 
// 004f5bd0  8b0c24               mov ecx, dword ptr [esp]
// 004f5bd3  a104deb700           mov eax, dword ptr [0xb7de04]
// 004f5bd8  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5bdf  83c40c               add esp, 0xc
// 004f5be2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Skin");
    return *name;
}
