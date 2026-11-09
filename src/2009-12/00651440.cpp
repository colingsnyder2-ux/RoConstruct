// from server: 100% by nuck16
// roc 2009-12 00651440  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651440  64a100000000         mov eax, dword ptr fs:[0]
// 00651446  6aff                 push -1
// 00651448  68be299400           push 0x9429be
// 0065144d  50                   push eax
// 0065144e  b801000000           mov eax, 1
// 00651453  64892500000000       mov dword ptr fs:[0], esp
// 0065145a  840598bfb800         test byte ptr [0xb8bf98], al
// 00651460  7532                 jne 0x651494
// 00651462  090598bfb800         or dword ptr [0xb8bf98], eax
// 00651468  6a00                 push 0
// 0065146a  68dc09b400           push 0xb409dc
// 0065146f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651477  e8348fdbff           call 0x40a3b0
// 0065147c  50                   push eax
// 0065147d  b9a0beb800           mov ecx, 0xb8bea0
// 00651482  e8792b0100           call 0x664000
// 00651487  6890319800           push 0x983190
// 0065148c  e898341a00           call 0x7f4929
// 00651491  83c404               add esp, 4
// 00651494  8b0c24               mov ecx, dword ptr [esp]
// 00651497  b8a0beb800           mov eax, 0xb8bea0
// 0065149c  64890d00000000       mov dword ptr fs:[0], ecx
// 006514a3  83c40c               add esp, 0xc
// 006514a6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b409dc[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b409dc, 0);
    return object;
}
