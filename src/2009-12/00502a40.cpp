// from server: 100% by nuck16
// roc 2009-12 00502a40  unit: RBX::VTimerService::?$FactoryProduct::Creator  size: 103 bytes
//
// 00502a40  64a100000000         mov eax, dword ptr fs:[0]
// 00502a46  6aff                 push -1
// 00502a48  686e659300           push 0x93656e
// 00502a4d  50                   push eax
// 00502a4e  b801000000           mov eax, 1
// 00502a53  64892500000000       mov dword ptr fs:[0], esp
// 00502a5a  8405e0e1b700         test byte ptr [0xb7e1e0], al
// 00502a60  7532                 jne 0x502a94
// 00502a62  0905e0e1b700         or dword ptr [0xb7e1e0], eax
// 00502a68  6a00                 push 0
// 00502a6a  68c8d59d00           push 0x9dd5c8
// 00502a6f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00502a77  e844f5ffff           call 0x501fc0
// 00502a7c  50                   push eax
// 00502a7d  b9e8e0b700           mov ecx, 0xb7e0e8
// 00502a82  e879151600           call 0x664000
// 00502a87  6890f39700           push 0x97f390
// 00502a8c  e8981e2f00           call 0x7f4929
// 00502a91  83c404               add esp, 4
// 00502a94  8b0c24               mov ecx, dword ptr [esp]
// 00502a97  b8e8e0b700           mov eax, 0xb7e0e8
// 00502a9c  64890d00000000       mov dword ptr fs:[0], ecx
// 00502aa3  83c40c               add esp, 0xc
// 00502aa6  c3                   ret 

struct Base;
Base &get_501fc0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_501fc0(), "Pants", 0);
    return object;
}
