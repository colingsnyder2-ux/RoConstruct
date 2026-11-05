// from server: 100% by nuck16
// roc 2009-12 00648510  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648510  64a100000000         mov eax, dword ptr fs:[0]
// 00648516  6aff                 push -1
// 00648518  68be179400           push 0x9417be
// 0064851d  50                   push eax
// 0064851e  b801000000           mov eax, 1
// 00648523  64892500000000       mov dword ptr fs:[0], esp
// 0064852a  8405605eb800         test byte ptr [0xb85e60], al
// 00648530  752e                 jne 0x648560
// 00648532  0905605eb800         or dword ptr [0xb85e60], eax
// 00648538  6810319e00           push 0x9e3110
// 0064853d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648545  e8969dfeff           call 0x6322e0
// 0064854a  83c404               add esp, 4
// 0064854d  a35c5eb800           mov dword ptr [0xb85e5c], eax
// 00648552  8b0c24               mov ecx, dword ptr [esp]
// 00648555  64890d00000000       mov dword ptr fs:[0], ecx
// 0064855c  83c40c               add esp, 0xc
// 0064855f  c3                   ret 
// 00648560  8b0c24               mov ecx, dword ptr [esp]
// 00648563  a15c5eb800           mov eax, dword ptr [0xb85e5c]
// 00648568  64890d00000000       mov dword ptr fs:[0], ecx
// 0064856f  83c40c               add esp, 0xc
// 00648572  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Flag");
    return *name;
}
