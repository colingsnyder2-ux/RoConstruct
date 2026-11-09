// from server: 100% by nuck16
// roc 2009-12 004f5c60  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f5c60  64a100000000         mov eax, dword ptr fs:[0]
// 004f5c66  6aff                 push -1
// 004f5c68  68ae579300           push 0x9357ae
// 004f5c6d  50                   push eax
// 004f5c6e  b801000000           mov eax, 1
// 004f5c73  64892500000000       mov dword ptr fs:[0], esp
// 004f5c7a  840518deb700         test byte ptr [0xb7de18], al
// 004f5c80  752e                 jne 0x4f5cb0
// 004f5c82  090518deb700         or dword ptr [0xb7de18], eax
// 004f5c88  68d48ab400           push 0xb48ad4
// 004f5c8d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f5c95  e846c61300           call 0x6322e0
// 004f5c9a  83c404               add esp, 4
// 004f5c9d  a314deb700           mov dword ptr [0xb7de14], eax
// 004f5ca2  8b0c24               mov ecx, dword ptr [esp]
// 004f5ca5  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5cac  83c40c               add esp, 0xc
// 004f5caf  c3                   ret 
// 004f5cb0  8b0c24               mov ecx, dword ptr [esp]
// 004f5cb3  a114deb700           mov eax, dword ptr [0xb7de14]
// 004f5cb8  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5cbf  83c40c               add esp, 0xc
// 004f5cc2  c3                   ret 

extern char string_00b48ad4[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b48ad4);
    return *name;
}
