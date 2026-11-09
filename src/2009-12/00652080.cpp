// from server: 100% by nuck16
// roc 2009-12 00652080  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00652080  64a100000000         mov eax, dword ptr fs:[0]
// 00652086  6aff                 push -1
// 00652088  683e2d9400           push 0x942d3e
// 0065208d  50                   push eax
// 0065208e  b801000000           mov eax, 1
// 00652093  64892500000000       mov dword ptr fs:[0], esp
// 0065209a  840598dbb800         test byte ptr [0xb8db98], al
// 006520a0  7532                 jne 0x6520d4
// 006520a2  090598dbb800         or dword ptr [0xb8db98], eax
// 006520a8  6a00                 push 0
// 006520aa  6870f4b400           push 0xb4f470
// 006520af  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006520b7  e8f482dbff           call 0x40a3b0
// 006520bc  50                   push eax
// 006520bd  b9a0dab800           mov ecx, 0xb8daa0
// 006520c2  e8391f0100           call 0x664000
// 006520c7  68d02f9800           push 0x982fd0
// 006520cc  e858281a00           call 0x7f4929
// 006520d1  83c404               add esp, 4
// 006520d4  8b0c24               mov ecx, dword ptr [esp]
// 006520d7  b8a0dab800           mov eax, 0xb8daa0
// 006520dc  64890d00000000       mov dword ptr fs:[0], ecx
// 006520e3  83c40c               add esp, 0xc
// 006520e6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4f470[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4f470, 0);
    return object;
}
