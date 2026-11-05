// from server: 100% by nuck16
// roc 2009-12 006522b0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006522b0
//
// 006522b0  64a100000000         mov eax, dword ptr fs:[0]
// 006522b6  6aff                 push -1
// 006522b8  68de2d9400           push 0x942dde
// 006522bd  50                   push eax
// 006522be  b801000000           mov eax, 1
// 006522c3  64892500000000       mov dword ptr fs:[0], esp
// 006522ca  840598e0b800         test byte ptr [0xb8e098], al
// 006522d0  7532                 jne 0x652304
// 006522d2  090598e0b800         or dword ptr [0xb8e098], eax
// 006522d8  6a00                 push 0
// 006522da  68b0f4b400           push 0xb4f4b0
// 006522df  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006522e7  e8c480dbff           call 0x40a3b0
// 006522ec  50                   push eax
// 006522ed  b9a0dfb800           mov ecx, 0xb8dfa0
// 006522f2  e8091d0100           call 0x664000
// 006522f7  68802f9800           push 0x982f80
// 006522fc  e828261a00           call 0x7f4929
// 00652301  83c404               add esp, 4
// 00652304  8b0c24               mov ecx, dword ptr [esp]
// 00652307  b8a0dfb800           mov eax, 0xb8dfa0
// 0065230c  64890d00000000       mov dword ptr fs:[0], ecx
// 00652313  83c40c               add esp, 0xc
// 00652316  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4f4b0[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4f4b0, 0);
    return object;
}
