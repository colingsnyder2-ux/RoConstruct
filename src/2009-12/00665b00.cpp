// from server: 100% by nuck16
// roc 2009-12 00665b00  unit: RBX::DataModel  size: 99 bytes
//
// 00665b00  64a100000000         mov eax, dword ptr fs:[0]
// 00665b06  6aff                 push -1
// 00665b08  687e409400           push 0x94407e
// 00665b0d  50                   push eax
// 00665b0e  b801000000           mov eax, 1
// 00665b13  64892500000000       mov dword ptr fs:[0], esp
// 00665b1a  8405cc09b900         test byte ptr [0xb909cc], al
// 00665b20  752e                 jne 0x665b50
// 00665b22  0905cc09b900         or dword ptr [0xb909cc], eax
// 00665b28  6878789e00           push 0x9e7878
// 00665b2d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00665b35  e8a6c7fcff           call 0x6322e0
// 00665b3a  83c404               add esp, 4
// 00665b3d  a3c809b900           mov dword ptr [0xb909c8], eax
// 00665b42  8b0c24               mov ecx, dword ptr [esp]
// 00665b45  64890d00000000       mov dword ptr fs:[0], ecx
// 00665b4c  83c40c               add esp, 0xc
// 00665b4f  c3                   ret 
// 00665b50  8b0c24               mov ecx, dword ptr [esp]
// 00665b53  a1c809b900           mov eax, dword ptr [0xb909c8]
// 00665b58  64890d00000000       mov dword ptr fs:[0], ecx
// 00665b5f  83c40c               add esp, 0xc
// 00665b62  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("BadgeService");
    return *name;
}
