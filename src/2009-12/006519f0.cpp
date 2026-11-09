// from server: 100% by nuck16
// roc 2009-12 006519f0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006519f0  64a100000000         mov eax, dword ptr fs:[0]
// 006519f6  6aff                 push -1
// 006519f8  685e2b9400           push 0x942b5e
// 006519fd  50                   push eax
// 006519fe  b801000000           mov eax, 1
// 00651a03  64892500000000       mov dword ptr fs:[0], esp
// 00651a0a  840598ccb800         test byte ptr [0xb8cc98], al
// 00651a10  7532                 jne 0x651a44
// 00651a12  090598ccb800         or dword ptr [0xb8cc98], eax
// 00651a18  6a00                 push 0
// 00651a1a  68f0a3b500           push 0xb5a3f0
// 00651a1f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651a27  e854ffffff           call 0x651980
// 00651a2c  50                   push eax
// 00651a2d  b9a0cbb800           mov ecx, 0xb8cba0
// 00651a32  e8c9250100           call 0x664000
// 00651a37  68c0309800           push 0x9830c0
// 00651a3c  e8e82e1a00           call 0x7f4929
// 00651a41  83c404               add esp, 4
// 00651a44  8b0c24               mov ecx, dword ptr [esp]
// 00651a47  b8a0cbb800           mov eax, 0xb8cba0
// 00651a4c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651a53  83c40c               add esp, 0xc
// 00651a56  c3                   ret 

struct Base;
Base &get_651980();
extern char string_00b5a3f0[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_651980(), string_00b5a3f0, 0);
    return object;
}
