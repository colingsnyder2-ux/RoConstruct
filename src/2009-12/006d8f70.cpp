// from server: 100% by nuck16
// roc 2009-12 006d8f70  unit: H::V?$RunningAverageItem::?$NonFactoryProduct  size: 99 bytes
//
// 006d8f70  64a100000000         mov eax, dword ptr fs:[0]
// 006d8f76  6aff                 push -1
// 006d8f78  685eaa9400           push 0x94aa5e
// 006d8f7d  50                   push eax
// 006d8f7e  b801000000           mov eax, 1
// 006d8f83  64892500000000       mov dword ptr fs:[0], esp
// 006d8f8a  8405a830b900         test byte ptr [0xb930a8], al
// 006d8f90  752e                 jne 0x6d8fc0
// 006d8f92  0905a830b900         or dword ptr [0xb930a8], eax
// 006d8f98  6850919d00           push 0x9d9150
// 006d8f9d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d8fa5  e83693f5ff           call 0x6322e0
// 006d8faa  83c404               add esp, 4
// 006d8fad  a3a430b900           mov dword ptr [0xb930a4], eax
// 006d8fb2  8b0c24               mov ecx, dword ptr [esp]
// 006d8fb5  64890d00000000       mov dword ptr fs:[0], ecx
// 006d8fbc  83c40c               add esp, 0xc
// 006d8fbf  c3                   ret 
// 006d8fc0  8b0c24               mov ecx, dword ptr [esp]
// 006d8fc3  a1a430b900           mov eax, dword ptr [0xb930a4]
// 006d8fc8  64890d00000000       mov dword ptr fs:[0], ecx
// 006d8fcf  83c40c               add esp, 0xc
// 006d8fd2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("RunningAverageItemDouble");
    return *name;
}
