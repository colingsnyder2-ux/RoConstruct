// from server: 100% by nuck16
// roc 2009-12 004f5870  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f5870  64a100000000         mov eax, dword ptr fs:[0]
// 004f5876  6aff                 push -1
// 004f5878  688e569300           push 0x93568e
// 004f587d  50                   push eax
// 004f587e  b801000000           mov eax, 1
// 004f5883  64892500000000       mov dword ptr fs:[0], esp
// 004f588a  8405d0ddb700         test byte ptr [0xb7ddd0], al
// 004f5890  752e                 jne 0x4f58c0
// 004f5892  0905d0ddb700         or dword ptr [0xb7ddd0], eax
// 004f5898  6828ce9d00           push 0x9dce28
// 004f589d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f58a5  e836ca1300           call 0x6322e0
// 004f58aa  83c404               add esp, 4
// 004f58ad  a3ccddb700           mov dword ptr [0xb7ddcc], eax
// 004f58b2  8b0c24               mov ecx, dword ptr [esp]
// 004f58b5  64890d00000000       mov dword ptr fs:[0], ecx
// 004f58bc  83c40c               add esp, 0xc
// 004f58bf  c3                   ret 
// 004f58c0  8b0c24               mov ecx, dword ptr [esp]
// 004f58c3  a1ccddb700           mov eax, dword ptr [0xb7ddcc]
// 004f58c8  64890d00000000       mov dword ptr fs:[0], ecx
// 004f58cf  83c40c               add esp, 0xc
// 004f58d2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("StarterGui");
    return *name;
}
