// from server: 100% by nuck16
// roc 2009-12 00512bb0  unit: RBX::Network::Players  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00512bb0
//
// 00512bb0  64a100000000         mov eax, dword ptr fs:[0]
// 00512bb6  6aff                 push -1
// 00512bb8  681e769300           push 0x93761e
// 00512bbd  50                   push eax
// 00512bbe  b801000000           mov eax, 1
// 00512bc3  64892500000000       mov dword ptr fs:[0], esp
// 00512bca  8405f8e8b700         test byte ptr [0xb7e8f8], al
// 00512bd0  752e                 jne 0x512c00
// 00512bd2  0905f8e8b700         or dword ptr [0xb7e8f8], eax
// 00512bd8  68008eb400           push 0xb48e00
// 00512bdd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00512be5  e8f6f61100           call 0x6322e0
// 00512bea  83c404               add esp, 4
// 00512bed  a3f4e8b700           mov dword ptr [0xb7e8f4], eax
// 00512bf2  8b0c24               mov ecx, dword ptr [esp]
// 00512bf5  64890d00000000       mov dword ptr fs:[0], ecx
// 00512bfc  83c40c               add esp, 0xc
// 00512bff  c3                   ret 
// 00512c00  8b0c24               mov ecx, dword ptr [esp]
// 00512c03  a1f4e8b700           mov eax, dword ptr [0xb7e8f4]
// 00512c08  64890d00000000       mov dword ptr fs:[0], ecx
// 00512c0f  83c40c               add esp, 0xc
// 00512c12  c3                   ret 

extern char string_00b48e00[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b48e00);
    return *name;
}
