// from server: 100% by nuck16
// roc 2009-12 00650e20  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650e20  64a100000000         mov eax, dword ptr fs:[0]
// 00650e26  6aff                 push -1
// 00650e28  68fe279400           push 0x9427fe
// 00650e2d  50                   push eax
// 00650e2e  b801000000           mov eax, 1
// 00650e33  64892500000000       mov dword ptr fs:[0], esp
// 00650e3a  840598b1b800         test byte ptr [0xb8b198], al
// 00650e40  7532                 jne 0x650e74
// 00650e42  090598b1b800         or dword ptr [0xb8b198], eax
// 00650e48  6a00                 push 0
// 00650e4a  68fc94b500           push 0xb594fc
// 00650e4f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650e57  e8a4e4ffff           call 0x64f300
// 00650e5c  50                   push eax
// 00650e5d  b9a0b0b800           mov ecx, 0xb8b0a0
// 00650e62  e899310100           call 0x664000
// 00650e67  6870329800           push 0x983270
// 00650e6c  e8b83a1a00           call 0x7f4929
// 00650e71  83c404               add esp, 4
// 00650e74  8b0c24               mov ecx, dword ptr [esp]
// 00650e77  b8a0b0b800           mov eax, 0xb8b0a0
// 00650e7c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650e83  83c40c               add esp, 0xc
// 00650e86  c3                   ret 

struct Base;
Base &get_64f300();
extern char string_00b594fc[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64f300(), string_00b594fc, 0);
    return object;
}
