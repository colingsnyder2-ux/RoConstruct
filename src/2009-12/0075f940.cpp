// from server: 100% by nuck16
// roc 2009-12 0075f940  unit: RBX::VInstance::?$NonFactoryProduct  size: 99 bytes
//
// 0075f940  64a100000000         mov eax, dword ptr fs:[0]
// 0075f946  6aff                 push -1
// 0075f948  684e1b9500           push 0x951b4e
// 0075f94d  50                   push eax
// 0075f94e  b801000000           mov eax, 1
// 0075f953  64892500000000       mov dword ptr fs:[0], esp
// 0075f95a  8405587ab900         test byte ptr [0xb97a58], al
// 0075f960  752e                 jne 0x75f990
// 0075f962  0905587ab900         or dword ptr [0xb97a58], eax
// 0075f968  6890deb500           push 0xb5de90
// 0075f96d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0075f975  e86629edff           call 0x6322e0
// 0075f97a  83c404               add esp, 4
// 0075f97d  a3547ab900           mov dword ptr [0xb97a54], eax
// 0075f982  8b0c24               mov ecx, dword ptr [esp]
// 0075f985  64890d00000000       mov dword ptr fs:[0], ecx
// 0075f98c  83c40c               add esp, 0xc
// 0075f98f  c3                   ret 
// 0075f990  8b0c24               mov ecx, dword ptr [esp]
// 0075f993  a1547ab900           mov eax, dword ptr [0xb97a54]
// 0075f998  64890d00000000       mov dword ptr fs:[0], ecx
// 0075f99f  83c40c               add esp, 0xc
// 0075f9a2  c3                   ret 

extern char string_00b5de90[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5de90);
    return *name;
}
