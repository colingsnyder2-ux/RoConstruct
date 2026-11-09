// from server: 100% by nuck16
// roc 2009-12 00650f00  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650f00  64a100000000         mov eax, dword ptr fs:[0]
// 00650f06  6aff                 push -1
// 00650f08  683e289400           push 0x94283e
// 00650f0d  50                   push eax
// 00650f0e  b801000000           mov eax, 1
// 00650f13  64892500000000       mov dword ptr fs:[0], esp
// 00650f1a  840598b3b800         test byte ptr [0xb8b398], al
// 00650f20  7532                 jne 0x650f54
// 00650f22  090598b3b800         or dword ptr [0xb8b398], eax
// 00650f28  6a00                 push 0
// 00650f2a  68ecd5b400           push 0xb4d5ec
// 00650f2f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650f37  e87494dbff           call 0x40a3b0
// 00650f3c  50                   push eax
// 00650f3d  b9a0b2b800           mov ecx, 0xb8b2a0
// 00650f42  e8b9300100           call 0x664000
// 00650f47  6850329800           push 0x983250
// 00650f4c  e8d8391a00           call 0x7f4929
// 00650f51  83c404               add esp, 4
// 00650f54  8b0c24               mov ecx, dword ptr [esp]
// 00650f57  b8a0b2b800           mov eax, 0xb8b2a0
// 00650f5c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650f63  83c40c               add esp, 0xc
// 00650f66  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4d5ec[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4d5ec, 0);
    return object;
}
