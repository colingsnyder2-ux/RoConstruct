// from server: 100% by nuck16
// roc 2009-12 006508e0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006508e0  64a100000000         mov eax, dword ptr fs:[0]
// 006508e6  6aff                 push -1
// 006508e8  687e269400           push 0x94267e
// 006508ed  50                   push eax
// 006508ee  b801000000           mov eax, 1
// 006508f3  64892500000000       mov dword ptr fs:[0], esp
// 006508fa  840598a5b800         test byte ptr [0xb8a598], al
// 00650900  7532                 jne 0x650934
// 00650902  090598a5b800         or dword ptr [0xb8a598], eax
// 00650908  6a00                 push 0
// 0065090a  687c68b500           push 0xb5687c
// 0065090f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650917  e854ffffff           call 0x650870
// 0065091c  50                   push eax
// 0065091d  b9a0a4b800           mov ecx, 0xb8a4a0
// 00650922  e8d9360100           call 0x664000
// 00650927  6830339800           push 0x983330
// 0065092c  e8f83f1a00           call 0x7f4929
// 00650931  83c404               add esp, 4
// 00650934  8b0c24               mov ecx, dword ptr [esp]
// 00650937  b8a0a4b800           mov eax, 0xb8a4a0
// 0065093c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650943  83c40c               add esp, 0xc
// 00650946  c3                   ret 

struct Base;
Base &get_650870();
extern char string_00b5687c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_650870(), string_00b5687c, 0);
    return object;
}
