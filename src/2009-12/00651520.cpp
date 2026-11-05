// from server: 100% by nuck16
// roc 2009-12 00651520  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651520  64a100000000         mov eax, dword ptr fs:[0]
// 00651526  6aff                 push -1
// 00651528  68fe299400           push 0x9429fe
// 0065152d  50                   push eax
// 0065152e  b801000000           mov eax, 1
// 00651533  64892500000000       mov dword ptr fs:[0], esp
// 0065153a  840598c1b800         test byte ptr [0xb8c198], al
// 00651540  7532                 jne 0x651574
// 00651542  090598c1b800         or dword ptr [0xb8c198], eax
// 00651548  6a00                 push 0
// 0065154a  688c9db500           push 0xb59d8c
// 0065154f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651557  e8f4d7ffff           call 0x64ed50
// 0065155c  50                   push eax
// 0065155d  b9a0c0b800           mov ecx, 0xb8c0a0
// 00651562  e8992a0100           call 0x664000
// 00651567  6870319800           push 0x983170
// 0065156c  e8b8331a00           call 0x7f4929
// 00651571  83c404               add esp, 4
// 00651574  8b0c24               mov ecx, dword ptr [esp]
// 00651577  b8a0c0b800           mov eax, 0xb8c0a0
// 0065157c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651583  83c40c               add esp, 0xc
// 00651586  c3                   ret 

struct Base;
Base &get_64ed50();
extern char string_00b59d8c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64ed50(), string_00b59d8c, 0);
    return object;
}
