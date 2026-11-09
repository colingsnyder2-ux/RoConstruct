// from server: 100% by nuck16
// roc 2009-12 00651c20  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651c20  64a100000000         mov eax, dword ptr fs:[0]
// 00651c26  6aff                 push -1
// 00651c28  68fe2b9400           push 0x942bfe
// 00651c2d  50                   push eax
// 00651c2e  b801000000           mov eax, 1
// 00651c33  64892500000000       mov dword ptr fs:[0], esp
// 00651c3a  840598d1b800         test byte ptr [0xb8d198], al
// 00651c40  7532                 jne 0x651c74
// 00651c42  090598d1b800         or dword ptr [0xb8d198], eax
// 00651c48  6a00                 push 0
// 00651c4a  68d8bdb500           push 0xb5bdd8
// 00651c4f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651c57  e8b4fcffff           call 0x651910
// 00651c5c  50                   push eax
// 00651c5d  b9a0d0b800           mov ecx, 0xb8d0a0
// 00651c62  e899230100           call 0x664000
// 00651c67  6870309800           push 0x983070
// 00651c6c  e8b82c1a00           call 0x7f4929
// 00651c71  83c404               add esp, 4
// 00651c74  8b0c24               mov ecx, dword ptr [esp]
// 00651c77  b8a0d0b800           mov eax, 0xb8d0a0
// 00651c7c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651c83  83c40c               add esp, 0xc
// 00651c86  c3                   ret 

struct Base;
Base &get_651910();
extern char string_00b5bdd8[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_651910(), string_00b5bdd8, 0);
    return object;
}
