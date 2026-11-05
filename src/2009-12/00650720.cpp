// from server: 100% by nuck16
// roc 2009-12 00650720  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650720  64a100000000         mov eax, dword ptr fs:[0]
// 00650726  6aff                 push -1
// 00650728  68fe259400           push 0x9425fe
// 0065072d  50                   push eax
// 0065072e  b801000000           mov eax, 1
// 00650733  64892500000000       mov dword ptr fs:[0], esp
// 0065073a  840598a1b800         test byte ptr [0xb8a198], al
// 00650740  7532                 jne 0x650774
// 00650742  090598a1b800         or dword ptr [0xb8a198], eax
// 00650748  6a00                 push 0
// 0065074a  68201fb500           push 0xb51f20
// 0065074f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650757  e8549cdbff           call 0x40a3b0
// 0065075c  50                   push eax
// 0065075d  b9a0a0b800           mov ecx, 0xb8a0a0
// 00650762  e899380100           call 0x664000
// 00650767  6870339800           push 0x983370
// 0065076c  e8b8411a00           call 0x7f4929
// 00650771  83c404               add esp, 4
// 00650774  8b0c24               mov ecx, dword ptr [esp]
// 00650777  b8a0a0b800           mov eax, 0xb8a0a0
// 0065077c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650783  83c40c               add esp, 0xc
// 00650786  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b51f20[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b51f20, 0);
    return object;
}
