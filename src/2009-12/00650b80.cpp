// from server: 100% by nuck16
// roc 2009-12 00650b80  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650b80  64a100000000         mov eax, dword ptr fs:[0]
// 00650b86  6aff                 push -1
// 00650b88  683e279400           push 0x94273e
// 00650b8d  50                   push eax
// 00650b8e  b801000000           mov eax, 1
// 00650b93  64892500000000       mov dword ptr fs:[0], esp
// 00650b9a  840598abb800         test byte ptr [0xb8ab98], al
// 00650ba0  7532                 jne 0x650bd4
// 00650ba2  090598abb800         or dword ptr [0xb8ab98], eax
// 00650ba8  6a00                 push 0
// 00650baa  6860ecb500           push 0xb5ec60
// 00650baf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650bb7  e8f497dbff           call 0x40a3b0
// 00650bbc  50                   push eax
// 00650bbd  b9a0aab800           mov ecx, 0xb8aaa0
// 00650bc2  e839340100           call 0x664000
// 00650bc7  68d0329800           push 0x9832d0
// 00650bcc  e8583d1a00           call 0x7f4929
// 00650bd1  83c404               add esp, 4
// 00650bd4  8b0c24               mov ecx, dword ptr [esp]
// 00650bd7  b8a0aab800           mov eax, 0xb8aaa0
// 00650bdc  64890d00000000       mov dword ptr fs:[0], ecx
// 00650be3  83c40c               add esp, 0xc
// 00650be6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b5ec60[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b5ec60, 0);
    return object;
}
