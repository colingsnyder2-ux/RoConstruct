// from server: 100% by nuck16
// roc 2009-12 00665a90  unit: RBX::DataModel  size: 99 bytes
//
// 00665a90  64a100000000         mov eax, dword ptr fs:[0]
// 00665a96  6aff                 push -1
// 00665a98  685e409400           push 0x94405e
// 00665a9d  50                   push eax
// 00665a9e  b801000000           mov eax, 1
// 00665aa3  64892500000000       mov dword ptr fs:[0], esp
// 00665aaa  8405c409b900         test byte ptr [0xb909c4], al
// 00665ab0  752e                 jne 0x665ae0
// 00665ab2  0905c409b900         or dword ptr [0xb909c4], eax
// 00665ab8  6840e79c00           push 0x9ce740
// 00665abd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00665ac5  e816c8fcff           call 0x6322e0
// 00665aca  83c404               add esp, 4
// 00665acd  a3c009b900           mov dword ptr [0xb909c0], eax
// 00665ad2  8b0c24               mov ecx, dword ptr [esp]
// 00665ad5  64890d00000000       mov dword ptr fs:[0], ecx
// 00665adc  83c40c               add esp, 0xc
// 00665adf  c3                   ret 
// 00665ae0  8b0c24               mov ecx, dword ptr [esp]
// 00665ae3  a1c009b900           mov eax, dword ptr [0xb909c0]
// 00665ae8  64890d00000000       mov dword ptr fs:[0], ecx
// 00665aef  83c40c               add esp, 0xc
// 00665af2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("ServiceProvider");
    return *name;
}
