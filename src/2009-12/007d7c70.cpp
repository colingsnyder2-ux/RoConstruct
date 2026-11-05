// from server: 100% by nuck16
// roc 2009-12 007d7c70  unit: RBX::HUMAN::FallingDown  size: 99 bytes
//
// 007d7c70  64a100000000         mov eax, dword ptr fs:[0]
// 007d7c76  6aff                 push -1
// 007d7c78  68be709500           push 0x9570be
// 007d7c7d  50                   push eax
// 007d7c7e  b801000000           mov eax, 1
// 007d7c83  64892500000000       mov dword ptr fs:[0], esp
// 007d7c8a  8405d08eb900         test byte ptr [0xb98ed0], al
// 007d7c90  752e                 jne 0x7d7cc0
// 007d7c92  0905d08eb900         or dword ptr [0xb98ed0], eax
// 007d7c98  68c0f69e00           push 0x9ef6c0
// 007d7c9d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007d7ca5  e836a6e5ff           call 0x6322e0
// 007d7caa  83c404               add esp, 4
// 007d7cad  a3cc8eb900           mov dword ptr [0xb98ecc], eax
// 007d7cb2  8b0c24               mov ecx, dword ptr [esp]
// 007d7cb5  64890d00000000       mov dword ptr fs:[0], ecx
// 007d7cbc  83c40c               add esp, 0xc
// 007d7cbf  c3                   ret 
// 007d7cc0  8b0c24               mov ecx, dword ptr [esp]
// 007d7cc3  a1cc8eb900           mov eax, dword ptr [0xb98ecc]
// 007d7cc8  64890d00000000       mov dword ptr fs:[0], ecx
// 007d7ccf  83c40c               add esp, 0xc
// 007d7cd2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Seated");
    return *name;
}
