// from server: 100% by nuck16
// roc 2009-12 00652240  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00652240  64a100000000         mov eax, dword ptr fs:[0]
// 00652246  6aff                 push -1
// 00652248  68be2d9400           push 0x942dbe
// 0065224d  50                   push eax
// 0065224e  b801000000           mov eax, 1
// 00652253  64892500000000       mov dword ptr fs:[0], esp
// 0065225a  840598dfb800         test byte ptr [0xb8df98], al
// 00652260  7532                 jne 0x652294
// 00652262  090598dfb800         or dword ptr [0xb8df98], eax
// 00652268  6a00                 push 0
// 0065226a  68a4f4b400           push 0xb4f4a4
// 0065226f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00652277  e83481dbff           call 0x40a3b0
// 0065227c  50                   push eax
// 0065227d  b9a0deb800           mov ecx, 0xb8dea0
// 00652282  e8791d0100           call 0x664000
// 00652287  68902f9800           push 0x982f90
// 0065228c  e898261a00           call 0x7f4929
// 00652291  83c404               add esp, 4
// 00652294  8b0c24               mov ecx, dword ptr [esp]
// 00652297  b8a0deb800           mov eax, 0xb8dea0
// 0065229c  64890d00000000       mov dword ptr fs:[0], ecx
// 006522a3  83c40c               add esp, 0xc
// 006522a6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4f4a4[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4f4a4, 0);
    return object;
}
