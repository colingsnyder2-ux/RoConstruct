// from server: 100% by nuck16
// roc 2009-12 004f5a30  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f5a30  64a100000000         mov eax, dword ptr fs:[0]
// 004f5a36  6aff                 push -1
// 004f5a38  680e579300           push 0x93570e
// 004f5a3d  50                   push eax
// 004f5a3e  b801000000           mov eax, 1
// 004f5a43  64892500000000       mov dword ptr fs:[0], esp
// 004f5a4a  8405f0ddb700         test byte ptr [0xb7ddf0], al
// 004f5a50  752e                 jne 0x4f5a80
// 004f5a52  0905f0ddb700         or dword ptr [0xb7ddf0], eax
// 004f5a58  68c8d59d00           push 0x9dd5c8
// 004f5a5d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f5a65  e876c81300           call 0x6322e0
// 004f5a6a  83c404               add esp, 4
// 004f5a6d  a3ecddb700           mov dword ptr [0xb7ddec], eax
// 004f5a72  8b0c24               mov ecx, dword ptr [esp]
// 004f5a75  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5a7c  83c40c               add esp, 0xc
// 004f5a7f  c3                   ret 
// 004f5a80  8b0c24               mov ecx, dword ptr [esp]
// 004f5a83  a1ecddb700           mov eax, dword ptr [0xb7ddec]
// 004f5a88  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5a8f  83c40c               add esp, 0xc
// 004f5a92  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Pants");
    return *name;
}
