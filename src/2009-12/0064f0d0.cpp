// from server: 100% by nuck16
// roc 2009-12 0064f0d0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f0d0  64a100000000         mov eax, dword ptr fs:[0]
// 0064f0d6  6aff                 push -1
// 0064f0d8  689e1f9400           push 0x941f9e
// 0064f0dd  50                   push eax
// 0064f0de  b801000000           mov eax, 1
// 0064f0e3  64892500000000       mov dword ptr fs:[0], esp
// 0064f0ea  8405986eb800         test byte ptr [0xb86e98], al
// 0064f0f0  7532                 jne 0x64f124
// 0064f0f2  0905986eb800         or dword ptr [0xb86e98], eax
// 0064f0f8  6a00                 push 0
// 0064f0fa  6820119d00           push 0x9d1120
// 0064f0ff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f107  e8a4b2dbff           call 0x40a3b0
// 0064f10c  50                   push eax
// 0064f10d  b9a06db800           mov ecx, 0xb86da0
// 0064f112  e8e94e0100           call 0x664000
// 0064f117  68a0369800           push 0x9836a0
// 0064f11c  e808581a00           call 0x7f4929
// 0064f121  83c404               add esp, 4
// 0064f124  8b0c24               mov ecx, dword ptr [esp]
// 0064f127  b8a06db800           mov eax, 0xb86da0
// 0064f12c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f133  83c40c               add esp, 0xc
// 0064f136  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "StarterGear", 0);
    return object;
}
