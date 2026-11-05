// from server: 100% by nuck16
// roc 2009-12 0064ed50  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064ed50  64a100000000         mov eax, dword ptr fs:[0]
// 0064ed56  6aff                 push -1
// 0064ed58  689e1e9400           push 0x941e9e
// 0064ed5d  50                   push eax
// 0064ed5e  b801000000           mov eax, 1
// 0064ed63  64892500000000       mov dword ptr fs:[0], esp
// 0064ed6a  84059866b800         test byte ptr [0xb86698], al
// 0064ed70  7532                 jne 0x64eda4
// 0064ed72  09059866b800         or dword ptr [0xb86698], eax
// 0064ed78  6a00                 push 0
// 0064ed7a  686cd6b300           push 0xb3d66c
// 0064ed7f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064ed87  e854ffffff           call 0x64ece0
// 0064ed8c  50                   push eax
// 0064ed8d  b9a065b800           mov ecx, 0xb865a0
// 0064ed92  e869520100           call 0x664000
// 0064ed97  6820379800           push 0x983720
// 0064ed9c  e8885b1a00           call 0x7f4929
// 0064eda1  83c404               add esp, 4
// 0064eda4  8b0c24               mov ecx, dword ptr [esp]
// 0064eda7  b8a065b800           mov eax, 0xb865a0
// 0064edac  64890d00000000       mov dword ptr fs:[0], ecx
// 0064edb3  83c40c               add esp, 0xc
// 0064edb6  c3                   ret 

struct Base;
Base &get_64ece0();
extern char string_00b3d66c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64ece0(), string_00b3d66c, 0);
    return object;
}
