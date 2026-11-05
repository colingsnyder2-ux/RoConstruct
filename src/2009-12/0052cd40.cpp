// from server: 100% by nuck16
// roc 2009-12 0052cd40  unit: RBX::VHint::?$FactoryProduct  size: 103 bytes
//
// 0052cd40  64a100000000         mov eax, dword ptr fs:[0]
// 0052cd46  6aff                 push -1
// 0052cd48  68de909300           push 0x9390de
// 0052cd4d  50                   push eax
// 0052cd4e  b801000000           mov eax, 1
// 0052cd53  64892500000000       mov dword ptr fs:[0], esp
// 0052cd5a  84057002b800         test byte ptr [0xb80270], al
// 0052cd60  7532                 jne 0x52cd94
// 0052cd62  09057002b800         or dword ptr [0xb80270], eax
// 0052cd68  6a00                 push 0
// 0052cd6a  6878b5b400           push 0xb4b578
// 0052cd6f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0052cd77  e834d6edff           call 0x40a3b0
// 0052cd7c  50                   push eax
// 0052cd7d  b97801b800           mov ecx, 0xb80178
// 0052cd82  e879721300           call 0x664000
// 0052cd87  6820049800           push 0x980420
// 0052cd8c  e8987b2c00           call 0x7f4929
// 0052cd91  83c404               add esp, 4
// 0052cd94  8b0c24               mov ecx, dword ptr [esp]
// 0052cd97  b87801b800           mov eax, 0xb80178
// 0052cd9c  64890d00000000       mov dword ptr fs:[0], ecx
// 0052cda3  83c40c               add esp, 0xc
// 0052cda6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4b578[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4b578, 0);
    return object;
}
