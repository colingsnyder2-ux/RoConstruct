// from server: 100% by nuck16
// roc 2009-12 0064eb20  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064eb20  64a100000000         mov eax, dword ptr fs:[0]
// 0064eb26  6aff                 push -1
// 0064eb28  68fe1d9400           push 0x941dfe
// 0064eb2d  50                   push eax
// 0064eb2e  b801000000           mov eax, 1
// 0064eb33  64892500000000       mov dword ptr fs:[0], esp
// 0064eb3a  84059861b800         test byte ptr [0xb86198], al
// 0064eb40  7532                 jne 0x64eb74
// 0064eb42  09059861b800         or dword ptr [0xb86198], eax
// 0064eb48  6a00                 push 0
// 0064eb4a  680cdcb500           push 0xb5dc0c
// 0064eb4f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064eb57  e854b8dbff           call 0x40a3b0
// 0064eb5c  50                   push eax
// 0064eb5d  b9a060b800           mov ecx, 0xb860a0
// 0064eb62  e899540100           call 0x664000
// 0064eb67  6870379800           push 0x983770
// 0064eb6c  e8b85d1a00           call 0x7f4929
// 0064eb71  83c404               add esp, 4
// 0064eb74  8b0c24               mov ecx, dword ptr [esp]
// 0064eb77  b8a060b800           mov eax, 0xb860a0
// 0064eb7c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064eb83  83c40c               add esp, 0xc
// 0064eb86  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b5dc0c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b5dc0c, 0);
    return object;
}
