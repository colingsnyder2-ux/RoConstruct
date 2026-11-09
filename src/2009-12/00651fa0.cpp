// from server: 100% by nuck16
// roc 2009-12 00651fa0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651fa0  64a100000000         mov eax, dword ptr fs:[0]
// 00651fa6  6aff                 push -1
// 00651fa8  68fe2c9400           push 0x942cfe
// 00651fad  50                   push eax
// 00651fae  b801000000           mov eax, 1
// 00651fb3  64892500000000       mov dword ptr fs:[0], esp
// 00651fba  840598d9b800         test byte ptr [0xb8d998], al
// 00651fc0  7532                 jne 0x651ff4
// 00651fc2  090598d9b800         or dword ptr [0xb8d998], eax
// 00651fc8  6a00                 push 0
// 00651fca  6864f4b400           push 0xb4f464
// 00651fcf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651fd7  e8d483dbff           call 0x40a3b0
// 00651fdc  50                   push eax
// 00651fdd  b9a0d8b800           mov ecx, 0xb8d8a0
// 00651fe2  e819200100           call 0x664000
// 00651fe7  68f02f9800           push 0x982ff0
// 00651fec  e838291a00           call 0x7f4929
// 00651ff1  83c404               add esp, 4
// 00651ff4  8b0c24               mov ecx, dword ptr [esp]
// 00651ff7  b8a0d8b800           mov eax, 0xb8d8a0
// 00651ffc  64890d00000000       mov dword ptr fs:[0], ecx
// 00652003  83c40c               add esp, 0xc
// 00652006  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4f464[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4f464, 0);
    return object;
}
