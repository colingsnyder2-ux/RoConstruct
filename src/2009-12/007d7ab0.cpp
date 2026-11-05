// from server: 100% by nuck16
// roc 2009-12 007d7ab0  unit: RBX::HUMAN::Dead  size: 99 bytes
//
// 007d7ab0  64a100000000         mov eax, dword ptr fs:[0]
// 007d7ab6  6aff                 push -1
// 007d7ab8  687e709500           push 0x95707e
// 007d7abd  50                   push eax
// 007d7abe  b801000000           mov eax, 1
// 007d7ac3  64892500000000       mov dword ptr fs:[0], esp
// 007d7aca  8405ac8eb900         test byte ptr [0xb98eac], al
// 007d7ad0  752e                 jne 0x7d7b00
// 007d7ad2  0905ac8eb900         or dword ptr [0xb98eac], eax
// 007d7ad8  683cf69e00           push 0x9ef63c
// 007d7add  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007d7ae5  e8f6a7e5ff           call 0x6322e0
// 007d7aea  83c404               add esp, 4
// 007d7aed  a3a88eb900           mov dword ptr [0xb98ea8], eax
// 007d7af2  8b0c24               mov ecx, dword ptr [esp]
// 007d7af5  64890d00000000       mov dword ptr fs:[0], ecx
// 007d7afc  83c40c               add esp, 0xc
// 007d7aff  c3                   ret 
// 007d7b00  8b0c24               mov ecx, dword ptr [esp]
// 007d7b03  a1a88eb900           mov eax, dword ptr [0xb98ea8]
// 007d7b08  64890d00000000       mov dword ptr fs:[0], ecx
// 007d7b0f  83c40c               add esp, 0xc
// 007d7b12  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Dead");
    return *name;
}
