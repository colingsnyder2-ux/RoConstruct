// from server: 100% by nuck16
// roc 2009-12 00650db0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650db0  64a100000000         mov eax, dword ptr fs:[0]
// 00650db6  6aff                 push -1
// 00650db8  68de279400           push 0x9427de
// 00650dbd  50                   push eax
// 00650dbe  b801000000           mov eax, 1
// 00650dc3  64892500000000       mov dword ptr fs:[0], esp
// 00650dca  840598b0b800         test byte ptr [0xb8b098], al
// 00650dd0  7532                 jne 0x650e04
// 00650dd2  090598b0b800         or dword ptr [0xb8b098], eax
// 00650dd8  6a00                 push 0
// 00650dda  6828ce9d00           push 0x9dce28
// 00650ddf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650de7  e854ffffff           call 0x650d40
// 00650dec  50                   push eax
// 00650ded  b9a0afb800           mov ecx, 0xb8afa0
// 00650df2  e809320100           call 0x664000
// 00650df7  6880329800           push 0x983280
// 00650dfc  e8283b1a00           call 0x7f4929
// 00650e01  83c404               add esp, 4
// 00650e04  8b0c24               mov ecx, dword ptr [esp]
// 00650e07  b8a0afb800           mov eax, 0xb8afa0
// 00650e0c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650e13  83c40c               add esp, 0xc
// 00650e16  c3                   ret 

struct Base;
Base &get_650d40();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_650d40(), "StarterGui", 0);
    return object;
}
