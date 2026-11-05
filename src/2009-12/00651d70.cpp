// from server: 100% by nuck16
// roc 2009-12 00651d70  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651d70  64a100000000         mov eax, dword ptr fs:[0]
// 00651d76  6aff                 push -1
// 00651d78  685e2c9400           push 0x942c5e
// 00651d7d  50                   push eax
// 00651d7e  b801000000           mov eax, 1
// 00651d83  64892500000000       mov dword ptr fs:[0], esp
// 00651d8a  840598d4b800         test byte ptr [0xb8d498], al
// 00651d90  7532                 jne 0x651dc4
// 00651d92  090598d4b800         or dword ptr [0xb8d498], eax
// 00651d98  6a00                 push 0
// 00651d9a  6814cfb500           push 0xb5cf14
// 00651d9f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651da7  e854ffffff           call 0x651d00
// 00651dac  50                   push eax
// 00651dad  b9a0d3b800           mov ecx, 0xb8d3a0
// 00651db2  e849220100           call 0x664000
// 00651db7  6840309800           push 0x983040
// 00651dbc  e8682b1a00           call 0x7f4929
// 00651dc1  83c404               add esp, 4
// 00651dc4  8b0c24               mov ecx, dword ptr [esp]
// 00651dc7  b8a0d3b800           mov eax, 0xb8d3a0
// 00651dcc  64890d00000000       mov dword ptr fs:[0], ecx
// 00651dd3  83c40c               add esp, 0xc
// 00651dd6  c3                   ret 

struct Base;
Base &get_651d00();
extern char string_00b5cf14[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_651d00(), string_00b5cf14, 0);
    return object;
}
