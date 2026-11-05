// from server: 100% by nuck16
// roc 2009-12 007abd90  unit: RBX::HUMAN::Landed  size: 99 bytes
//
// 007abd90  64a100000000         mov eax, dword ptr fs:[0]
// 007abd96  6aff                 push -1
// 007abd98  685e579500           push 0x95575e
// 007abd9d  50                   push eax
// 007abd9e  b801000000           mov eax, 1
// 007abda3  64892500000000       mov dword ptr fs:[0], esp
// 007abdaa  8405a08ab900         test byte ptr [0xb98aa0], al
// 007abdb0  752e                 jne 0x7abde0
// 007abdb2  0905a08ab900         or dword ptr [0xb98aa0], eax
// 007abdb8  6858f59e00           push 0x9ef558
// 007abdbd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007abdc5  e81665e8ff           call 0x6322e0
// 007abdca  83c404               add esp, 4
// 007abdcd  a39c8ab900           mov dword ptr [0xb98a9c], eax
// 007abdd2  8b0c24               mov ecx, dword ptr [esp]
// 007abdd5  64890d00000000       mov dword ptr fs:[0], ecx
// 007abddc  83c40c               add esp, 0xc
// 007abddf  c3                   ret 
// 007abde0  8b0c24               mov ecx, dword ptr [esp]
// 007abde3  a19c8ab900           mov eax, dword ptr [0xb98a9c]
// 007abde8  64890d00000000       mov dword ptr fs:[0], ecx
// 007abdef  83c40c               add esp, 0xc
// 007abdf2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Climbing");
    return *name;
}
