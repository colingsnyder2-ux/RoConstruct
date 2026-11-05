// from server: 100% by nuck16
// roc 2009-12 004f55d0  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f55d0  64a100000000         mov eax, dword ptr fs:[0]
// 004f55d6  6aff                 push -1
// 004f55d8  68ce559300           push 0x9355ce
// 004f55dd  50                   push eax
// 004f55de  b801000000           mov eax, 1
// 004f55e3  64892500000000       mov dword ptr fs:[0], esp
// 004f55ea  8405a0ddb700         test byte ptr [0xb7dda0], al
// 004f55f0  752e                 jne 0x4f5620
// 004f55f2  0905a0ddb700         or dword ptr [0xb7dda0], eax
// 004f55f8  6870bf9b00           push 0x9bbf70
// 004f55fd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f5605  e8d6cc1300           call 0x6322e0
// 004f560a  83c404               add esp, 4
// 004f560d  a39cddb700           mov dword ptr [0xb7dd9c], eax
// 004f5612  8b0c24               mov ecx, dword ptr [esp]
// 004f5615  64890d00000000       mov dword ptr fs:[0], ecx
// 004f561c  83c40c               add esp, 0xc
// 004f561f  c3                   ret 
// 004f5620  8b0c24               mov ecx, dword ptr [esp]
// 004f5623  a19cddb700           mov eax, dword ptr [0xb7dd9c]
// 004f5628  64890d00000000       mov dword ptr fs:[0], ecx
// 004f562f  83c40c               add esp, 0xc
// 004f5632  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("NetworkSettings");
    return *name;
}
