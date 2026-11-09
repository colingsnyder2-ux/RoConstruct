// from server: 100% by nuck16
// roc 2009-12 007d7190  unit: RBX::HUMAN::HumanoidState  size: 99 bytes
//
// 007d7190  64a100000000         mov eax, dword ptr fs:[0]
// 007d7196  6aff                 push -1
// 007d7198  685e709500           push 0x95705e
// 007d719d  50                   push eax
// 007d719e  b801000000           mov eax, 1
// 007d71a3  64892500000000       mov dword ptr fs:[0], esp
// 007d71aa  8405648eb900         test byte ptr [0xb98e64], al
// 007d71b0  752e                 jne 0x7d71e0
// 007d71b2  0905648eb900         or dword ptr [0xb98e64], eax
// 007d71b8  6840f59e00           push 0x9ef540
// 007d71bd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007d71c5  e816b1e5ff           call 0x6322e0
// 007d71ca  83c404               add esp, 4
// 007d71cd  a3608eb900           mov dword ptr [0xb98e60], eax
// 007d71d2  8b0c24               mov ecx, dword ptr [esp]
// 007d71d5  64890d00000000       mov dword ptr fs:[0], ecx
// 007d71dc  83c40c               add esp, 0xc
// 007d71df  c3                   ret 
// 007d71e0  8b0c24               mov ecx, dword ptr [esp]
// 007d71e3  a1608eb900           mov eax, dword ptr [0xb98e60]
// 007d71e8  64890d00000000       mov dword ptr fs:[0], ecx
// 007d71ef  83c40c               add esp, 0xc
// 007d71f2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("RunningSlave");
    return *name;
}
