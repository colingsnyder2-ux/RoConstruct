// from server: 100% by nuck16
// roc 2009-12 00650100  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650100  64a100000000         mov eax, dword ptr fs:[0]
// 00650106  6aff                 push -1
// 00650108  683e249400           push 0x94243e
// 0065010d  50                   push eax
// 0065010e  b801000000           mov eax, 1
// 00650113  64892500000000       mov dword ptr fs:[0], esp
// 0065011a  84059893b800         test byte ptr [0xb89398], al
// 00650120  7532                 jne 0x650154
// 00650122  09059893b800         or dword ptr [0xb89398], eax
// 00650128  6a00                 push 0
// 0065012a  68e8299e00           push 0x9e29e8
// 0065012f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650137  e8e4feffff           call 0x650020
// 0065013c  50                   push eax
// 0065013d  b9a092b800           mov ecx, 0xb892a0
// 00650142  e8b93e0100           call 0x664000
// 00650147  6850349800           push 0x983450
// 0065014c  e8d8471a00           call 0x7f4929
// 00650151  83c404               add esp, 4
// 00650154  8b0c24               mov ecx, dword ptr [esp]
// 00650157  b8a092b800           mov eax, 0xb892a0
// 0065015c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650163  83c40c               add esp, 0xc
// 00650166  c3                   ret 

struct Base;
Base &get_650020();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_650020(), "Hole", 0);
    return object;
}
