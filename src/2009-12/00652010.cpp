// from server: 100% by nuck16
// roc 2009-12 00652010  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00652010  64a100000000         mov eax, dword ptr fs:[0]
// 00652016  6aff                 push -1
// 00652018  681e2d9400           push 0x942d1e
// 0065201d  50                   push eax
// 0065201e  b801000000           mov eax, 1
// 00652023  64892500000000       mov dword ptr fs:[0], esp
// 0065202a  840598dab800         test byte ptr [0xb8da98], al
// 00652030  7532                 jne 0x652064
// 00652032  090598dab800         or dword ptr [0xb8da98], eax
// 00652038  6a00                 push 0
// 0065203a  6858f4b400           push 0xb4f458
// 0065203f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00652047  e86483dbff           call 0x40a3b0
// 0065204c  50                   push eax
// 0065204d  b9a0d9b800           mov ecx, 0xb8d9a0
// 00652052  e8a91f0100           call 0x664000
// 00652057  68e02f9800           push 0x982fe0
// 0065205c  e8c8281a00           call 0x7f4929
// 00652061  83c404               add esp, 4
// 00652064  8b0c24               mov ecx, dword ptr [esp]
// 00652067  b8a0d9b800           mov eax, 0xb8d9a0
// 0065206c  64890d00000000       mov dword ptr fs:[0], ecx
// 00652073  83c40c               add esp, 0xc
// 00652076  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4f458[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4f458, 0);
    return object;
}
