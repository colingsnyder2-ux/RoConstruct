// from server: 100% by nuck16
// roc 2009-12 00648eb0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648eb0  64a100000000         mov eax, dword ptr fs:[0]
// 00648eb6  6aff                 push -1
// 00648eb8  687e1a9400           push 0x941a7e
// 00648ebd  50                   push eax
// 00648ebe  b801000000           mov eax, 1
// 00648ec3  64892500000000       mov dword ptr fs:[0], esp
// 00648eca  8405105fb800         test byte ptr [0xb85f10], al
// 00648ed0  752e                 jne 0x648f00
// 00648ed2  0905105fb800         or dword ptr [0xb85f10], eax
// 00648ed8  688c9db500           push 0xb59d8c
// 00648edd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648ee5  e8f693feff           call 0x6322e0
// 00648eea  83c404               add esp, 4
// 00648eed  a30c5fb800           mov dword ptr [0xb85f0c], eax
// 00648ef2  8b0c24               mov ecx, dword ptr [esp]
// 00648ef5  64890d00000000       mov dword ptr fs:[0], ecx
// 00648efc  83c40c               add esp, 0xc
// 00648eff  c3                   ret 
// 00648f00  8b0c24               mov ecx, dword ptr [esp]
// 00648f03  a10c5fb800           mov eax, dword ptr [0xb85f0c]
// 00648f08  64890d00000000       mov dword ptr fs:[0], ecx
// 00648f0f  83c40c               add esp, 0xc
// 00648f12  c3                   ret 

extern char string_00b59d8c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b59d8c);
    return *name;
}
