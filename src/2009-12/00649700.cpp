// from server: 100% by nuck16
// roc 2009-12 00649700  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00649700  64a100000000         mov eax, dword ptr fs:[0]
// 00649706  6aff                 push -1
// 00649708  68de1c9400           push 0x941cde
// 0064970d  50                   push eax
// 0064970e  b801000000           mov eax, 1
// 00649713  64892500000000       mov dword ptr fs:[0], esp
// 0064971a  8405a85fb800         test byte ptr [0xb85fa8], al
// 00649720  752e                 jne 0x649750
// 00649722  0905a85fb800         or dword ptr [0xb85fa8], eax
// 00649728  68a4f4b400           push 0xb4f4a4
// 0064972d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00649735  e8a68bfeff           call 0x6322e0
// 0064973a  83c404               add esp, 4
// 0064973d  a3a45fb800           mov dword ptr [0xb85fa4], eax
// 00649742  8b0c24               mov ecx, dword ptr [esp]
// 00649745  64890d00000000       mov dword ptr fs:[0], ecx
// 0064974c  83c40c               add esp, 0xc
// 0064974f  c3                   ret 
// 00649750  8b0c24               mov ecx, dword ptr [esp]
// 00649753  a1a45fb800           mov eax, dword ptr [0xb85fa4]
// 00649758  64890d00000000       mov dword ptr fs:[0], ecx
// 0064975f  83c40c               add esp, 0xc
// 00649762  c3                   ret 

extern char string_00b4f4a4[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4f4a4);
    return *name;
}
