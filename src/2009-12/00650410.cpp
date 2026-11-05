// from server: 100% by nuck16
// roc 2009-12 00650410  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650410  64a100000000         mov eax, dword ptr fs:[0]
// 00650416  6aff                 push -1
// 00650418  681e259400           push 0x94251e
// 0065041d  50                   push eax
// 0065041e  b801000000           mov eax, 1
// 00650423  64892500000000       mov dword ptr fs:[0], esp
// 0065042a  8405989ab800         test byte ptr [0xb89a98], al
// 00650430  7532                 jne 0x650464
// 00650432  0905989ab800         or dword ptr [0xb89a98], eax
// 00650438  6a00                 push 0
// 0065043a  683065b500           push 0xb56530
// 0065043f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650447  e8649fdbff           call 0x40a3b0
// 0065044c  50                   push eax
// 0065044d  b9a099b800           mov ecx, 0xb899a0
// 00650452  e8a93b0100           call 0x664000
// 00650457  68e0339800           push 0x9833e0
// 0065045c  e8c8441a00           call 0x7f4929
// 00650461  83c404               add esp, 4
// 00650464  8b0c24               mov ecx, dword ptr [esp]
// 00650467  b8a099b800           mov eax, 0xb899a0
// 0065046c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650473  83c40c               add esp, 0xc
// 00650476  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b56530[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b56530, 0);
    return object;
}
