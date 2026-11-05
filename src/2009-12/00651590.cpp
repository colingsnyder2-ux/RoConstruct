// from server: 100% by nuck16
// roc 2009-12 00651590  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651590  64a100000000         mov eax, dword ptr fs:[0]
// 00651596  6aff                 push -1
// 00651598  681e2a9400           push 0x942a1e
// 0065159d  50                   push eax
// 0065159e  b801000000           mov eax, 1
// 006515a3  64892500000000       mov dword ptr fs:[0], esp
// 006515aa  840598c2b800         test byte ptr [0xb8c298], al
// 006515b0  7532                 jne 0x6515e4
// 006515b2  090598c2b800         or dword ptr [0xb8c298], eax
// 006515b8  6a00                 push 0
// 006515ba  6884e8b300           push 0xb3e884
// 006515bf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006515c7  e8e48ddbff           call 0x40a3b0
// 006515cc  50                   push eax
// 006515cd  b9a0c1b800           mov ecx, 0xb8c1a0
// 006515d2  e8292a0100           call 0x664000
// 006515d7  6860319800           push 0x983160
// 006515dc  e848331a00           call 0x7f4929
// 006515e1  83c404               add esp, 4
// 006515e4  8b0c24               mov ecx, dword ptr [esp]
// 006515e7  b8a0c1b800           mov eax, 0xb8c1a0
// 006515ec  64890d00000000       mov dword ptr fs:[0], ecx
// 006515f3  83c40c               add esp, 0xc
// 006515f6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b3e884[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b3e884, 0);
    return object;
}
