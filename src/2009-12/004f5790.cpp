// from server: 100% by nuck16
// roc 2009-12 004f5790  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f5790  64a100000000         mov eax, dword ptr fs:[0]
// 004f5796  6aff                 push -1
// 004f5798  684e569300           push 0x93564e
// 004f579d  50                   push eax
// 004f579e  b801000000           mov eax, 1
// 004f57a3  64892500000000       mov dword ptr fs:[0], esp
// 004f57aa  8405c0ddb700         test byte ptr [0xb7ddc0], al
// 004f57b0  752e                 jne 0x4f57e0
// 004f57b2  0905c0ddb700         or dword ptr [0xb7ddc0], eax
// 004f57b8  6858c89d00           push 0x9dc858
// 004f57bd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f57c5  e816cb1300           call 0x6322e0
// 004f57ca  83c404               add esp, 4
// 004f57cd  a3bcddb700           mov dword ptr [0xb7ddbc], eax
// 004f57d2  8b0c24               mov ecx, dword ptr [esp]
// 004f57d5  64890d00000000       mov dword ptr fs:[0], ecx
// 004f57dc  83c40c               add esp, 0xc
// 004f57df  c3                   ret 
// 004f57e0  8b0c24               mov ecx, dword ptr [esp]
// 004f57e3  a1bcddb700           mov eax, dword ptr [0xb7ddbc]
// 004f57e8  64890d00000000       mov dword ptr fs:[0], ecx
// 004f57ef  83c40c               add esp, 0xc
// 004f57f2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("PlayerMouse");
    return *name;
}
