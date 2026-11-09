// from server: 100% by nuck16
// roc 2009-12 00650aa0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650aa0  64a100000000         mov eax, dword ptr fs:[0]
// 00650aa6  6aff                 push -1
// 00650aa8  68fe269400           push 0x9426fe
// 00650aad  50                   push eax
// 00650aae  b801000000           mov eax, 1
// 00650ab3  64892500000000       mov dword ptr fs:[0], esp
// 00650aba  840598a9b800         test byte ptr [0xb8a998], al
// 00650ac0  7532                 jne 0x650af4
// 00650ac2  090598a9b800         or dword ptr [0xb8a998], eax
// 00650ac8  6a00                 push 0
// 00650aca  68d4419e00           push 0x9e41d4
// 00650acf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650ad7  e8d498dbff           call 0x40a3b0
// 00650adc  50                   push eax
// 00650add  b9a0a8b800           mov ecx, 0xb8a8a0
// 00650ae2  e819350100           call 0x664000
// 00650ae7  68f0329800           push 0x9832f0
// 00650aec  e8383e1a00           call 0x7f4929
// 00650af1  83c404               add esp, 4
// 00650af4  8b0c24               mov ecx, dword ptr [esp]
// 00650af7  b8a0a8b800           mov eax, 0xb8a8a0
// 00650afc  64890d00000000       mov dword ptr fs:[0], ecx
// 00650b03  83c40c               add esp, 0xc
// 00650b06  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "LocalBackpackSwitcher", 0);
    return object;
}
