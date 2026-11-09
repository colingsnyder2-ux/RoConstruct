// from server: 100% by nuck16
// roc 2009-12 00649690  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00649690  64a100000000         mov eax, dword ptr fs:[0]
// 00649696  6aff                 push -1
// 00649698  68be1c9400           push 0x941cbe
// 0064969d  50                   push eax
// 0064969e  b801000000           mov eax, 1
// 006496a3  64892500000000       mov dword ptr fs:[0], esp
// 006496aa  8405a05fb800         test byte ptr [0xb85fa0], al
// 006496b0  752e                 jne 0x6496e0
// 006496b2  0905a05fb800         or dword ptr [0xb85fa0], eax
// 006496b8  6898f4b400           push 0xb4f498
// 006496bd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006496c5  e8168cfeff           call 0x6322e0
// 006496ca  83c404               add esp, 4
// 006496cd  a39c5fb800           mov dword ptr [0xb85f9c], eax
// 006496d2  8b0c24               mov ecx, dword ptr [esp]
// 006496d5  64890d00000000       mov dword ptr fs:[0], ecx
// 006496dc  83c40c               add esp, 0xc
// 006496df  c3                   ret 
// 006496e0  8b0c24               mov ecx, dword ptr [esp]
// 006496e3  a19c5fb800           mov eax, dword ptr [0xb85f9c]
// 006496e8  64890d00000000       mov dword ptr fs:[0], ecx
// 006496ef  83c40c               add esp, 0xc
// 006496f2  c3                   ret 

extern char string_00b4f498[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4f498);
    return *name;
}
