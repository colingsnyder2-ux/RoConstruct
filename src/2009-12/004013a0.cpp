// from server: 100% by nuck16
// roc 2009-12 004013a0  unit: CAboutRobloxDialog  size: 99 bytes
//
// 004013a0  64a100000000         mov eax, dword ptr fs:[0]
// 004013a6  6aff                 push -1
// 004013a8  684e6f9200           push 0x926f4e
// 004013ad  50                   push eax
// 004013ae  b801000000           mov eax, 1
// 004013b3  64892500000000       mov dword ptr fs:[0], esp
// 004013ba  84051494b700         test byte ptr [0xb79414], al
// 004013c0  752e                 jne 0x4013f0
// 004013c2  09051494b700         or dword ptr [0xb79414], eax
// 004013c8  68c8ac9c00           push 0x9cacc8
// 004013cd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004013d5  e8060f2300           call 0x6322e0
// 004013da  83c404               add esp, 4
// 004013dd  a31094b700           mov dword ptr [0xb79410], eax
// 004013e2  8b0c24               mov ecx, dword ptr [esp]
// 004013e5  64890d00000000       mov dword ptr fs:[0], ecx
// 004013ec  83c40c               add esp, 0xc
// 004013ef  c3                   ret 
// 004013f0  8b0c24               mov ecx, dword ptr [esp]
// 004013f3  a11094b700           mov eax, dword ptr [0xb79410]
// 004013f8  64890d00000000       mov dword ptr fs:[0], ecx
// 004013ff  83c40c               add esp, 0xc
// 00401402  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("TaskScheduler");
    return *name;
}
