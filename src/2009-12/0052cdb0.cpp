// from server: 100% by nuck16
// roc 2009-12 0052cdb0  unit: RBX::VHint::?$FactoryProduct  size: 103 bytes
//
// 0052cdb0  64a100000000         mov eax, dword ptr fs:[0]
// 0052cdb6  6aff                 push -1
// 0052cdb8  68fe909300           push 0x9390fe
// 0052cdbd  50                   push eax
// 0052cdbe  b801000000           mov eax, 1
// 0052cdc3  64892500000000       mov dword ptr fs:[0], esp
// 0052cdca  84057003b800         test byte ptr [0xb80370], al
// 0052cdd0  7532                 jne 0x52ce04
// 0052cdd2  09057003b800         or dword ptr [0xb80370], eax
// 0052cdd8  6a00                 push 0
// 0052cdda  6880b5b400           push 0xb4b580
// 0052cddf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0052cde7  e854ffffff           call 0x52cd40
// 0052cdec  50                   push eax
// 0052cded  b97802b800           mov ecx, 0xb80278
// 0052cdf2  e809721300           call 0x664000
// 0052cdf7  6810049800           push 0x980410
// 0052cdfc  e8287b2c00           call 0x7f4929
// 0052ce01  83c404               add esp, 4
// 0052ce04  8b0c24               mov ecx, dword ptr [esp]
// 0052ce07  b87802b800           mov eax, 0xb80278
// 0052ce0c  64890d00000000       mov dword ptr fs:[0], ecx
// 0052ce13  83c40c               add esp, 0xc
// 0052ce16  c3                   ret 

struct Base;
Base &get_52cd40();
extern char string_00b4b580[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_52cd40(), string_00b4b580, 0);
    return object;
}
