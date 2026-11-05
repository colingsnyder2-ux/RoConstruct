// from server: 100% by nuck16
// roc 2009-12 004f5aa0  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f5aa0  64a100000000         mov eax, dword ptr fs:[0]
// 004f5aa6  6aff                 push -1
// 004f5aa8  682e579300           push 0x93572e
// 004f5aad  50                   push eax
// 004f5aae  b801000000           mov eax, 1
// 004f5ab3  64892500000000       mov dword ptr fs:[0], esp
// 004f5aba  8405f8ddb700         test byte ptr [0xb7ddf8], al
// 004f5ac0  752e                 jne 0x4f5af0
// 004f5ac2  0905f8ddb700         or dword ptr [0xb7ddf8], eax
// 004f5ac8  68c0d59d00           push 0x9dd5c0
// 004f5acd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f5ad5  e806c81300           call 0x6322e0
// 004f5ada  83c404               add esp, 4
// 004f5add  a3f4ddb700           mov dword ptr [0xb7ddf4], eax
// 004f5ae2  8b0c24               mov ecx, dword ptr [esp]
// 004f5ae5  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5aec  83c40c               add esp, 0xc
// 004f5aef  c3                   ret 
// 004f5af0  8b0c24               mov ecx, dword ptr [esp]
// 004f5af3  a1f4ddb700           mov eax, dword ptr [0xb7ddf4]
// 004f5af8  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5aff  83c40c               add esp, 0xc
// 004f5b02  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Shirt");
    return *name;
}
