// from server: 100% by nuck16
// roc 2009-12 00768050  unit: RBX::VHandles::?$FactoryProduct  size: 99 bytes
//
// 00768050  64a100000000         mov eax, dword ptr fs:[0]
// 00768056  6aff                 push -1
// 00768058  681e259500           push 0x95251e
// 0076805d  50                   push eax
// 0076805e  b801000000           mov eax, 1
// 00768063  64892500000000       mov dword ptr fs:[0], esp
// 0076806a  8405e47db900         test byte ptr [0xb97de4], al
// 00768070  752e                 jne 0x7680a0
// 00768072  0905e47db900         or dword ptr [0xb97de4], eax
// 00768078  6850ecb500           push 0xb5ec50
// 0076807d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00768085  e856a2ecff           call 0x6322e0
// 0076808a  83c404               add esp, 4
// 0076808d  a3e07db900           mov dword ptr [0xb97de0], eax
// 00768092  8b0c24               mov ecx, dword ptr [esp]
// 00768095  64890d00000000       mov dword ptr fs:[0], ecx
// 0076809c  83c40c               add esp, 0xc
// 0076809f  c3                   ret 
// 007680a0  8b0c24               mov ecx, dword ptr [esp]
// 007680a3  a1e07db900           mov eax, dword ptr [0xb97de0]
// 007680a8  64890d00000000       mov dword ptr fs:[0], ecx
// 007680af  83c40c               add esp, 0xc
// 007680b2  c3                   ret 

extern char string_00b5ec50[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5ec50);
    return *name;
}
