// from server: 100% by nuck16
// roc 2009-12 00651910  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651910  64a100000000         mov eax, dword ptr fs:[0]
// 00651916  6aff                 push -1
// 00651918  681e2b9400           push 0x942b1e
// 0065191d  50                   push eax
// 0065191e  b801000000           mov eax, 1
// 00651923  64892500000000       mov dword ptr fs:[0], esp
// 0065192a  840598cab800         test byte ptr [0xb8ca98], al
// 00651930  7532                 jne 0x651964
// 00651932  090598cab800         or dword ptr [0xb8ca98], eax
// 00651938  6a00                 push 0
// 0065193a  68c8fdb500           push 0xb5fdc8
// 0065193f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651947  e8e4feffff           call 0x651830
// 0065194c  50                   push eax
// 0065194d  b9a0c9b800           mov ecx, 0xb8c9a0
// 00651952  e8a9260100           call 0x664000
// 00651957  68e0309800           push 0x9830e0
// 0065195c  e8c82f1a00           call 0x7f4929
// 00651961  83c404               add esp, 4
// 00651964  8b0c24               mov ecx, dword ptr [esp]
// 00651967  b8a0c9b800           mov eax, 0xb8c9a0
// 0065196c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651973  83c40c               add esp, 0xc
// 00651976  c3                   ret 

struct Base;
Base &get_651830();
extern char string_00b5fdc8[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_651830(), string_00b5fdc8, 0);
    return object;
}
