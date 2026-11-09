// from server: 100% by nuck16
// roc 2009-12 00650790  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650790  64a100000000         mov eax, dword ptr fs:[0]
// 00650796  6aff                 push -1
// 00650798  681e269400           push 0x94261e
// 0065079d  50                   push eax
// 0065079e  b801000000           mov eax, 1
// 006507a3  64892500000000       mov dword ptr fs:[0], esp
// 006507aa  840598a2b800         test byte ptr [0xb8a298], al
// 006507b0  7532                 jne 0x6507e4
// 006507b2  090598a2b800         or dword ptr [0xb8a298], eax
// 006507b8  6a00                 push 0
// 006507ba  683c1fb500           push 0xb51f3c
// 006507bf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006507c7  e8e49bdbff           call 0x40a3b0
// 006507cc  50                   push eax
// 006507cd  b9a0a1b800           mov ecx, 0xb8a1a0
// 006507d2  e829380100           call 0x664000
// 006507d7  6860339800           push 0x983360
// 006507dc  e848411a00           call 0x7f4929
// 006507e1  83c404               add esp, 4
// 006507e4  8b0c24               mov ecx, dword ptr [esp]
// 006507e7  b8a0a1b800           mov eax, 0xb8a1a0
// 006507ec  64890d00000000       mov dword ptr fs:[0], ecx
// 006507f3  83c40c               add esp, 0xc
// 006507f6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b51f3c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b51f3c, 0);
    return object;
}
