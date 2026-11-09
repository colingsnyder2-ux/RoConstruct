// from server: 100% by nuck16
// roc 2009-12 0064f1b0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f1b0  64a100000000         mov eax, dword ptr fs:[0]
// 0064f1b6  6aff                 push -1
// 0064f1b8  68de1f9400           push 0x941fde
// 0064f1bd  50                   push eax
// 0064f1be  b801000000           mov eax, 1
// 0064f1c3  64892500000000       mov dword ptr fs:[0], esp
// 0064f1ca  84059870b800         test byte ptr [0xb87098], al
// 0064f1d0  7532                 jne 0x64f204
// 0064f1d2  09059870b800         or dword ptr [0xb87098], eax
// 0064f1d8  6a00                 push 0
// 0064f1da  687859b300           push 0xb35978
// 0064f1df  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f1e7  e854ffffff           call 0x64f140
// 0064f1ec  50                   push eax
// 0064f1ed  b9a06fb800           mov ecx, 0xb86fa0
// 0064f1f2  e8094e0100           call 0x664000
// 0064f1f7  6880369800           push 0x983680
// 0064f1fc  e828571a00           call 0x7f4929
// 0064f201  83c404               add esp, 4
// 0064f204  8b0c24               mov ecx, dword ptr [esp]
// 0064f207  b8a06fb800           mov eax, 0xb86fa0
// 0064f20c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f213  83c40c               add esp, 0xc
// 0064f216  c3                   ret 

struct Base;
Base &get_64f140();
extern char string_00b35978[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64f140(), string_00b35978, 0);
    return object;
}
