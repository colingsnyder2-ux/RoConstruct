// from server: 100% by nuck16
// roc 2009-12 0064f920  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f920  64a100000000         mov eax, dword ptr fs:[0]
// 0064f926  6aff                 push -1
// 0064f928  68fe219400           push 0x9421fe
// 0064f92d  50                   push eax
// 0064f92e  b801000000           mov eax, 1
// 0064f933  64892500000000       mov dword ptr fs:[0], esp
// 0064f93a  84059881b800         test byte ptr [0xb88198], al
// 0064f940  7532                 jne 0x64f974
// 0064f942  09059881b800         or dword ptr [0xb88198], eax
// 0064f948  6a00                 push 0
// 0064f94a  68584ab500           push 0xb54a58
// 0064f94f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f957  e854aadbff           call 0x40a3b0
// 0064f95c  50                   push eax
// 0064f95d  b9a080b800           mov ecx, 0xb880a0
// 0064f962  e899460100           call 0x664000
// 0064f967  6870359800           push 0x983570
// 0064f96c  e8b84f1a00           call 0x7f4929
// 0064f971  83c404               add esp, 4
// 0064f974  8b0c24               mov ecx, dword ptr [esp]
// 0064f977  b8a080b800           mov eax, 0xb880a0
// 0064f97c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f983  83c40c               add esp, 0xc
// 0064f986  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b54a58[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b54a58, 0);
    return object;
}
