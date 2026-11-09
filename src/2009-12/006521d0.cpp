// from server: 100% by nuck16
// roc 2009-12 006521d0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006521d0  64a100000000         mov eax, dword ptr fs:[0]
// 006521d6  6aff                 push -1
// 006521d8  689e2d9400           push 0x942d9e
// 006521dd  50                   push eax
// 006521de  b801000000           mov eax, 1
// 006521e3  64892500000000       mov dword ptr fs:[0], esp
// 006521ea  840598deb800         test byte ptr [0xb8de98], al
// 006521f0  7532                 jne 0x652224
// 006521f2  090598deb800         or dword ptr [0xb8de98], eax
// 006521f8  6a00                 push 0
// 006521fa  6898f4b400           push 0xb4f498
// 006521ff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00652207  e8a481dbff           call 0x40a3b0
// 0065220c  50                   push eax
// 0065220d  b9a0ddb800           mov ecx, 0xb8dda0
// 00652212  e8e91d0100           call 0x664000
// 00652217  68a02f9800           push 0x982fa0
// 0065221c  e808271a00           call 0x7f4929
// 00652221  83c404               add esp, 4
// 00652224  8b0c24               mov ecx, dword ptr [esp]
// 00652227  b8a0ddb800           mov eax, 0xb8dda0
// 0065222c  64890d00000000       mov dword ptr fs:[0], ecx
// 00652233  83c40c               add esp, 0xc
// 00652236  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4f498[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4f498, 0);
    return object;
}
