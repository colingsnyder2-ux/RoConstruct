// from server: 100% by nuck16
// roc 2009-12 00665b70  unit: RBX::DataModel  size: 99 bytes
//
// 00665b70  64a100000000         mov eax, dword ptr fs:[0]
// 00665b76  6aff                 push -1
// 00665b78  689e409400           push 0x94409e
// 00665b7d  50                   push eax
// 00665b7e  b801000000           mov eax, 1
// 00665b83  64892500000000       mov dword ptr fs:[0], esp
// 00665b8a  8405d409b900         test byte ptr [0xb909d4], al
// 00665b90  752e                 jne 0x665bc0
// 00665b92  0905d409b900         or dword ptr [0xb909d4], eax
// 00665b98  6860ecb500           push 0xb5ec60
// 00665b9d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00665ba5  e836c7fcff           call 0x6322e0
// 00665baa  83c404               add esp, 4
// 00665bad  a3d009b900           mov dword ptr [0xb909d0], eax
// 00665bb2  8b0c24               mov ecx, dword ptr [esp]
// 00665bb5  64890d00000000       mov dword ptr fs:[0], ecx
// 00665bbc  83c40c               add esp, 0xc
// 00665bbf  c3                   ret 
// 00665bc0  8b0c24               mov ecx, dword ptr [esp]
// 00665bc3  a1d009b900           mov eax, dword ptr [0xb909d0]
// 00665bc8  64890d00000000       mov dword ptr fs:[0], ecx
// 00665bcf  83c40c               add esp, 0xc
// 00665bd2  c3                   ret 

extern char string_00b5ec60[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5ec60);
    return *name;
}
