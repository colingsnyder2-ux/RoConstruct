// from server: 100% by nuck16
// roc 2009-12 007abcf0  unit: RBX::HUMAN::Climbing  size: 99 bytes
//
// 007abcf0  64a100000000         mov eax, dword ptr fs:[0]
// 007abcf6  6aff                 push -1
// 007abcf8  683e579500           push 0x95573e
// 007abcfd  50                   push eax
// 007abcfe  b801000000           mov eax, 1
// 007abd03  64892500000000       mov dword ptr fs:[0], esp
// 007abd0a  8405948ab900         test byte ptr [0xb98a94], al
// 007abd10  752e                 jne 0x7abd40
// 007abd12  0905948ab900         or dword ptr [0xb98a94], eax
// 007abd18  6850f59e00           push 0x9ef550
// 007abd1d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007abd25  e8b665e8ff           call 0x6322e0
// 007abd2a  83c404               add esp, 4
// 007abd2d  a3908ab900           mov dword ptr [0xb98a90], eax
// 007abd32  8b0c24               mov ecx, dword ptr [esp]
// 007abd35  64890d00000000       mov dword ptr fs:[0], ecx
// 007abd3c  83c40c               add esp, 0xc
// 007abd3f  c3                   ret 
// 007abd40  8b0c24               mov ecx, dword ptr [esp]
// 007abd43  a1908ab900           mov eax, dword ptr [0xb98a90]
// 007abd48  64890d00000000       mov dword ptr fs:[0], ecx
// 007abd4f  83c40c               add esp, 0xc
// 007abd52  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Landed");
    return *name;
}
