// from server: 100% by nuck16
// roc 2009-12 006505d0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006505d0  64a100000000         mov eax, dword ptr fs:[0]
// 006505d6  6aff                 push -1
// 006505d8  689e259400           push 0x94259e
// 006505dd  50                   push eax
// 006505de  b801000000           mov eax, 1
// 006505e3  64892500000000       mov dword ptr fs:[0], esp
// 006505ea  8405989eb800         test byte ptr [0xb89e98], al
// 006505f0  7532                 jne 0x650624
// 006505f2  0905989eb800         or dword ptr [0xb89e98], eax
// 006505f8  6a00                 push 0
// 006505fa  68501fb500           push 0xb51f50
// 006505ff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650607  e8a49ddbff           call 0x40a3b0
// 0065060c  50                   push eax
// 0065060d  b9a09db800           mov ecx, 0xb89da0
// 00650612  e8e9390100           call 0x664000
// 00650617  68a0339800           push 0x9833a0
// 0065061c  e808431a00           call 0x7f4929
// 00650621  83c404               add esp, 4
// 00650624  8b0c24               mov ecx, dword ptr [esp]
// 00650627  b8a09db800           mov eax, 0xb89da0
// 0065062c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650633  83c40c               add esp, 0xc
// 00650636  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b51f50[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b51f50, 0);
    return object;
}
