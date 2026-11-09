// from server: 100% by nuck16
// roc 2009-12 007d8100  unit: RBX::HUMAN::Flying  size: 99 bytes
//
// 007d8100  64a100000000         mov eax, dword ptr fs:[0]
// 007d8106  6aff                 push -1
// 007d8108  687e719500           push 0x95717e
// 007d810d  50                   push eax
// 007d810e  b801000000           mov eax, 1
// 007d8113  64892500000000       mov dword ptr fs:[0], esp
// 007d811a  8405308fb900         test byte ptr [0xb98f30], al
// 007d8120  752e                 jne 0x7d8150
// 007d8122  0905308fb900         or dword ptr [0xb98f30], eax
// 007d8128  6800f89e00           push 0x9ef800
// 007d812d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007d8135  e8a6a1e5ff           call 0x6322e0
// 007d813a  83c404               add esp, 4
// 007d813d  a32c8fb900           mov dword ptr [0xb98f2c], eax
// 007d8142  8b0c24               mov ecx, dword ptr [esp]
// 007d8145  64890d00000000       mov dword ptr fs:[0], ecx
// 007d814c  83c40c               add esp, 0xc
// 007d814f  c3                   ret 
// 007d8150  8b0c24               mov ecx, dword ptr [esp]
// 007d8153  a12c8fb900           mov eax, dword ptr [0xb98f2c]
// 007d8158  64890d00000000       mov dword ptr fs:[0], ecx
// 007d815f  83c40c               add esp, 0xc
// 007d8162  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Freefall");
    return *name;
}
