// from server: 100% by nuck16
// roc 2009-12 006497e0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006497e0  64a100000000         mov eax, dword ptr fs:[0]
// 006497e6  6aff                 push -1
// 006497e8  681e1d9400           push 0x941d1e
// 006497ed  50                   push eax
// 006497ee  b801000000           mov eax, 1
// 006497f3  64892500000000       mov dword ptr fs:[0], esp
// 006497fa  8405b85fb800         test byte ptr [0xb85fb8], al
// 00649800  752e                 jne 0x649830
// 00649802  0905b85fb800         or dword ptr [0xb85fb8], eax
// 00649808  68c0f4b400           push 0xb4f4c0
// 0064980d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00649815  e8c68afeff           call 0x6322e0
// 0064981a  83c404               add esp, 4
// 0064981d  a3b45fb800           mov dword ptr [0xb85fb4], eax
// 00649822  8b0c24               mov ecx, dword ptr [esp]
// 00649825  64890d00000000       mov dword ptr fs:[0], ecx
// 0064982c  83c40c               add esp, 0xc
// 0064982f  c3                   ret 
// 00649830  8b0c24               mov ecx, dword ptr [esp]
// 00649833  a1b45fb800           mov eax, dword ptr [0xb85fb4]
// 00649838  64890d00000000       mov dword ptr fs:[0], ecx
// 0064983f  83c40c               add esp, 0xc
// 00649842  c3                   ret 

extern char string_00b4f4c0[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4f4c0);
    return *name;
}
