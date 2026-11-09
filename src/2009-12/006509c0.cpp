// from server: 100% by nuck16
// roc 2009-12 006509c0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006509c0  64a100000000         mov eax, dword ptr fs:[0]
// 006509c6  6aff                 push -1
// 006509c8  68be269400           push 0x9426be
// 006509cd  50                   push eax
// 006509ce  b801000000           mov eax, 1
// 006509d3  64892500000000       mov dword ptr fs:[0], esp
// 006509da  840598a7b800         test byte ptr [0xb8a798], al
// 006509e0  7532                 jne 0x650a14
// 006509e2  090598a7b800         or dword ptr [0xb8a798], eax
// 006509e8  6a00                 push 0
// 006509ea  6800b7b400           push 0xb4b700
// 006509ef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006509f7  e8b499dbff           call 0x40a3b0
// 006509fc  50                   push eax
// 006509fd  b9a0a6b800           mov ecx, 0xb8a6a0
// 00650a02  e8f9350100           call 0x664000
// 00650a07  6810339800           push 0x983310
// 00650a0c  e8183f1a00           call 0x7f4929
// 00650a11  83c404               add esp, 4
// 00650a14  8b0c24               mov ecx, dword ptr [esp]
// 00650a17  b8a0a6b800           mov eax, 0xb8a6a0
// 00650a1c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650a23  83c40c               add esp, 0xc
// 00650a26  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4b700[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4b700, 0);
    return object;
}
