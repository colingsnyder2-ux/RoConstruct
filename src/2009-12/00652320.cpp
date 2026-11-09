// from server: 100% by nuck16
// roc 2009-12 00652320  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00652320  64a100000000         mov eax, dword ptr fs:[0]
// 00652326  6aff                 push -1
// 00652328  68fe2d9400           push 0x942dfe
// 0065232d  50                   push eax
// 0065232e  b801000000           mov eax, 1
// 00652333  64892500000000       mov dword ptr fs:[0], esp
// 0065233a  840598e1b800         test byte ptr [0xb8e198], al
// 00652340  7532                 jne 0x652374
// 00652342  090598e1b800         or dword ptr [0xb8e198], eax
// 00652348  6a00                 push 0
// 0065234a  68c0f4b400           push 0xb4f4c0
// 0065234f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00652357  e85480dbff           call 0x40a3b0
// 0065235c  50                   push eax
// 0065235d  b9a0e0b800           mov ecx, 0xb8e0a0
// 00652362  e8991c0100           call 0x664000
// 00652367  68702f9800           push 0x982f70
// 0065236c  e8b8251a00           call 0x7f4929
// 00652371  83c404               add esp, 4
// 00652374  8b0c24               mov ecx, dword ptr [esp]
// 00652377  b8a0e0b800           mov eax, 0xb8e0a0
// 0065237c  64890d00000000       mov dword ptr fs:[0], ecx
// 00652383  83c40c               add esp, 0xc
// 00652386  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4f4c0[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4f4c0, 0);
    return object;
}
