// from server: 100% by nuck16
// roc 2009-12 00651280  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651280  64a100000000         mov eax, dword ptr fs:[0]
// 00651286  6aff                 push -1
// 00651288  683e299400           push 0x94293e
// 0065128d  50                   push eax
// 0065128e  b801000000           mov eax, 1
// 00651293  64892500000000       mov dword ptr fs:[0], esp
// 0065129a  840598bbb800         test byte ptr [0xb8bb98], al
// 006512a0  7532                 jne 0x6512d4
// 006512a2  090598bbb800         or dword ptr [0xb8bb98], eax
// 006512a8  6a00                 push 0
// 006512aa  68d48ab400           push 0xb48ad4
// 006512af  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006512b7  e8f490dbff           call 0x40a3b0
// 006512bc  50                   push eax
// 006512bd  b9a0bab800           mov ecx, 0xb8baa0
// 006512c2  e8392d0100           call 0x664000
// 006512c7  68d0319800           push 0x9831d0
// 006512cc  e858361a00           call 0x7f4929
// 006512d1  83c404               add esp, 4
// 006512d4  8b0c24               mov ecx, dword ptr [esp]
// 006512d7  b8a0bab800           mov eax, 0xb8baa0
// 006512dc  64890d00000000       mov dword ptr fs:[0], ecx
// 006512e3  83c40c               add esp, 0xc
// 006512e6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b48ad4[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b48ad4, 0);
    return object;
}
