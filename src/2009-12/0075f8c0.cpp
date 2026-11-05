// from server: 100% by nuck16
// roc 2009-12 0075f8c0  unit: RBX::VInstance::?$NonFactoryProduct  size: 99 bytes
//
// 0075f8c0  64a100000000         mov eax, dword ptr fs:[0]
// 0075f8c6  6aff                 push -1
// 0075f8c8  682e1b9500           push 0x951b2e
// 0075f8cd  50                   push eax
// 0075f8ce  b801000000           mov eax, 1
// 0075f8d3  64892500000000       mov dword ptr fs:[0], esp
// 0075f8da  84054c7ab900         test byte ptr [0xb97a4c], al
// 0075f8e0  752e                 jne 0x75f910
// 0075f8e2  09054c7ab900         or dword ptr [0xb97a4c], eax
// 0075f8e8  6880deb500           push 0xb5de80
// 0075f8ed  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0075f8f5  e8e629edff           call 0x6322e0
// 0075f8fa  83c404               add esp, 4
// 0075f8fd  a3487ab900           mov dword ptr [0xb97a48], eax
// 0075f902  8b0c24               mov ecx, dword ptr [esp]
// 0075f905  64890d00000000       mov dword ptr fs:[0], ecx
// 0075f90c  83c40c               add esp, 0xc
// 0075f90f  c3                   ret 
// 0075f910  8b0c24               mov ecx, dword ptr [esp]
// 0075f913  a1487ab900           mov eax, dword ptr [0xb97a48]
// 0075f918  64890d00000000       mov dword ptr fs:[0], ecx
// 0075f91f  83c40c               add esp, 0xc
// 0075f922  c3                   ret 

extern char string_00b5de80[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5de80);
    return *name;
}
