// from server: 100% by nuck16
// roc 2009-12 00651c90  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651c90  64a100000000         mov eax, dword ptr fs:[0]
// 00651c96  6aff                 push -1
// 00651c98  681e2c9400           push 0x942c1e
// 00651c9d  50                   push eax
// 00651c9e  b801000000           mov eax, 1
// 00651ca3  64892500000000       mov dword ptr fs:[0], esp
// 00651caa  840598d2b800         test byte ptr [0xb8d298], al
// 00651cb0  7532                 jne 0x651ce4
// 00651cb2  090598d2b800         or dword ptr [0xb8d298], eax
// 00651cb8  6a00                 push 0
// 00651cba  6884c6b500           push 0xb5c684
// 00651cbf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651cc7  e864fbffff           call 0x651830
// 00651ccc  50                   push eax
// 00651ccd  b9a0d1b800           mov ecx, 0xb8d1a0
// 00651cd2  e829230100           call 0x664000
// 00651cd7  6860309800           push 0x983060
// 00651cdc  e8482c1a00           call 0x7f4929
// 00651ce1  83c404               add esp, 4
// 00651ce4  8b0c24               mov ecx, dword ptr [esp]
// 00651ce7  b8a0d1b800           mov eax, 0xb8d1a0
// 00651cec  64890d00000000       mov dword ptr fs:[0], ecx
// 00651cf3  83c40c               add esp, 0xc
// 00651cf6  c3                   ret 

struct Base;
Base &get_651830();
extern char string_00b5c684[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_651830(), string_00b5c684, 0);
    return object;
}
