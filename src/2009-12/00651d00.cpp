// from server: 100% by nuck16
// roc 2009-12 00651d00  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651d00  64a100000000         mov eax, dword ptr fs:[0]
// 00651d06  6aff                 push -1
// 00651d08  683e2c9400           push 0x942c3e
// 00651d0d  50                   push eax
// 00651d0e  b801000000           mov eax, 1
// 00651d13  64892500000000       mov dword ptr fs:[0], esp
// 00651d1a  840598d3b800         test byte ptr [0xb8d398], al
// 00651d20  7532                 jne 0x651d54
// 00651d22  090598d3b800         or dword ptr [0xb8d398], eax
// 00651d28  6a00                 push 0
// 00651d2a  6804cfb500           push 0xb5cf04
// 00651d2f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651d37  e8e4cdffff           call 0x64eb20
// 00651d3c  50                   push eax
// 00651d3d  b9a0d2b800           mov ecx, 0xb8d2a0
// 00651d42  e8b9220100           call 0x664000
// 00651d47  6850309800           push 0x983050
// 00651d4c  e8d82b1a00           call 0x7f4929
// 00651d51  83c404               add esp, 4
// 00651d54  8b0c24               mov ecx, dword ptr [esp]
// 00651d57  b8a0d2b800           mov eax, 0xb8d2a0
// 00651d5c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651d63  83c40c               add esp, 0xc
// 00651d66  c3                   ret 

struct Base;
Base &get_64eb20();
extern char string_00b5cf04[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64eb20(), string_00b5cf04, 0);
    return object;
}
