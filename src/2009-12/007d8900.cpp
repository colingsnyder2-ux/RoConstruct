// from server: 100% by nuck16
// roc 2009-12 007d8900  unit: RBX::HUMAN::Freefall  size: 99 bytes
//
// 007d8900  64a100000000         mov eax, dword ptr fs:[0]
// 007d8906  6aff                 push -1
// 007d8908  689e719500           push 0x95719e
// 007d890d  50                   push eax
// 007d890e  b801000000           mov eax, 1
// 007d8913  64892500000000       mov dword ptr fs:[0], esp
// 007d891a  8405488fb900         test byte ptr [0xb98f48], al
// 007d8920  752e                 jne 0x7d8950
// 007d8922  0905488fb900         or dword ptr [0xb98f48], eax
// 007d8928  6858f89e00           push 0x9ef858
// 007d892d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007d8935  e8a699e5ff           call 0x6322e0
// 007d893a  83c404               add esp, 4
// 007d893d  a3448fb900           mov dword ptr [0xb98f44], eax
// 007d8942  8b0c24               mov ecx, dword ptr [esp]
// 007d8945  64890d00000000       mov dword ptr fs:[0], ecx
// 007d894c  83c40c               add esp, 0xc
// 007d894f  c3                   ret 
// 007d8950  8b0c24               mov ecx, dword ptr [esp]
// 007d8953  a1448fb900           mov eax, dword ptr [0xb98f44]
// 007d8958  64890d00000000       mov dword ptr fs:[0], ecx
// 007d895f  83c40c               add esp, 0xc
// 007d8962  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Jumping");
    return *name;
}
