// from server: 100% by nuck16
// roc 2009-12 00650a30  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650a30  64a100000000         mov eax, dword ptr fs:[0]
// 00650a36  6aff                 push -1
// 00650a38  68de269400           push 0x9426de
// 00650a3d  50                   push eax
// 00650a3e  b801000000           mov eax, 1
// 00650a43  64892500000000       mov dword ptr fs:[0], esp
// 00650a4a  840598a8b800         test byte ptr [0xb8a898], al
// 00650a50  7532                 jne 0x650a84
// 00650a52  090598a8b800         or dword ptr [0xb8a898], eax
// 00650a58  6a00                 push 0
// 00650a5a  68c0419e00           push 0x9e41c0
// 00650a5f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650a67  e84499dbff           call 0x40a3b0
// 00650a6c  50                   push eax
// 00650a6d  b9a0a7b800           mov ecx, 0xb8a7a0
// 00650a72  e889350100           call 0x664000
// 00650a77  6800339800           push 0x983300
// 00650a7c  e8a83e1a00           call 0x7f4929
// 00650a81  83c404               add esp, 4
// 00650a84  8b0c24               mov ecx, dword ptr [esp]
// 00650a87  b8a0a7b800           mov eax, 0xb8a7a0
// 00650a8c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650a93  83c40c               add esp, 0xc
// 00650a96  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "LocalBackpackTool", 0);
    return object;
}
