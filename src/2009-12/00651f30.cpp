// from server: 100% by nuck16
// roc 2009-12 00651f30  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651f30  64a100000000         mov eax, dword ptr fs:[0]
// 00651f36  6aff                 push -1
// 00651f38  68de2c9400           push 0x942cde
// 00651f3d  50                   push eax
// 00651f3e  b801000000           mov eax, 1
// 00651f43  64892500000000       mov dword ptr fs:[0], esp
// 00651f4a  840598d8b800         test byte ptr [0xb8d898], al
// 00651f50  7532                 jne 0x651f84
// 00651f52  090598d8b800         or dword ptr [0xb8d898], eax
// 00651f58  6a00                 push 0
// 00651f5a  684cf4b400           push 0xb4f44c
// 00651f5f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651f67  e84484dbff           call 0x40a3b0
// 00651f6c  50                   push eax
// 00651f6d  b9a0d7b800           mov ecx, 0xb8d7a0
// 00651f72  e889200100           call 0x664000
// 00651f77  6800309800           push 0x983000
// 00651f7c  e8a8291a00           call 0x7f4929
// 00651f81  83c404               add esp, 4
// 00651f84  8b0c24               mov ecx, dword ptr [esp]
// 00651f87  b8a0d7b800           mov eax, 0xb8d7a0
// 00651f8c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651f93  83c40c               add esp, 0xc
// 00651f96  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4f44c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4f44c, 0);
    return object;
}
