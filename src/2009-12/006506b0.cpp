// from server: 100% by nuck16
// roc 2009-12 006506b0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006506b0  64a100000000         mov eax, dword ptr fs:[0]
// 006506b6  6aff                 push -1
// 006506b8  68de259400           push 0x9425de
// 006506bd  50                   push eax
// 006506be  b801000000           mov eax, 1
// 006506c3  64892500000000       mov dword ptr fs:[0], esp
// 006506ca  840598a0b800         test byte ptr [0xb8a098], al
// 006506d0  7532                 jne 0x650704
// 006506d2  090598a0b800         or dword ptr [0xb8a098], eax
// 006506d8  6a00                 push 0
// 006506da  68101fb500           push 0xb51f10
// 006506df  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006506e7  e8c49cdbff           call 0x40a3b0
// 006506ec  50                   push eax
// 006506ed  b9a09fb800           mov ecx, 0xb89fa0
// 006506f2  e809390100           call 0x664000
// 006506f7  6880339800           push 0x983380
// 006506fc  e828421a00           call 0x7f4929
// 00650701  83c404               add esp, 4
// 00650704  8b0c24               mov ecx, dword ptr [esp]
// 00650707  b8a09fb800           mov eax, 0xb89fa0
// 0065070c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650713  83c40c               add esp, 0xc
// 00650716  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b51f10[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b51f10, 0);
    return object;
}
