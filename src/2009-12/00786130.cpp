// from server: 100% by nuck16
// roc 2009-12 00786130  unit: RBX::ArrowTool  size: 99 bytes
//
// 00786130  64a100000000         mov eax, dword ptr fs:[0]
// 00786136  6aff                 push -1
// 00786138  684e3b9500           push 0x953b4e
// 0078613d  50                   push eax
// 0078613e  b801000000           mov eax, 1
// 00786143  64892500000000       mov dword ptr fs:[0], esp
// 0078614a  8405a488b900         test byte ptr [0xb988a4], al
// 00786150  752e                 jne 0x786180
// 00786152  0905a488b900         or dword ptr [0xb988a4], eax
// 00786158  68b422b600           push 0xb622b4
// 0078615d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00786165  e876c1eaff           call 0x6322e0
// 0078616a  83c404               add esp, 4
// 0078616d  a3a088b900           mov dword ptr [0xb988a0], eax
// 00786172  8b0c24               mov ecx, dword ptr [esp]
// 00786175  64890d00000000       mov dword ptr fs:[0], ecx
// 0078617c  83c40c               add esp, 0xc
// 0078617f  c3                   ret 
// 00786180  8b0c24               mov ecx, dword ptr [esp]
// 00786183  a1a088b900           mov eax, dword ptr [0xb988a0]
// 00786188  64890d00000000       mov dword ptr fs:[0], ecx
// 0078618f  83c40c               add esp, 0xc
// 00786192  c3                   ret 

extern char string_00b622b4[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b622b4);
    return *name;
}
