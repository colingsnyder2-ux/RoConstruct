// from server: 100% by nuck16
// roc 2009-12 00651130  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651130  64a100000000         mov eax, dword ptr fs:[0]
// 00651136  6aff                 push -1
// 00651138  68de289400           push 0x9428de
// 0065113d  50                   push eax
// 0065113e  b801000000           mov eax, 1
// 00651143  64892500000000       mov dword ptr fs:[0], esp
// 0065114a  840598b8b800         test byte ptr [0xb8b898], al
// 00651150  7532                 jne 0x651184
// 00651152  090598b8b800         or dword ptr [0xb8b898], eax
// 00651158  6a00                 push 0
// 0065115a  681822b400           push 0xb42218
// 0065115f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651167  e874f0ffff           call 0x6501e0
// 0065116c  50                   push eax
// 0065116d  b9a0b7b800           mov ecx, 0xb8b7a0
// 00651172  e8892e0100           call 0x664000
// 00651177  6800329800           push 0x983200
// 0065117c  e8a8371a00           call 0x7f4929
// 00651181  83c404               add esp, 4
// 00651184  8b0c24               mov ecx, dword ptr [esp]
// 00651187  b8a0b7b800           mov eax, 0xb8b7a0
// 0065118c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651193  83c40c               add esp, 0xc
// 00651196  c3                   ret 

struct Base;
Base &get_6501e0();
extern char string_00b42218[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_6501e0(), string_00b42218, 0);
    return object;
}
