// from server: 100% by nuck16
// roc 2009-12 007d7b20  unit: RBX::HUMAN::Dead  size: 99 bytes
//
// 007d7b20  64a100000000         mov eax, dword ptr fs:[0]
// 007d7b26  6aff                 push -1
// 007d7b28  689e709500           push 0x95709e
// 007d7b2d  50                   push eax
// 007d7b2e  b801000000           mov eax, 1
// 007d7b33  64892500000000       mov dword ptr fs:[0], esp
// 007d7b3a  8405b48eb900         test byte ptr [0xb98eb4], al
// 007d7b40  752e                 jne 0x7d7b70
// 007d7b42  0905b48eb900         or dword ptr [0xb98eb4], eax
// 007d7b48  6830f69e00           push 0x9ef630
// 007d7b4d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007d7b55  e886a7e5ff           call 0x6322e0
// 007d7b5a  83c404               add esp, 4
// 007d7b5d  a3b08eb900           mov dword ptr [0xb98eb0], eax
// 007d7b62  8b0c24               mov ecx, dword ptr [esp]
// 007d7b65  64890d00000000       mov dword ptr fs:[0], ecx
// 007d7b6c  83c40c               add esp, 0xc
// 007d7b6f  c3                   ret 
// 007d7b70  8b0c24               mov ecx, dword ptr [esp]
// 007d7b73  a1b08eb900           mov eax, dword ptr [0xb98eb0]
// 007d7b78  64890d00000000       mov dword ptr fs:[0], ecx
// 007d7b7f  83c40c               add esp, 0xc
// 007d7b82  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("FallingDown");
    return *name;
}
