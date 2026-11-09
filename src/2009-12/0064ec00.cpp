// from server: 100% by nuck16
// roc 2009-12 0064ec00  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064ec00  64a100000000         mov eax, dword ptr fs:[0]
// 0064ec06  6aff                 push -1
// 0064ec08  683e1e9400           push 0x941e3e
// 0064ec0d  50                   push eax
// 0064ec0e  b801000000           mov eax, 1
// 0064ec13  64892500000000       mov dword ptr fs:[0], esp
// 0064ec1a  84059863b800         test byte ptr [0xb86398], al
// 0064ec20  7532                 jne 0x64ec54
// 0064ec22  09059863b800         or dword ptr [0xb86398], eax
// 0064ec28  6a00                 push 0
// 0064ec2a  6890deb500           push 0xb5de90
// 0064ec2f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064ec37  e8e4feffff           call 0x64eb20
// 0064ec3c  50                   push eax
// 0064ec3d  b9a062b800           mov ecx, 0xb862a0
// 0064ec42  e8b9530100           call 0x664000
// 0064ec47  6850379800           push 0x983750
// 0064ec4c  e8d85c1a00           call 0x7f4929
// 0064ec51  83c404               add esp, 4
// 0064ec54  8b0c24               mov ecx, dword ptr [esp]
// 0064ec57  b8a062b800           mov eax, 0xb862a0
// 0064ec5c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ec63  83c40c               add esp, 0xc
// 0064ec66  c3                   ret 

struct Base;
Base &get_64eb20();
extern char string_00b5de90[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64eb20(), string_00b5de90, 0);
    return object;
}
