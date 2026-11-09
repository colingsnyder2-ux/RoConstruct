// from server: 100% by nuck16
// roc 2009-12 004f5720  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f5720  64a100000000         mov eax, dword ptr fs:[0]
// 004f5726  6aff                 push -1
// 004f5728  682e569300           push 0x93562e
// 004f572d  50                   push eax
// 004f572e  b801000000           mov eax, 1
// 004f5733  64892500000000       mov dword ptr fs:[0], esp
// 004f573a  8405b8ddb700         test byte ptr [0xb7ddb8], al
// 004f5740  752e                 jne 0x4f5770
// 004f5742  0905b8ddb700         or dword ptr [0xb7ddb8], eax
// 004f5748  6800c79d00           push 0x9dc700
// 004f574d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f5755  e886cb1300           call 0x6322e0
// 004f575a  83c404               add esp, 4
// 004f575d  a3b4ddb700           mov dword ptr [0xb7ddb4], eax
// 004f5762  8b0c24               mov ecx, dword ptr [esp]
// 004f5765  64890d00000000       mov dword ptr fs:[0], ecx
// 004f576c  83c40c               add esp, 0xc
// 004f576f  c3                   ret 
// 004f5770  8b0c24               mov ecx, dword ptr [esp]
// 004f5773  a1b4ddb700           mov eax, dword ptr [0xb7ddb4]
// 004f5778  64890d00000000       mov dword ptr fs:[0], ecx
// 004f577f  83c40c               add esp, 0xc
// 004f5782  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Backpack");
    return *name;
}
