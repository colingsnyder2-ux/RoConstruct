// from server: 100% by nuck16
// roc 2009-12 00651a60  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651a60  64a100000000         mov eax, dword ptr fs:[0]
// 00651a66  6aff                 push -1
// 00651a68  687e2b9400           push 0x942b7e
// 00651a6d  50                   push eax
// 00651a6e  b801000000           mov eax, 1
// 00651a73  64892500000000       mov dword ptr fs:[0], esp
// 00651a7a  840598cdb800         test byte ptr [0xb8cd98], al
// 00651a80  7532                 jne 0x651ab4
// 00651a82  090598cdb800         or dword ptr [0xb8cd98], eax
// 00651a88  6a00                 push 0
// 00651a8a  68dca7b500           push 0xb5a7dc
// 00651a8f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651a97  e894fdffff           call 0x651830
// 00651a9c  50                   push eax
// 00651a9d  b9a0ccb800           mov ecx, 0xb8cca0
// 00651aa2  e859250100           call 0x664000
// 00651aa7  68b0309800           push 0x9830b0
// 00651aac  e8782e1a00           call 0x7f4929
// 00651ab1  83c404               add esp, 4
// 00651ab4  8b0c24               mov ecx, dword ptr [esp]
// 00651ab7  b8a0ccb800           mov eax, 0xb8cca0
// 00651abc  64890d00000000       mov dword ptr fs:[0], ecx
// 00651ac3  83c40c               add esp, 0xc
// 00651ac6  c3                   ret 

struct Base;
Base &get_651830();
extern char string_00b5a7dc[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_651830(), string_00b5a7dc, 0);
    return object;
}
