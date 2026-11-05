// from server: 100% by nuck16
// roc 2009-12 00501fc0  unit: RBX::VPants::?$FactoryProduct  size: 103 bytes
//
// 00501fc0  64a100000000         mov eax, dword ptr fs:[0]
// 00501fc6  6aff                 push -1
// 00501fc8  680e659300           push 0x93650e
// 00501fcd  50                   push eax
// 00501fce  b801000000           mov eax, 1
// 00501fd3  64892500000000       mov dword ptr fs:[0], esp
// 00501fda  8405d0e0b700         test byte ptr [0xb7e0d0], al
// 00501fe0  7532                 jne 0x502014
// 00501fe2  0905d0e0b700         or dword ptr [0xb7e0d0], eax
// 00501fe8  6a00                 push 0
// 00501fea  68e0d59d00           push 0x9dd5e0
// 00501fef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00501ff7  e8b483f0ff           call 0x40a3b0
// 00501ffc  50                   push eax
// 00501ffd  b9d8dfb700           mov ecx, 0xb7dfd8
// 00502002  e8f91f1600           call 0x664000
// 00502007  68a0f39700           push 0x97f3a0
// 0050200c  e818292f00           call 0x7f4929
// 00502011  83c404               add esp, 4
// 00502014  8b0c24               mov ecx, dword ptr [esp]
// 00502017  b8d8dfb700           mov eax, 0xb7dfd8
// 0050201c  64890d00000000       mov dword ptr fs:[0], ecx
// 00502023  83c40c               add esp, 0xc
// 00502026  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "Clothing", 0);
    return object;
}
