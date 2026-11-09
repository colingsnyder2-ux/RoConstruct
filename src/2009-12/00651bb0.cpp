// from server: 100% by nuck16
// roc 2009-12 00651bb0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651bb0  64a100000000         mov eax, dword ptr fs:[0]
// 00651bb6  6aff                 push -1
// 00651bb8  68de2b9400           push 0x942bde
// 00651bbd  50                   push eax
// 00651bbe  b801000000           mov eax, 1
// 00651bc3  64892500000000       mov dword ptr fs:[0], esp
// 00651bca  840598d0b800         test byte ptr [0xb8d098], al
// 00651bd0  7532                 jne 0x651c04
// 00651bd2  090598d0b800         or dword ptr [0xb8d098], eax
// 00651bd8  6a00                 push 0
// 00651bda  68ccb3b500           push 0xb5b3cc
// 00651bdf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651be7  e8b4fcffff           call 0x6518a0
// 00651bec  50                   push eax
// 00651bed  b9a0cfb800           mov ecx, 0xb8cfa0
// 00651bf2  e809240100           call 0x664000
// 00651bf7  6880309800           push 0x983080
// 00651bfc  e8282d1a00           call 0x7f4929
// 00651c01  83c404               add esp, 4
// 00651c04  8b0c24               mov ecx, dword ptr [esp]
// 00651c07  b8a0cfb800           mov eax, 0xb8cfa0
// 00651c0c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651c13  83c40c               add esp, 0xc
// 00651c16  c3                   ret 

struct Base;
Base &get_6518a0();
extern char string_00b5b3cc[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_6518a0(), string_00b5b3cc, 0);
    return object;
}
