// from server: 100% by nuck16
// roc 2009-12 0064f300  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f300  64a100000000         mov eax, dword ptr fs:[0]
// 0064f306  6aff                 push -1
// 0064f308  683e209400           push 0x94203e
// 0064f30d  50                   push eax
// 0064f30e  b801000000           mov eax, 1
// 0064f313  64892500000000       mov dword ptr fs:[0], esp
// 0064f31a  84059873b800         test byte ptr [0xb87398], al
// 0064f320  7532                 jne 0x64f354
// 0064f322  09059873b800         or dword ptr [0xb87398], eax
// 0064f328  6a00                 push 0
// 0064f32a  681449b400           push 0xb44914
// 0064f32f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f337  e814faffff           call 0x64ed50
// 0064f33c  50                   push eax
// 0064f33d  b9a072b800           mov ecx, 0xb872a0
// 0064f342  e8b94c0100           call 0x664000
// 0064f347  6850369800           push 0x983650
// 0064f34c  e8d8551a00           call 0x7f4929
// 0064f351  83c404               add esp, 4
// 0064f354  8b0c24               mov ecx, dword ptr [esp]
// 0064f357  b8a072b800           mov eax, 0xb872a0
// 0064f35c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f363  83c40c               add esp, 0xc
// 0064f366  c3                   ret 

struct Base;
Base &get_64ed50();
extern char string_00b44914[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64ed50(), string_00b44914, 0);
    return object;
}
