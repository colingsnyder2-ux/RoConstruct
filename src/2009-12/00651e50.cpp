// from server: 100% by nuck16
// roc 2009-12 00651e50  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651e50  64a100000000         mov eax, dword ptr fs:[0]
// 00651e56  6aff                 push -1
// 00651e58  689e2c9400           push 0x942c9e
// 00651e5d  50                   push eax
// 00651e5e  b801000000           mov eax, 1
// 00651e63  64892500000000       mov dword ptr fs:[0], esp
// 00651e6a  840598d6b800         test byte ptr [0xb8d698], al
// 00651e70  7532                 jne 0x651ea4
// 00651e72  090598d6b800         or dword ptr [0xb8d698], eax
// 00651e78  6a00                 push 0
// 00651e7a  68008eb400           push 0xb48e00
// 00651e7f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651e87  e82485dbff           call 0x40a3b0
// 00651e8c  50                   push eax
// 00651e8d  b9a0d5b800           mov ecx, 0xb8d5a0
// 00651e92  e869210100           call 0x664000
// 00651e97  6820309800           push 0x983020
// 00651e9c  e8882a1a00           call 0x7f4929
// 00651ea1  83c404               add esp, 4
// 00651ea4  8b0c24               mov ecx, dword ptr [esp]
// 00651ea7  b8a0d5b800           mov eax, 0xb8d5a0
// 00651eac  64890d00000000       mov dword ptr fs:[0], ecx
// 00651eb3  83c40c               add esp, 0xc
// 00651eb6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b48e00[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b48e00, 0);
    return object;
}
