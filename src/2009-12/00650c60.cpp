// from server: 100% by nuck16
// roc 2009-12 00650c60  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650c60  64a100000000         mov eax, dword ptr fs:[0]
// 00650c66  6aff                 push -1
// 00650c68  687e279400           push 0x94277e
// 00650c6d  50                   push eax
// 00650c6e  b801000000           mov eax, 1
// 00650c73  64892500000000       mov dword ptr fs:[0], esp
// 00650c7a  840598adb800         test byte ptr [0xb8ad98], al
// 00650c80  7532                 jne 0x650cb4
// 00650c82  090598adb800         or dword ptr [0xb8ad98], eax
// 00650c88  6a00                 push 0
// 00650c8a  68507e9e00           push 0x9e7e50
// 00650c8f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650c97  e81497dbff           call 0x40a3b0
// 00650c9c  50                   push eax
// 00650c9d  b9a0acb800           mov ecx, 0xb8aca0
// 00650ca2  e859330100           call 0x664000
// 00650ca7  68b0329800           push 0x9832b0
// 00650cac  e8783c1a00           call 0x7f4929
// 00650cb1  83c404               add esp, 4
// 00650cb4  8b0c24               mov ecx, dword ptr [esp]
// 00650cb7  b8a0acb800           mov eax, 0xb8aca0
// 00650cbc  64890d00000000       mov dword ptr fs:[0], ecx
// 00650cc3  83c40c               add esp, 0xc
// 00650cc6  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "Mouse", 0);
    return object;
}
