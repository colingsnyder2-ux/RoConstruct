// from server: 100% by nuck16
// roc 2009-12 00650cd0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650cd0  64a100000000         mov eax, dword ptr fs:[0]
// 00650cd6  6aff                 push -1
// 00650cd8  689e279400           push 0x94279e
// 00650cdd  50                   push eax
// 00650cde  b801000000           mov eax, 1
// 00650ce3  64892500000000       mov dword ptr fs:[0], esp
// 00650cea  840598aeb800         test byte ptr [0xb8ae98], al
// 00650cf0  7532                 jne 0x650d24
// 00650cf2  090598aeb800         or dword ptr [0xb8ae98], eax
// 00650cf8  6a00                 push 0
// 00650cfa  6800f69d00           push 0x9df600
// 00650cff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650d07  e8a496dbff           call 0x40a3b0
// 00650d0c  50                   push eax
// 00650d0d  b9a0adb800           mov ecx, 0xb8ada0
// 00650d12  e8e9320100           call 0x664000
// 00650d17  68a0329800           push 0x9832a0
// 00650d1c  e8083c1a00           call 0x7f4929
// 00650d21  83c404               add esp, 4
// 00650d24  8b0c24               mov ecx, dword ptr [esp]
// 00650d27  b8a0adb800           mov eax, 0xb8ada0
// 00650d2c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650d33  83c40c               add esp, 0xc
// 00650d36  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "PhysicsService", 0);
    return object;
}
