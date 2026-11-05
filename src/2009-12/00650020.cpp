// from server: 100% by nuck16
// roc 2009-12 00650020  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650020  64a100000000         mov eax, dword ptr fs:[0]
// 00650026  6aff                 push -1
// 00650028  68fe239400           push 0x9423fe
// 0065002d  50                   push eax
// 0065002e  b801000000           mov eax, 1
// 00650033  64892500000000       mov dword ptr fs:[0], esp
// 0065003a  84059891b800         test byte ptr [0xb89198], al
// 00650040  7532                 jne 0x650074
// 00650042  09059891b800         or dword ptr [0xb89198], eax
// 00650048  6a00                 push 0
// 0065004a  68e0299e00           push 0x9e29e0
// 0065004f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650057  e854a3dbff           call 0x40a3b0
// 0065005c  50                   push eax
// 0065005d  b9a090b800           mov ecx, 0xb890a0
// 00650062  e8993f0100           call 0x664000
// 00650067  6870349800           push 0x983470
// 0065006c  e8b8481a00           call 0x7f4929
// 00650071  83c404               add esp, 4
// 00650074  8b0c24               mov ecx, dword ptr [esp]
// 00650077  b8a090b800           mov eax, 0xb890a0
// 0065007c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650083  83c40c               add esp, 0xc
// 00650086  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "Feature", 0);
    return object;
}
