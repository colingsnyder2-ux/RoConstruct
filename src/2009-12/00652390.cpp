// from server: 100% by nuck16
// roc 2009-12 00652390  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00652390  64a100000000         mov eax, dword ptr fs:[0]
// 00652396  6aff                 push -1
// 00652398  681e2e9400           push 0x942e1e
// 0065239d  50                   push eax
// 0065239e  b801000000           mov eax, 1
// 006523a3  64892500000000       mov dword ptr fs:[0], esp
// 006523aa  840598e2b800         test byte ptr [0xb8e298], al
// 006523b0  7532                 jne 0x6523e4
// 006523b2  090598e2b800         or dword ptr [0xb8e298], eax
// 006523b8  6a00                 push 0
// 006523ba  68d4f4b400           push 0xb4f4d4
// 006523bf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006523c7  e8e47fdbff           call 0x40a3b0
// 006523cc  50                   push eax
// 006523cd  b9a0e1b800           mov ecx, 0xb8e1a0
// 006523d2  e8291c0100           call 0x664000
// 006523d7  68602f9800           push 0x982f60
// 006523dc  e848251a00           call 0x7f4929
// 006523e1  83c404               add esp, 4
// 006523e4  8b0c24               mov ecx, dword ptr [esp]
// 006523e7  b8a0e1b800           mov eax, 0xb8e1a0
// 006523ec  64890d00000000       mov dword ptr fs:[0], ecx
// 006523f3  83c40c               add esp, 0xc
// 006523f6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4f4d4[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4f4d4, 0);
    return object;
}
