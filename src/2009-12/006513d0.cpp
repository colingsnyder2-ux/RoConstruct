// from server: 100% by nuck16
// roc 2009-12 006513d0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006513d0  64a100000000         mov eax, dword ptr fs:[0]
// 006513d6  6aff                 push -1
// 006513d8  689e299400           push 0x94299e
// 006513dd  50                   push eax
// 006513de  b801000000           mov eax, 1
// 006513e3  64892500000000       mov dword ptr fs:[0], esp
// 006513ea  840598beb800         test byte ptr [0xb8be98], al
// 006513f0  7532                 jne 0x651424
// 006513f2  090598beb800         or dword ptr [0xb8be98], eax
// 006513f8  6a00                 push 0
// 006513fa  68c809b400           push 0xb409c8
// 006513ff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651407  e8a48fdbff           call 0x40a3b0
// 0065140c  50                   push eax
// 0065140d  b9a0bdb800           mov ecx, 0xb8bda0
// 00651412  e8e92b0100           call 0x664000
// 00651417  68a0319800           push 0x9831a0
// 0065141c  e808351a00           call 0x7f4929
// 00651421  83c404               add esp, 4
// 00651424  8b0c24               mov ecx, dword ptr [esp]
// 00651427  b8a0bdb800           mov eax, 0xb8bda0
// 0065142c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651433  83c40c               add esp, 0xc
// 00651436  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b409c8[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b409c8, 0);
    return object;
}
