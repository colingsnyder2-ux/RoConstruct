// from server: 100% by nuck16
// roc 2009-12 006514b0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006514b0  64a100000000         mov eax, dword ptr fs:[0]
// 006514b6  6aff                 push -1
// 006514b8  68de299400           push 0x9429de
// 006514bd  50                   push eax
// 006514be  b801000000           mov eax, 1
// 006514c3  64892500000000       mov dword ptr fs:[0], esp
// 006514ca  840598c0b800         test byte ptr [0xb8c098], al
// 006514d0  7532                 jne 0x651504
// 006514d2  090598c0b800         or dword ptr [0xb8c098], eax
// 006514d8  6a00                 push 0
// 006514da  68ecf4b400           push 0xb4f4ec
// 006514df  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006514e7  e8c48edbff           call 0x40a3b0
// 006514ec  50                   push eax
// 006514ed  b9a0bfb800           mov ecx, 0xb8bfa0
// 006514f2  e8092b0100           call 0x664000
// 006514f7  6880319800           push 0x983180
// 006514fc  e828341a00           call 0x7f4929
// 00651501  83c404               add esp, 4
// 00651504  8b0c24               mov ecx, dword ptr [esp]
// 00651507  b8a0bfb800           mov eax, 0xb8bfa0
// 0065150c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651513  83c40c               add esp, 0xc
// 00651516  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4f4ec[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4f4ec, 0);
    return object;
}
