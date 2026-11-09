// from server: 100% by nuck16
// roc 2009-12 006484a0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006484a0  64a100000000         mov eax, dword ptr fs:[0]
// 006484a6  6aff                 push -1
// 006484a8  689e179400           push 0x94179e
// 006484ad  50                   push eax
// 006484ae  b801000000           mov eax, 1
// 006484b3  64892500000000       mov dword ptr fs:[0], esp
// 006484ba  8405585eb800         test byte ptr [0xb85e58], al
// 006484c0  752e                 jne 0x6484f0
// 006484c2  0905585eb800         or dword ptr [0xb85e58], eax
// 006484c8  68002a9e00           push 0x9e2a00
// 006484cd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006484d5  e8069efeff           call 0x6322e0
// 006484da  83c404               add esp, 4
// 006484dd  a3545eb800           mov dword ptr [0xb85e54], eax
// 006484e2  8b0c24               mov ecx, dword ptr [esp]
// 006484e5  64890d00000000       mov dword ptr fs:[0], ecx
// 006484ec  83c40c               add esp, 0xc
// 006484ef  c3                   ret 
// 006484f0  8b0c24               mov ecx, dword ptr [esp]
// 006484f3  a1545eb800           mov eax, dword ptr [0xb85e54]
// 006484f8  64890d00000000       mov dword ptr fs:[0], ecx
// 006484ff  83c40c               add esp, 0xc
// 00648502  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("VelocityMotor");
    return *name;
}
