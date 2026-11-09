// from server: 100% by nuck16
// roc 2009-12 0064fae0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064fae0  64a100000000         mov eax, dword ptr fs:[0]
// 0064fae6  6aff                 push -1
// 0064fae8  687e229400           push 0x94227e
// 0064faed  50                   push eax
// 0064faee  b801000000           mov eax, 1
// 0064faf3  64892500000000       mov dword ptr fs:[0], esp
// 0064fafa  84059885b800         test byte ptr [0xb88598], al
// 0064fb00  7532                 jne 0x64fb34
// 0064fb02  09059885b800         or dword ptr [0xb88598], eax
// 0064fb08  6a00                 push 0
// 0064fb0a  68e86e9d00           push 0x9d6ee8
// 0064fb0f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064fb17  e894a8dbff           call 0x40a3b0
// 0064fb1c  50                   push eax
// 0064fb1d  b9a084b800           mov ecx, 0xb884a0
// 0064fb22  e8d9440100           call 0x664000
// 0064fb27  6830359800           push 0x983530
// 0064fb2c  e8f84d1a00           call 0x7f4929
// 0064fb31  83c404               add esp, 4
// 0064fb34  8b0c24               mov ecx, dword ptr [esp]
// 0064fb37  b8a084b800           mov eax, 0xb884a0
// 0064fb3c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064fb43  83c40c               add esp, 0xc
// 0064fb46  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "PhysicsSettings", 0);
    return object;
}
