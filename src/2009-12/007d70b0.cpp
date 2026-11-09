// from server: 100% by nuck16
// roc 2009-12 007d70b0  unit: RBX::HUMAN::Climbing  size: 99 bytes
//
// 007d70b0  64a100000000         mov eax, dword ptr fs:[0]
// 007d70b6  6aff                 push -1
// 007d70b8  683e709500           push 0x95703e
// 007d70bd  50                   push eax
// 007d70be  b801000000           mov eax, 1
// 007d70c3  64892500000000       mov dword ptr fs:[0], esp
// 007d70ca  84055c8eb900         test byte ptr [0xb98e5c], al
// 007d70d0  752e                 jne 0x7d7100
// 007d70d2  09055c8eb900         or dword ptr [0xb98e5c], eax
// 007d70d8  6838f59e00           push 0x9ef538
// 007d70dd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007d70e5  e8f6b1e5ff           call 0x6322e0
// 007d70ea  83c404               add esp, 4
// 007d70ed  a3588eb900           mov dword ptr [0xb98e58], eax
// 007d70f2  8b0c24               mov ecx, dword ptr [esp]
// 007d70f5  64890d00000000       mov dword ptr fs:[0], ecx
// 007d70fc  83c40c               add esp, 0xc
// 007d70ff  c3                   ret 
// 007d7100  8b0c24               mov ecx, dword ptr [esp]
// 007d7103  a1588eb900           mov eax, dword ptr [0xb98e58]
// 007d7108  64890d00000000       mov dword ptr fs:[0], ecx
// 007d710f  83c40c               add esp, 0xc
// 007d7112  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Running");
    return *name;
}
