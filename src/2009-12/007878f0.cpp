// from server: 100% by nuck16
// roc 2009-12 007878f0  unit: RBX::NewNullTool  size: 99 bytes
//
// 007878f0  64a100000000         mov eax, dword ptr fs:[0]
// 007878f6  6aff                 push -1
// 007878f8  68fe3b9500           push 0x953bfe
// 007878fd  50                   push eax
// 007878fe  b801000000           mov eax, 1
// 00787903  64892500000000       mov dword ptr fs:[0], esp
// 0078790a  8405bc88b900         test byte ptr [0xb988bc], al
// 00787910  752e                 jne 0x787940
// 00787912  0905bc88b900         or dword ptr [0xb988bc], eax
// 00787918  684023b600           push 0xb62340
// 0078791d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00787925  e8b6a9eaff           call 0x6322e0
// 0078792a  83c404               add esp, 4
// 0078792d  a3b888b900           mov dword ptr [0xb988b8], eax
// 00787932  8b0c24               mov ecx, dword ptr [esp]
// 00787935  64890d00000000       mov dword ptr fs:[0], ecx
// 0078793c  83c40c               add esp, 0xc
// 0078793f  c3                   ret 
// 00787940  8b0c24               mov ecx, dword ptr [esp]
// 00787943  a1b888b900           mov eax, dword ptr [0xb988b8]
// 00787948  64890d00000000       mov dword ptr fs:[0], ecx
// 0078794f  83c40c               add esp, 0xc
// 00787952  c3                   ret 

extern char string_00b62340[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b62340);
    return *name;
}
