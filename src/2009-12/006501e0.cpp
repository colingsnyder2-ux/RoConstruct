// from server: 100% by nuck16
// roc 2009-12 006501e0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006501e0  64a100000000         mov eax, dword ptr fs:[0]
// 006501e6  6aff                 push -1
// 006501e8  687e249400           push 0x94247e
// 006501ed  50                   push eax
// 006501ee  b801000000           mov eax, 1
// 006501f3  64892500000000       mov dword ptr fs:[0], esp
// 006501fa  84059895b800         test byte ptr [0xb89598], al
// 00650200  7532                 jne 0x650234
// 00650202  09059895b800         or dword ptr [0xb89598], eax
// 00650208  6a00                 push 0
// 0065020a  680c1eb400           push 0xb41e0c
// 0065020f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650217  e814aff2ff           call 0x57b130
// 0065021c  50                   push eax
// 0065021d  b9a094b800           mov ecx, 0xb894a0
// 00650222  e8d93d0100           call 0x664000
// 00650227  6830349800           push 0x983430
// 0065022c  e8f8461a00           call 0x7f4929
// 00650231  83c404               add esp, 4
// 00650234  8b0c24               mov ecx, dword ptr [esp]
// 00650237  b8a094b800           mov eax, 0xb894a0
// 0065023c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650243  83c40c               add esp, 0xc
// 00650246  c3                   ret 

struct Base;
Base &get_57b130();
extern char string_00b41e0c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_57b130(), string_00b41e0c, 0);
    return object;
}
