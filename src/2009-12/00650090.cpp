// from server: 100% by nuck16
// roc 2009-12 00650090  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650090  64a100000000         mov eax, dword ptr fs:[0]
// 00650096  6aff                 push -1
// 00650098  681e249400           push 0x94241e
// 0065009d  50                   push eax
// 0065009e  b801000000           mov eax, 1
// 006500a3  64892500000000       mov dword ptr fs:[0], esp
// 006500aa  84059892b800         test byte ptr [0xb89298], al
// 006500b0  7532                 jne 0x6500e4
// 006500b2  09059892b800         or dword ptr [0xb89298], eax
// 006500b8  6a00                 push 0
// 006500ba  68f0299e00           push 0x9e29f0
// 006500bf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006500c7  e854ffffff           call 0x650020
// 006500cc  50                   push eax
// 006500cd  b9a091b800           mov ecx, 0xb891a0
// 006500d2  e8293f0100           call 0x664000
// 006500d7  6860349800           push 0x983460
// 006500dc  e848481a00           call 0x7f4929
// 006500e1  83c404               add esp, 4
// 006500e4  8b0c24               mov ecx, dword ptr [esp]
// 006500e7  b8a091b800           mov eax, 0xb891a0
// 006500ec  64890d00000000       mov dword ptr fs:[0], ecx
// 006500f3  83c40c               add esp, 0xc
// 006500f6  c3                   ret 

struct Base;
Base &get_650020();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_650020(), "MotorFeature", 0);
    return object;
}
