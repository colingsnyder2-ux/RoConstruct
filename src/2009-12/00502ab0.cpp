// from server: 100% by nuck16
// roc 2009-12 00502ab0  unit: RBX::VTimerService::?$FactoryProduct::Creator  size: 103 bytes
//
// 00502ab0  64a100000000         mov eax, dword ptr fs:[0]
// 00502ab6  6aff                 push -1
// 00502ab8  688e659300           push 0x93658e
// 00502abd  50                   push eax
// 00502abe  b801000000           mov eax, 1
// 00502ac3  64892500000000       mov dword ptr fs:[0], esp
// 00502aca  8405e0e2b700         test byte ptr [0xb7e2e0], al
// 00502ad0  7532                 jne 0x502b04
// 00502ad2  0905e0e2b700         or dword ptr [0xb7e2e0], eax
// 00502ad8  6a00                 push 0
// 00502ada  68c0d59d00           push 0x9dd5c0
// 00502adf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00502ae7  e8d4f4ffff           call 0x501fc0
// 00502aec  50                   push eax
// 00502aed  b9e8e1b700           mov ecx, 0xb7e1e8
// 00502af2  e809151600           call 0x664000
// 00502af7  6880f39700           push 0x97f380
// 00502afc  e8281e2f00           call 0x7f4929
// 00502b01  83c404               add esp, 4
// 00502b04  8b0c24               mov ecx, dword ptr [esp]
// 00502b07  b8e8e1b700           mov eax, 0xb7e1e8
// 00502b0c  64890d00000000       mov dword ptr fs:[0], ecx
// 00502b13  83c40c               add esp, 0xc
// 00502b16  c3                   ret 

struct Base;
Base &get_501fc0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_501fc0(), "Shirt", 0);
    return object;
}
