// from server: 100% by nuck16
// roc 2009-12 006511a0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006511a0  64a100000000         mov eax, dword ptr fs:[0]
// 006511a6  6aff                 push -1
// 006511a8  68fe289400           push 0x9428fe
// 006511ad  50                   push eax
// 006511ae  b801000000           mov eax, 1
// 006511b3  64892500000000       mov dword ptr fs:[0], esp
// 006511ba  840598b9b800         test byte ptr [0xb8b998], al
// 006511c0  7532                 jne 0x6511f4
// 006511c2  090598b9b800         or dword ptr [0xb8b998], eax
// 006511c8  6a00                 push 0
// 006511ca  681c98b500           push 0xb5981c
// 006511cf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006511d7  e8b4d9ffff           call 0x64eb90
// 006511dc  50                   push eax
// 006511dd  b9a0b8b800           mov ecx, 0xb8b8a0
// 006511e2  e8192e0100           call 0x664000
// 006511e7  68f0319800           push 0x9831f0
// 006511ec  e838371a00           call 0x7f4929
// 006511f1  83c404               add esp, 4
// 006511f4  8b0c24               mov ecx, dword ptr [esp]
// 006511f7  b8a0b8b800           mov eax, 0xb8b8a0
// 006511fc  64890d00000000       mov dword ptr fs:[0], ecx
// 00651203  83c40c               add esp, 0xc
// 00651206  c3                   ret 

struct Base;
Base &get_64eb90();
extern char string_00b5981c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64eb90(), string_00b5981c, 0);
    return object;
}
