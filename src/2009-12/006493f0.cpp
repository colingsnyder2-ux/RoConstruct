// from server: 100% by nuck16
// roc 2009-12 006493f0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 006493f0  64a100000000         mov eax, dword ptr fs:[0]
// 006493f6  6aff                 push -1
// 006493f8  68fe1b9400           push 0x941bfe
// 006493fd  50                   push eax
// 006493fe  b801000000           mov eax, 1
// 00649403  64892500000000       mov dword ptr fs:[0], esp
// 0064940a  8405705fb800         test byte ptr [0xb85f70], al
// 00649410  752e                 jne 0x649440
// 00649412  0905705fb800         or dword ptr [0xb85f70], eax
// 00649418  684cf4b400           push 0xb4f44c
// 0064941d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00649425  e8b68efeff           call 0x6322e0
// 0064942a  83c404               add esp, 4
// 0064942d  a36c5fb800           mov dword ptr [0xb85f6c], eax
// 00649432  8b0c24               mov ecx, dword ptr [esp]
// 00649435  64890d00000000       mov dword ptr fs:[0], ecx
// 0064943c  83c40c               add esp, 0xc
// 0064943f  c3                   ret 
// 00649440  8b0c24               mov ecx, dword ptr [esp]
// 00649443  a16c5fb800           mov eax, dword ptr [0xb85f6c]
// 00649448  64890d00000000       mov dword ptr fs:[0], ecx
// 0064944f  83c40c               add esp, 0xc
// 00649452  c3                   ret 

extern char string_00b4f44c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4f44c);
    return *name;
}
