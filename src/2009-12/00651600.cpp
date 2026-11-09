// from server: 100% by nuck16
// roc 2009-12 00651600  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651600  64a100000000         mov eax, dword ptr fs:[0]
// 00651606  6aff                 push -1
// 00651608  683e2a9400           push 0x942a3e
// 0065160d  50                   push eax
// 0065160e  b801000000           mov eax, 1
// 00651613  64892500000000       mov dword ptr fs:[0], esp
// 0065161a  840598c3b800         test byte ptr [0xb8c398], al
// 00651620  7532                 jne 0x651654
// 00651622  090598c3b800         or dword ptr [0xb8c398], eax
// 00651628  6a00                 push 0
// 0065162a  687468b300           push 0xb36874
// 0065162f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651637  e8d4dfffff           call 0x64f610
// 0065163c  50                   push eax
// 0065163d  b9a0c2b800           mov ecx, 0xb8c2a0
// 00651642  e8b9290100           call 0x664000
// 00651647  6850319800           push 0x983150
// 0065164c  e8d8321a00           call 0x7f4929
// 00651651  83c404               add esp, 4
// 00651654  8b0c24               mov ecx, dword ptr [esp]
// 00651657  b8a0c2b800           mov eax, 0xb8c2a0
// 0065165c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651663  83c40c               add esp, 0xc
// 00651666  c3                   ret 

struct Base;
Base &get_64f610();
extern char string_00b36874[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64f610(), string_00b36874, 0);
    return object;
}
