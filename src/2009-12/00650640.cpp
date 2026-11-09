// from server: 100% by nuck16
// roc 2009-12 00650640  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650640  64a100000000         mov eax, dword ptr fs:[0]
// 00650646  6aff                 push -1
// 00650648  68be259400           push 0x9425be
// 0065064d  50                   push eax
// 0065064e  b801000000           mov eax, 1
// 00650653  64892500000000       mov dword ptr fs:[0], esp
// 0065065a  8405989fb800         test byte ptr [0xb89f98], al
// 00650660  7532                 jne 0x650694
// 00650662  0905989fb800         or dword ptr [0xb89f98], eax
// 00650668  6a00                 push 0
// 0065066a  685c1fb500           push 0xb51f5c
// 0065066f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650677  e8349ddbff           call 0x40a3b0
// 0065067c  50                   push eax
// 0065067d  b9a09eb800           mov ecx, 0xb89ea0
// 00650682  e879390100           call 0x664000
// 00650687  6890339800           push 0x983390
// 0065068c  e898421a00           call 0x7f4929
// 00650691  83c404               add esp, 4
// 00650694  8b0c24               mov ecx, dword ptr [esp]
// 00650697  b8a09eb800           mov eax, 0xb89ea0
// 0065069c  64890d00000000       mov dword ptr fs:[0], ecx
// 006506a3  83c40c               add esp, 0xc
// 006506a6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b51f5c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b51f5c, 0);
    return object;
}
