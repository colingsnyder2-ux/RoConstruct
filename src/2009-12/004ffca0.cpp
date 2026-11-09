// from server: 100% by nuck16
// roc 2009-12 004ffca0  unit: RBX::Network::Player::W4BuildPermission::?$EnumDesc  size: 103 bytes
//
// 004ffca0  64a100000000         mov eax, dword ptr fs:[0]
// 004ffca6  6aff                 push -1
// 004ffca8  684e649300           push 0x93644e
// 004ffcad  50                   push eax
// 004ffcae  b801000000           mov eax, 1
// 004ffcb3  64892500000000       mov dword ptr fs:[0], esp
// 004ffcba  8405a8dfb700         test byte ptr [0xb7dfa8], al
// 004ffcc0  7532                 jne 0x4ffcf4
// 004ffcc2  0905a8dfb700         or dword ptr [0xb7dfa8], eax
// 004ffcc8  6a00                 push 0
// 004ffcca  68b428b100           push 0xb128b4
// 004ffccf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004ffcd7  e8d4a6f0ff           call 0x40a3b0
// 004ffcdc  50                   push eax
// 004ffcdd  b9b0deb700           mov ecx, 0xb7deb0
// 004ffce2  e819431600           call 0x664000
// 004ffce7  6870f39700           push 0x97f370
// 004ffcec  e8384c2f00           call 0x7f4929
// 004ffcf1  83c404               add esp, 4
// 004ffcf4  8b0c24               mov ecx, dword ptr [esp]
// 004ffcf7  b8b0deb700           mov eax, 0xb7deb0
// 004ffcfc  64890d00000000       mov dword ptr fs:[0], ecx
// 004ffd03  83c40c               add esp, 0xc
// 004ffd06  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b128b4[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b128b4, 0);
    return object;
}
