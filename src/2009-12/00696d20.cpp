// from server: 100% by nuck16
// roc 2009-12 00696d20  unit: RBX::PartTool  size: 99 bytes
//
// 00696d20  64a100000000         mov eax, dword ptr fs:[0]
// 00696d26  6aff                 push -1
// 00696d28  68ce6e9400           push 0x946ece
// 00696d2d  50                   push eax
// 00696d2e  b801000000           mov eax, 1
// 00696d33  64892500000000       mov dword ptr fs:[0], esp
// 00696d3a  84055816b900         test byte ptr [0xb91658], al
// 00696d40  752e                 jne 0x696d70
// 00696d42  09055816b900         or dword ptr [0xb91658], eax
// 00696d48  687824b600           push 0xb62478
// 00696d4d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00696d55  e886b5f9ff           call 0x6322e0
// 00696d5a  83c404               add esp, 4
// 00696d5d  a35416b900           mov dword ptr [0xb91654], eax
// 00696d62  8b0c24               mov ecx, dword ptr [esp]
// 00696d65  64890d00000000       mov dword ptr fs:[0], ecx
// 00696d6c  83c40c               add esp, 0xc
// 00696d6f  c3                   ret 
// 00696d70  8b0c24               mov ecx, dword ptr [esp]
// 00696d73  a15416b900           mov eax, dword ptr [0xb91654]
// 00696d78  64890d00000000       mov dword ptr fs:[0], ecx
// 00696d7f  83c40c               add esp, 0xc
// 00696d82  c3                   ret 

extern char string_00b62478[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b62478);
    return *name;
}
