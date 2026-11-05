// from server: 100% by nuck16
// roc 2009-12 0064f8b0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f8b0  64a100000000         mov eax, dword ptr fs:[0]
// 0064f8b6  6aff                 push -1
// 0064f8b8  68de219400           push 0x9421de
// 0064f8bd  50                   push eax
// 0064f8be  b801000000           mov eax, 1
// 0064f8c3  64892500000000       mov dword ptr fs:[0], esp
// 0064f8ca  84059880b800         test byte ptr [0xb88098], al
// 0064f8d0  7532                 jne 0x64f904
// 0064f8d2  09059880b800         or dword ptr [0xb88098], eax
// 0064f8d8  6a00                 push 0
// 0064f8da  68e8e79c00           push 0x9ce7e8
// 0064f8df  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f8e7  e8943cedff           call 0x523580
// 0064f8ec  50                   push eax
// 0064f8ed  b9a07fb800           mov ecx, 0xb87fa0
// 0064f8f2  e809470100           call 0x664000
// 0064f8f7  6880359800           push 0x983580
// 0064f8fc  e828501a00           call 0x7f4929
// 0064f901  83c404               add esp, 4
// 0064f904  8b0c24               mov ecx, dword ptr [esp]
// 0064f907  b8a07fb800           mov eax, 0xb87fa0
// 0064f90c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f913  83c40c               add esp, 0xc
// 0064f916  c3                   ret 

struct Base;
Base &get_523580();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_523580(), "DataModel", 0);
    return object;
}
