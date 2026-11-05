// from server: 100% by nuck16
// roc 2009-12 006d4070  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d4070  64a100000000         mov eax, dword ptr fs:[0]
// 006d4076  6aff                 push -1
// 006d4078  686ea39400           push 0x94a36e
// 006d407d  50                   push eax
// 006d407e  b801000000           mov eax, 1
// 006d4083  64892500000000       mov dword ptr fs:[0], esp
// 006d408a  84057c2cb900         test byte ptr [0xb92c7c], al
// 006d4090  752e                 jne 0x6d40c0
// 006d4092  09057c2cb900         or dword ptr [0xb92c7c], eax
// 006d4098  683824b600           push 0xb62438
// 006d409d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d40a5  e836e2f5ff           call 0x6322e0
// 006d40aa  83c404               add esp, 4
// 006d40ad  a3782cb900           mov dword ptr [0xb92c78], eax
// 006d40b2  8b0c24               mov ecx, dword ptr [esp]
// 006d40b5  64890d00000000       mov dword ptr fs:[0], ecx
// 006d40bc  83c40c               add esp, 0xc
// 006d40bf  c3                   ret 
// 006d40c0  8b0c24               mov ecx, dword ptr [esp]
// 006d40c3  a1782cb900           mov eax, dword ptr [0xb92c78]
// 006d40c8  64890d00000000       mov dword ptr fs:[0], ecx
// 006d40cf  83c40c               add esp, 0xc
// 006d40d2  c3                   ret 

extern char string_00b62438[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b62438);
    return *name;
}
