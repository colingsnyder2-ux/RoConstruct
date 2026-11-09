// from server: 100% by nuck16
// roc 2009-12 00650870  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650870  64a100000000         mov eax, dword ptr fs:[0]
// 00650876  6aff                 push -1
// 00650878  685e269400           push 0x94265e
// 0065087d  50                   push eax
// 0065087e  b801000000           mov eax, 1
// 00650883  64892500000000       mov dword ptr fs:[0], esp
// 0065088a  840598a4b800         test byte ptr [0xb8a498], al
// 00650890  7532                 jne 0x6508c4
// 00650892  090598a4b800         or dword ptr [0xb8a498], eax
// 00650898  6a00                 push 0
// 0065089a  6850ecb500           push 0xb5ec50
// 0065089f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006508a7  e8e4e2ffff           call 0x64eb90
// 006508ac  50                   push eax
// 006508ad  b9a0a3b800           mov ecx, 0xb8a3a0
// 006508b2  e849370100           call 0x664000
// 006508b7  6840339800           push 0x983340
// 006508bc  e868401a00           call 0x7f4929
// 006508c1  83c404               add esp, 4
// 006508c4  8b0c24               mov ecx, dword ptr [esp]
// 006508c7  b8a0a3b800           mov eax, 0xb8a3a0
// 006508cc  64890d00000000       mov dword ptr fs:[0], ecx
// 006508d3  83c40c               add esp, 0xc
// 006508d6  c3                   ret 

struct Base;
Base &get_64eb90();
extern char string_00b5ec50[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64eb90(), string_00b5ec50, 0);
    return object;
}
