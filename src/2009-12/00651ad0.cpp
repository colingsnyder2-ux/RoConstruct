// from server: 100% by nuck16
// roc 2009-12 00651ad0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651ad0  64a100000000         mov eax, dword ptr fs:[0]
// 00651ad6  6aff                 push -1
// 00651ad8  689e2b9400           push 0x942b9e
// 00651add  50                   push eax
// 00651ade  b801000000           mov eax, 1
// 00651ae3  64892500000000       mov dword ptr fs:[0], esp
// 00651aea  840598ceb800         test byte ptr [0xb8ce98], al
// 00651af0  7532                 jne 0x651b24
// 00651af2  090598ceb800         or dword ptr [0xb8ce98], eax
// 00651af8  6a00                 push 0
// 00651afa  6828abb500           push 0xb5ab28
// 00651aff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651b07  e894fdffff           call 0x6518a0
// 00651b0c  50                   push eax
// 00651b0d  b9a0cdb800           mov ecx, 0xb8cda0
// 00651b12  e8e9240100           call 0x664000
// 00651b17  68a0309800           push 0x9830a0
// 00651b1c  e8082e1a00           call 0x7f4929
// 00651b21  83c404               add esp, 4
// 00651b24  8b0c24               mov ecx, dword ptr [esp]
// 00651b27  b8a0cdb800           mov eax, 0xb8cda0
// 00651b2c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651b33  83c40c               add esp, 0xc
// 00651b36  c3                   ret 

struct Base;
Base &get_6518a0();
extern char string_00b5ab28[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_6518a0(), string_00b5ab28, 0);
    return object;
}
