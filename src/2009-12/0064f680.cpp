// from server: 100% by nuck16
// roc 2009-12 0064f680  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f680  64a100000000         mov eax, dword ptr fs:[0]
// 0064f686  6aff                 push -1
// 0064f688  683e219400           push 0x94213e
// 0064f68d  50                   push eax
// 0064f68e  b801000000           mov eax, 1
// 0064f693  64892500000000       mov dword ptr fs:[0], esp
// 0064f69a  8405987bb800         test byte ptr [0xb87b98], al
// 0064f6a0  7532                 jne 0x64f6d4
// 0064f6a2  0905987bb800         or dword ptr [0xb87b98], eax
// 0064f6a8  6a00                 push 0
// 0064f6aa  68d83bb500           push 0xb53bd8
// 0064f6af  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f6b7  e8f4acdbff           call 0x40a3b0
// 0064f6bc  50                   push eax
// 0064f6bd  b9a07ab800           mov ecx, 0xb87aa0
// 0064f6c2  e839490100           call 0x664000
// 0064f6c7  68d0359800           push 0x9835d0
// 0064f6cc  e858521a00           call 0x7f4929
// 0064f6d1  83c404               add esp, 4
// 0064f6d4  8b0c24               mov ecx, dword ptr [esp]
// 0064f6d7  b8a07ab800           mov eax, 0xb87aa0
// 0064f6dc  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f6e3  83c40c               add esp, 0xc
// 0064f6e6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b53bd8[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b53bd8, 0);
    return object;
}
