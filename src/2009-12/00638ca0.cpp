// from server: 100% by nuck16
// roc 2009-12 00638ca0  unit: RBX::VSelection::?$FactoryProduct  size: 103 bytes
//
// 00638ca0  64a100000000         mov eax, dword ptr fs:[0]
// 00638ca6  6aff                 push -1
// 00638ca8  680e079400           push 0x94070e
// 00638cad  50                   push eax
// 00638cae  b801000000           mov eax, 1
// 00638cb3  64892500000000       mov dword ptr fs:[0], esp
// 00638cba  8405f056b800         test byte ptr [0xb856f0], al
// 00638cc0  7532                 jne 0x638cf4
// 00638cc2  0905f056b800         or dword ptr [0xb856f0], eax
// 00638cc8  6a00                 push 0
// 00638cca  68d0c09c00           push 0x9cc0d0
// 00638ccf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00638cd7  e8d416ddff           call 0x40a3b0
// 00638cdc  50                   push eax
// 00638cdd  b9f855b800           mov ecx, 0xb855f8
// 00638ce2  e819b30200           call 0x664000
// 00638ce7  68101b9800           push 0x981b10
// 00638cec  e838bc1b00           call 0x7f4929
// 00638cf1  83c404               add esp, 4
// 00638cf4  8b0c24               mov ecx, dword ptr [esp]
// 00638cf7  b8f855b800           mov eax, 0xb855f8
// 00638cfc  64890d00000000       mov dword ptr fs:[0], ecx
// 00638d03  83c40c               add esp, 0xc
// 00638d06  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "Selection", 0);
    return object;
}
