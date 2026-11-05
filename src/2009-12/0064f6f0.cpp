// from server: 100% by nuck16
// roc 2009-12 0064f6f0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f6f0  64a100000000         mov eax, dword ptr fs:[0]
// 0064f6f6  6aff                 push -1
// 0064f6f8  685e219400           push 0x94215e
// 0064f6fd  50                   push eax
// 0064f6fe  b801000000           mov eax, 1
// 0064f703  64892500000000       mov dword ptr fs:[0], esp
// 0064f70a  8405987cb800         test byte ptr [0xb87c98], al
// 0064f710  7532                 jne 0x64f744
// 0064f712  0905987cb800         or dword ptr [0xb87c98], eax
// 0064f718  6a00                 push 0
// 0064f71a  685cbfb300           push 0xb3bf5c
// 0064f71f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f727  e884acdbff           call 0x40a3b0
// 0064f72c  50                   push eax
// 0064f72d  b9a07bb800           mov ecx, 0xb87ba0
// 0064f732  e8c9480100           call 0x664000
// 0064f737  68c0359800           push 0x9835c0
// 0064f73c  e8e8511a00           call 0x7f4929
// 0064f741  83c404               add esp, 4
// 0064f744  8b0c24               mov ecx, dword ptr [esp]
// 0064f747  b8a07bb800           mov eax, 0xb87ba0
// 0064f74c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f753  83c40c               add esp, 0xc
// 0064f756  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b3bf5c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b3bf5c, 0);
    return object;
}
