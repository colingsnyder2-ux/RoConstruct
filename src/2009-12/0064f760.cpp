// from server: 100% by nuck16
// roc 2009-12 0064f760  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f760  64a100000000         mov eax, dword ptr fs:[0]
// 0064f766  6aff                 push -1
// 0064f768  687e219400           push 0x94217e
// 0064f76d  50                   push eax
// 0064f76e  b801000000           mov eax, 1
// 0064f773  64892500000000       mov dword ptr fs:[0], esp
// 0064f77a  8405987db800         test byte ptr [0xb87d98], al
// 0064f780  7532                 jne 0x64f7b4
// 0064f782  0905987db800         or dword ptr [0xb87d98], eax
// 0064f788  6a00                 push 0
// 0064f78a  68d43fb500           push 0xb53fd4
// 0064f78f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f797  e814acdbff           call 0x40a3b0
// 0064f79c  50                   push eax
// 0064f79d  b9a07cb800           mov ecx, 0xb87ca0
// 0064f7a2  e859480100           call 0x664000
// 0064f7a7  68b0359800           push 0x9835b0
// 0064f7ac  e878511a00           call 0x7f4929
// 0064f7b1  83c404               add esp, 4
// 0064f7b4  8b0c24               mov ecx, dword ptr [esp]
// 0064f7b7  b8a07cb800           mov eax, 0xb87ca0
// 0064f7bc  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f7c3  83c40c               add esp, 0xc
// 0064f7c6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b53fd4[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b53fd4, 0);
    return object;
}
