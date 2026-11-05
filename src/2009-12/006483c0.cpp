// from server: 100% by nuck16
// roc 2009-12 006483c0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006483c0  64a100000000         mov eax, dword ptr fs:[0]
// 006483c6  6aff                 push -1
// 006483c8  685e179400           push 0x94175e
// 006483cd  50                   push eax
// 006483ce  b801000000           mov eax, 1
// 006483d3  64892500000000       mov dword ptr fs:[0], esp
// 006483da  8405485eb800         test byte ptr [0xb85e48], al
// 006483e0  752e                 jne 0x648410
// 006483e2  0905485eb800         or dword ptr [0xb85e48], eax
// 006483e8  68f0299e00           push 0x9e29f0
// 006483ed  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006483f5  e8e69efeff           call 0x6322e0
// 006483fa  83c404               add esp, 4
// 006483fd  a3445eb800           mov dword ptr [0xb85e44], eax
// 00648402  8b0c24               mov ecx, dword ptr [esp]
// 00648405  64890d00000000       mov dword ptr fs:[0], ecx
// 0064840c  83c40c               add esp, 0xc
// 0064840f  c3                   ret 
// 00648410  8b0c24               mov ecx, dword ptr [esp]
// 00648413  a1445eb800           mov eax, dword ptr [0xb85e44]
// 00648418  64890d00000000       mov dword ptr fs:[0], ecx
// 0064841f  83c40c               add esp, 0xc
// 00648422  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("MotorFeature");
    return *name;
}
