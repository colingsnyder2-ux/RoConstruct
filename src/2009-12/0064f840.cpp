// from server: 100% by nuck16
// roc 2009-12 0064f840  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f840  64a100000000         mov eax, dword ptr fs:[0]
// 0064f846  6aff                 push -1
// 0064f848  68be219400           push 0x9421be
// 0064f84d  50                   push eax
// 0064f84e  b801000000           mov eax, 1
// 0064f853  64892500000000       mov dword ptr fs:[0], esp
// 0064f85a  8405987fb800         test byte ptr [0xb87f98], al
// 0064f860  7532                 jne 0x64f894
// 0064f862  0905987fb800         or dword ptr [0xb87f98], eax
// 0064f868  6a00                 push 0
// 0064f86a  686847b500           push 0xb54768
// 0064f86f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f877  e834abdbff           call 0x40a3b0
// 0064f87c  50                   push eax
// 0064f87d  b9a07eb800           mov ecx, 0xb87ea0
// 0064f882  e879470100           call 0x664000
// 0064f887  6890359800           push 0x983590
// 0064f88c  e898501a00           call 0x7f4929
// 0064f891  83c404               add esp, 4
// 0064f894  8b0c24               mov ecx, dword ptr [esp]
// 0064f897  b8a07eb800           mov eax, 0xb87ea0
// 0064f89c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f8a3  83c40c               add esp, 0xc
// 0064f8a6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b54768[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b54768, 0);
    return object;
}
