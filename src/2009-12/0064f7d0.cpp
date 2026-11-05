// from server: 100% by nuck16
// roc 2009-12 0064f7d0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f7d0  64a100000000         mov eax, dword ptr fs:[0]
// 0064f7d6  6aff                 push -1
// 0064f7d8  689e219400           push 0x94219e
// 0064f7dd  50                   push eax
// 0064f7de  b801000000           mov eax, 1
// 0064f7e3  64892500000000       mov dword ptr fs:[0], esp
// 0064f7ea  8405987eb800         test byte ptr [0xb87e98], al
// 0064f7f0  7532                 jne 0x64f824
// 0064f7f2  0905987eb800         or dword ptr [0xb87e98], eax
// 0064f7f8  6a00                 push 0
// 0064f7fa  686041b500           push 0xb54160
// 0064f7ff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f807  e8a4abdbff           call 0x40a3b0
// 0064f80c  50                   push eax
// 0064f80d  b9a07db800           mov ecx, 0xb87da0
// 0064f812  e8e9470100           call 0x664000
// 0064f817  68a0359800           push 0x9835a0
// 0064f81c  e808511a00           call 0x7f4929
// 0064f821  83c404               add esp, 4
// 0064f824  8b0c24               mov ecx, dword ptr [esp]
// 0064f827  b8a07db800           mov eax, 0xb87da0
// 0064f82c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f833  83c40c               add esp, 0xc
// 0064f836  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b54160[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b54160, 0);
    return object;
}
