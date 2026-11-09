// from server: 100% by nuck16
// roc 2009-12 00426720  unit: MainLogManager  size: 99 bytes
//
// 00426720  64a100000000         mov eax, dword ptr fs:[0]
// 00426726  6aff                 push -1
// 00426728  686e939200           push 0x92936e
// 0042672d  50                   push eax
// 0042672e  b801000000           mov eax, 1
// 00426733  64892500000000       mov dword ptr fs:[0], esp
// 0042673a  840594a2b700         test byte ptr [0xb7a294], al
// 00426740  752e                 jne 0x426770
// 00426742  090594a2b700         or dword ptr [0xb7a294], eax
// 00426748  685096b300           push 0xb39650
// 0042674d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00426755  e886bb2000           call 0x6322e0
// 0042675a  83c404               add esp, 4
// 0042675d  a390a2b700           mov dword ptr [0xb7a290], eax
// 00426762  8b0c24               mov ecx, dword ptr [esp]
// 00426765  64890d00000000       mov dword ptr fs:[0], ecx
// 0042676c  83c40c               add esp, 0xc
// 0042676f  c3                   ret 
// 00426770  8b0c24               mov ecx, dword ptr [esp]
// 00426773  a190a2b700           mov eax, dword ptr [0xb7a290]
// 00426778  64890d00000000       mov dword ptr fs:[0], ecx
// 0042677f  83c40c               add esp, 0xc
// 00426782  c3                   ret 

extern char string_00b39650[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b39650);
    return *name;
}
