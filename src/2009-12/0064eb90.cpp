// from server: 100% by nuck16
// roc 2009-12 0064eb90  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064eb90  64a100000000         mov eax, dword ptr fs:[0]
// 0064eb96  6aff                 push -1
// 0064eb98  681e1e9400           push 0x941e1e
// 0064eb9d  50                   push eax
// 0064eb9e  b801000000           mov eax, 1
// 0064eba3  64892500000000       mov dword ptr fs:[0], esp
// 0064ebaa  84059862b800         test byte ptr [0xb86298], al
// 0064ebb0  7532                 jne 0x64ebe4
// 0064ebb2  09059862b800         or dword ptr [0xb86298], eax
// 0064ebb8  6a00                 push 0
// 0064ebba  6880deb500           push 0xb5de80
// 0064ebbf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064ebc7  e854ffffff           call 0x64eb20
// 0064ebcc  50                   push eax
// 0064ebcd  b9a061b800           mov ecx, 0xb861a0
// 0064ebd2  e829540100           call 0x664000
// 0064ebd7  6860379800           push 0x983760
// 0064ebdc  e8485d1a00           call 0x7f4929
// 0064ebe1  83c404               add esp, 4
// 0064ebe4  8b0c24               mov ecx, dword ptr [esp]
// 0064ebe7  b8a061b800           mov eax, 0xb861a0
// 0064ebec  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ebf3  83c40c               add esp, 0xc
// 0064ebf6  c3                   ret 

struct Base;
Base &get_64eb20();
extern char string_00b5de80[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64eb20(), string_00b5de80, 0);
    return object;
}
