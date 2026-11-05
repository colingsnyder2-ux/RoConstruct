// from server: 100% by nuck16
// roc 2009-12 006520f0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006520f0  64a100000000         mov eax, dword ptr fs:[0]
// 006520f6  6aff                 push -1
// 006520f8  685e2d9400           push 0x942d5e
// 006520fd  50                   push eax
// 006520fe  b801000000           mov eax, 1
// 00652103  64892500000000       mov dword ptr fs:[0], esp
// 0065210a  840598dcb800         test byte ptr [0xb8dc98], al
// 00652110  7532                 jne 0x652144
// 00652112  090598dcb800         or dword ptr [0xb8dc98], eax
// 00652118  6a00                 push 0
// 0065211a  687cf4b400           push 0xb4f47c
// 0065211f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00652127  e88482dbff           call 0x40a3b0
// 0065212c  50                   push eax
// 0065212d  b9a0dbb800           mov ecx, 0xb8dba0
// 00652132  e8c91e0100           call 0x664000
// 00652137  68c02f9800           push 0x982fc0
// 0065213c  e8e8271a00           call 0x7f4929
// 00652141  83c404               add esp, 4
// 00652144  8b0c24               mov ecx, dword ptr [esp]
// 00652147  b8a0dbb800           mov eax, 0xb8dba0
// 0065214c  64890d00000000       mov dword ptr fs:[0], ecx
// 00652153  83c40c               add esp, 0xc
// 00652156  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4f47c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4f47c, 0);
    return object;
}
