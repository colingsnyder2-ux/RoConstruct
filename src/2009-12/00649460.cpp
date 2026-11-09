// from server: 100% by nuck16
// roc 2009-12 00649460  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00649460  64a100000000         mov eax, dword ptr fs:[0]
// 00649466  6aff                 push -1
// 00649468  681e1c9400           push 0x941c1e
// 0064946d  50                   push eax
// 0064946e  b801000000           mov eax, 1
// 00649473  64892500000000       mov dword ptr fs:[0], esp
// 0064947a  8405785fb800         test byte ptr [0xb85f78], al
// 00649480  752e                 jne 0x6494b0
// 00649482  0905785fb800         or dword ptr [0xb85f78], eax
// 00649488  6864f4b400           push 0xb4f464
// 0064948d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00649495  e8468efeff           call 0x6322e0
// 0064949a  83c404               add esp, 4
// 0064949d  a3745fb800           mov dword ptr [0xb85f74], eax
// 006494a2  8b0c24               mov ecx, dword ptr [esp]
// 006494a5  64890d00000000       mov dword ptr fs:[0], ecx
// 006494ac  83c40c               add esp, 0xc
// 006494af  c3                   ret 
// 006494b0  8b0c24               mov ecx, dword ptr [esp]
// 006494b3  a1745fb800           mov eax, dword ptr [0xb85f74]
// 006494b8  64890d00000000       mov dword ptr fs:[0], ecx
// 006494bf  83c40c               add esp, 0xc
// 006494c2  c3                   ret 

extern char string_00b4f464[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4f464);
    return *name;
}
