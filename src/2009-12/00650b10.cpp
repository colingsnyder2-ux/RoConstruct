// from server: 100% by nuck16
// roc 2009-12 00650b10  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650b10  64a100000000         mov eax, dword ptr fs:[0]
// 00650b16  6aff                 push -1
// 00650b18  681e279400           push 0x94271e
// 00650b1d  50                   push eax
// 00650b1e  b801000000           mov eax, 1
// 00650b23  64892500000000       mov dword ptr fs:[0], esp
// 00650b2a  840598aab800         test byte ptr [0xb8aa98], al
// 00650b30  7532                 jne 0x650b64
// 00650b32  090598aab800         or dword ptr [0xb8aa98], eax
// 00650b38  6a00                 push 0
// 00650b3a  68ec419e00           push 0x9e41ec
// 00650b3f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650b47  e86498dbff           call 0x40a3b0
// 00650b4c  50                   push eax
// 00650b4d  b9a0a9b800           mov ecx, 0xb8a9a0
// 00650b52  e8a9340100           call 0x664000
// 00650b57  68e0329800           push 0x9832e0
// 00650b5c  e8c83d1a00           call 0x7f4929
// 00650b61  83c404               add esp, 4
// 00650b64  8b0c24               mov ecx, dword ptr [esp]
// 00650b67  b8a0a9b800           mov eax, 0xb8a9a0
// 00650b6c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650b73  83c40c               add esp, 0xc
// 00650b76  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "LocalBackpack", 0);
    return object;
}
