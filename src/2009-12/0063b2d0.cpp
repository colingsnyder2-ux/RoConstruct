// from server: 100% by nuck16
// roc 2009-12 0063b2d0  unit: RBX::VRunService::?$FactoryProduct  size: 103 bytes
//
// 0063b2d0  64a100000000         mov eax, dword ptr fs:[0]
// 0063b2d6  6aff                 push -1
// 0063b2d8  684e099400           push 0x94094e
// 0063b2dd  50                   push eax
// 0063b2de  b801000000           mov eax, 1
// 0063b2e3  64892500000000       mov dword ptr fs:[0], esp
// 0063b2ea  84058858b800         test byte ptr [0xb85888], al
// 0063b2f0  7532                 jne 0x63b324
// 0063b2f2  09058858b800         or dword ptr [0xb85888], eax
// 0063b2f8  6a00                 push 0
// 0063b2fa  6800c29c00           push 0x9cc200
// 0063b2ff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0063b307  e8a4f0dcff           call 0x40a3b0
// 0063b30c  50                   push eax
// 0063b30d  b99057b800           mov ecx, 0xb85790
// 0063b312  e8e98c0200           call 0x664000
// 0063b317  68701b9800           push 0x981b70
// 0063b31c  e808961b00           call 0x7f4929
// 0063b321  83c404               add esp, 4
// 0063b324  8b0c24               mov ecx, dword ptr [esp]
// 0063b327  b89057b800           mov eax, 0xb85790
// 0063b32c  64890d00000000       mov dword ptr fs:[0], ecx
// 0063b333  83c40c               add esp, 0xc
// 0063b336  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "RunService", 0);
    return object;
}
