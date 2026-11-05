// from server: 100% by nuck16
// roc 2009-12 00648660  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648660  64a100000000         mov eax, dword ptr fs:[0]
// 00648666  6aff                 push -1
// 00648668  681e189400           push 0x94181e
// 0064866d  50                   push eax
// 0064866e  b801000000           mov eax, 1
// 00648673  64892500000000       mov dword ptr fs:[0], esp
// 0064867a  8405785eb800         test byte ptr [0xb85e78], al
// 00648680  752e                 jne 0x6486b0
// 00648682  0905785eb800         or dword ptr [0xb85e78], eax
// 00648688  683065b500           push 0xb56530
// 0064868d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648695  e8469cfeff           call 0x6322e0
// 0064869a  83c404               add esp, 4
// 0064869d  a3745eb800           mov dword ptr [0xb85e74], eax
// 006486a2  8b0c24               mov ecx, dword ptr [esp]
// 006486a5  64890d00000000       mov dword ptr fs:[0], ecx
// 006486ac  83c40c               add esp, 0xc
// 006486af  c3                   ret 
// 006486b0  8b0c24               mov ecx, dword ptr [esp]
// 006486b3  a1745eb800           mov eax, dword ptr [0xb85e74]
// 006486b8  64890d00000000       mov dword ptr fs:[0], ecx
// 006486bf  83c40c               add esp, 0xc
// 006486c2  c3                   ret 

extern char string_00b56530[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b56530);
    return *name;
}
