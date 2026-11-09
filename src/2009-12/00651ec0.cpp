// from server: 100% by nuck16
// roc 2009-12 00651ec0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00651ec0
//
// 00651ec0  64a100000000         mov eax, dword ptr fs:[0]
// 00651ec6  6aff                 push -1
// 00651ec8  68be2c9400           push 0x942cbe
// 00651ecd  50                   push eax
// 00651ece  b801000000           mov eax, 1
// 00651ed3  64892500000000       mov dword ptr fs:[0], esp
// 00651eda  840598d7b800         test byte ptr [0xb8d798], al
// 00651ee0  7532                 jne 0x651f14
// 00651ee2  090598d7b800         or dword ptr [0xb8d798], eax
// 00651ee8  6a00                 push 0
// 00651eea  683cd8b500           push 0xb5d83c
// 00651eef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651ef7  e8b484dbff           call 0x40a3b0
// 00651efc  50                   push eax
// 00651efd  b9a0d6b800           mov ecx, 0xb8d6a0
// 00651f02  e8f9200100           call 0x664000
// 00651f07  6810309800           push 0x983010
// 00651f0c  e8182a1a00           call 0x7f4929
// 00651f11  83c404               add esp, 4
// 00651f14  8b0c24               mov ecx, dword ptr [esp]
// 00651f17  b8a0d6b800           mov eax, 0xb8d6a0
// 00651f1c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651f23  83c40c               add esp, 0xc
// 00651f26  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b5d83c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b5d83c, 0);
    return object;
}
