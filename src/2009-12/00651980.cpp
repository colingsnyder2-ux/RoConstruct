// from server: 100% by nuck16
// roc 2009-12 00651980  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651980  64a100000000         mov eax, dword ptr fs:[0]
// 00651986  6aff                 push -1
// 00651988  683e2b9400           push 0x942b3e
// 0065198d  50                   push eax
// 0065198e  b801000000           mov eax, 1
// 00651993  64892500000000       mov dword ptr fs:[0], esp
// 0065199a  840598cbb800         test byte ptr [0xb8cb98], al
// 006519a0  7532                 jne 0x6519d4
// 006519a2  090598cbb800         or dword ptr [0xb8cb98], eax
// 006519a8  6a00                 push 0
// 006519aa  68e4a3b500           push 0xb5a3e4
// 006519af  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006519b7  e8b4d2ffff           call 0x64ec70
// 006519bc  50                   push eax
// 006519bd  b9a0cab800           mov ecx, 0xb8caa0
// 006519c2  e839260100           call 0x664000
// 006519c7  68d0309800           push 0x9830d0
// 006519cc  e8582f1a00           call 0x7f4929
// 006519d1  83c404               add esp, 4
// 006519d4  8b0c24               mov ecx, dword ptr [esp]
// 006519d7  b8a0cab800           mov eax, 0xb8caa0
// 006519dc  64890d00000000       mov dword ptr fs:[0], ecx
// 006519e3  83c40c               add esp, 0xc
// 006519e6  c3                   ret 

struct Base;
Base &get_64ec70();
extern char string_00b5a3e4[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64ec70(), string_00b5a3e4, 0);
    return object;
}
