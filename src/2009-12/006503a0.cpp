// from server: 100% by nuck16
// roc 2009-12 006503a0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006503a0  64a100000000         mov eax, dword ptr fs:[0]
// 006503a6  6aff                 push -1
// 006503a8  68fe249400           push 0x9424fe
// 006503ad  50                   push eax
// 006503ae  b801000000           mov eax, 1
// 006503b3  64892500000000       mov dword ptr fs:[0], esp
// 006503ba  84059899b800         test byte ptr [0xb89998], al
// 006503c0  7532                 jne 0x6503f4
// 006503c2  09059899b800         or dword ptr [0xb89998], eax
// 006503c8  6a00                 push 0
// 006503ca  6848349e00           push 0x9e3448
// 006503cf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006503d7  e8d49fdbff           call 0x40a3b0
// 006503dc  50                   push eax
// 006503dd  b9a098b800           mov ecx, 0xb898a0
// 006503e2  e8193c0100           call 0x664000
// 006503e7  68f0339800           push 0x9833f0
// 006503ec  e838451a00           call 0x7f4929
// 006503f1  83c404               add esp, 4
// 006503f4  8b0c24               mov ecx, dword ptr [esp]
// 006503f7  b8a098b800           mov eax, 0xb898a0
// 006503fc  64890d00000000       mov dword ptr fs:[0], ecx
// 00650403  83c40c               add esp, 0xc
// 00650406  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "FlagStandService", 0);
    return object;
}
