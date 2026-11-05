// from server: 100% by nuck16
// roc 2009-12 00651de0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651de0  64a100000000         mov eax, dword ptr fs:[0]
// 00651de6  6aff                 push -1
// 00651de8  687e2c9400           push 0x942c7e
// 00651ded  50                   push eax
// 00651dee  b801000000           mov eax, 1
// 00651df3  64892500000000       mov dword ptr fs:[0], esp
// 00651dfa  840598d5b800         test byte ptr [0xb8d598], al
// 00651e00  7532                 jne 0x651e34
// 00651e02  090598d5b800         or dword ptr [0xb8d598], eax
// 00651e08  6a00                 push 0
// 00651e0a  6828cfb500           push 0xb5cf28
// 00651e0f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651e17  e8e4feffff           call 0x651d00
// 00651e1c  50                   push eax
// 00651e1d  b9a0d4b800           mov ecx, 0xb8d4a0
// 00651e22  e8d9210100           call 0x664000
// 00651e27  6830309800           push 0x983030
// 00651e2c  e8f82a1a00           call 0x7f4929
// 00651e31  83c404               add esp, 4
// 00651e34  8b0c24               mov ecx, dword ptr [esp]
// 00651e37  b8a0d4b800           mov eax, 0xb8d4a0
// 00651e3c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651e43  83c40c               add esp, 0xc
// 00651e46  c3                   ret 

struct Base;
Base &get_651d00();
extern char string_00b5cf28[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_651d00(), string_00b5cf28, 0);
    return object;
}
