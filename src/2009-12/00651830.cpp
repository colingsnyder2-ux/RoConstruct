// from server: 100% by nuck16
// roc 2009-12 00651830  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651830  64a100000000         mov eax, dword ptr fs:[0]
// 00651836  6aff                 push -1
// 00651838  68de2a9400           push 0x942ade
// 0065183d  50                   push eax
// 0065183e  b801000000           mov eax, 1
// 00651843  64892500000000       mov dword ptr fs:[0], esp
// 0065184a  840598c8b800         test byte ptr [0xb8c898], al
// 00651850  7532                 jne 0x651884
// 00651852  090598c8b800         or dword ptr [0xb8c898], eax
// 00651858  6a00                 push 0
// 0065185a  68b0fdb500           push 0xb5fdb0
// 0065185f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651867  e804d4ffff           call 0x64ec70
// 0065186c  50                   push eax
// 0065186d  b9a0c7b800           mov ecx, 0xb8c7a0
// 00651872  e889270100           call 0x664000
// 00651877  6800319800           push 0x983100
// 0065187c  e8a8301a00           call 0x7f4929
// 00651881  83c404               add esp, 4
// 00651884  8b0c24               mov ecx, dword ptr [esp]
// 00651887  b8a0c7b800           mov eax, 0xb8c7a0
// 0065188c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651893  83c40c               add esp, 0xc
// 00651896  c3                   ret 

struct Base;
Base &get_64ec70();
extern char string_00b5fdb0[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64ec70(), string_00b5fdb0, 0);
    return object;
}
