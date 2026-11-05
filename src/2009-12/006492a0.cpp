// from server: 100% by nuck16
// roc 2009-12 006492a0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006492a0  64a100000000         mov eax, dword ptr fs:[0]
// 006492a6  6aff                 push -1
// 006492a8  689e1b9400           push 0x941b9e
// 006492ad  50                   push eax
// 006492ae  b801000000           mov eax, 1
// 006492b3  64892500000000       mov dword ptr fs:[0], esp
// 006492ba  8405585fb800         test byte ptr [0xb85f58], al
// 006492c0  752e                 jne 0x6492f0
// 006492c2  0905585fb800         or dword ptr [0xb85f58], eax
// 006492c8  6814cfb500           push 0xb5cf14
// 006492cd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006492d5  e80690feff           call 0x6322e0
// 006492da  83c404               add esp, 4
// 006492dd  a3545fb800           mov dword ptr [0xb85f54], eax
// 006492e2  8b0c24               mov ecx, dword ptr [esp]
// 006492e5  64890d00000000       mov dword ptr fs:[0], ecx
// 006492ec  83c40c               add esp, 0xc
// 006492ef  c3                   ret 
// 006492f0  8b0c24               mov ecx, dword ptr [esp]
// 006492f3  a1545fb800           mov eax, dword ptr [0xb85f54]
// 006492f8  64890d00000000       mov dword ptr fs:[0], ecx
// 006492ff  83c40c               add esp, 0xc
// 00649302  c3                   ret 

extern char string_00b5cf14[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5cf14);
    return *name;
}
