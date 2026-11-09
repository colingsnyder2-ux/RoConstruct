// from server: 100% by nuck16
// roc 2009-12 00650f70  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650f70  64a100000000         mov eax, dword ptr fs:[0]
// 00650f76  6aff                 push -1
// 00650f78  685e289400           push 0x94285e
// 00650f7d  50                   push eax
// 00650f7e  b801000000           mov eax, 1
// 00650f83  64892500000000       mov dword ptr fs:[0], esp
// 00650f8a  840598b4b800         test byte ptr [0xb8b498], al
// 00650f90  7532                 jne 0x650fc4
// 00650f92  090598b4b800         or dword ptr [0xb8b498], eax
// 00650f98  6a00                 push 0
// 00650f9a  687828b400           push 0xb42878
// 00650f9f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650fa7  e80494dbff           call 0x40a3b0
// 00650fac  50                   push eax
// 00650fad  b9a0b3b800           mov ecx, 0xb8b3a0
// 00650fb2  e849300100           call 0x664000
// 00650fb7  6840329800           push 0x983240
// 00650fbc  e868391a00           call 0x7f4929
// 00650fc1  83c404               add esp, 4
// 00650fc4  8b0c24               mov ecx, dword ptr [esp]
// 00650fc7  b8a0b3b800           mov eax, 0xb8b3a0
// 00650fcc  64890d00000000       mov dword ptr fs:[0], ecx
// 00650fd3  83c40c               add esp, 0xc
// 00650fd6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b42878[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b42878, 0);
    return object;
}
