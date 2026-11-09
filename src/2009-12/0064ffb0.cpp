// from server: 100% by nuck16
// roc 2009-12 0064ffb0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064ffb0  64a100000000         mov eax, dword ptr fs:[0]
// 0064ffb6  6aff                 push -1
// 0064ffb8  68de239400           push 0x9423de
// 0064ffbd  50                   push eax
// 0064ffbe  b801000000           mov eax, 1
// 0064ffc3  64892500000000       mov dword ptr fs:[0], esp
// 0064ffca  84059890b800         test byte ptr [0xb89098], al
// 0064ffd0  7532                 jne 0x650004
// 0064ffd2  09059890b800         or dword ptr [0xb89098], eax
// 0064ffd8  6a00                 push 0
// 0064ffda  6838e89d00           push 0x9de838
// 0064ffdf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064ffe7  e844fcffff           call 0x64fc30
// 0064ffec  50                   push eax
// 0064ffed  b9a08fb800           mov ecx, 0xb88fa0
// 0064fff2  e809400100           call 0x664000
// 0064fff7  6880349800           push 0x983480
// 0064fffc  e828491a00           call 0x7f4929
// 00650001  83c404               add esp, 4
// 00650004  8b0c24               mov ecx, dword ptr [esp]
// 00650007  b8a08fb800           mov eax, 0xb88fa0
// 0065000c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650013  83c40c               add esp, 0xc
// 00650016  c3                   ret 

struct Base;
Base &get_64fc30();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64fc30(), "Motor", 0);
    return object;
}
