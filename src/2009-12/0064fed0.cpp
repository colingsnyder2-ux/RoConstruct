// from server: 100% by nuck16
// roc 2009-12 0064fed0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064fed0  64a100000000         mov eax, dword ptr fs:[0]
// 0064fed6  6aff                 push -1
// 0064fed8  689e239400           push 0x94239e
// 0064fedd  50                   push eax
// 0064fede  b801000000           mov eax, 1
// 0064fee3  64892500000000       mov dword ptr fs:[0], esp
// 0064feea  8405988eb800         test byte ptr [0xb88e98], al
// 0064fef0  7532                 jne 0x64ff24
// 0064fef2  0905988eb800         or dword ptr [0xb88e98], eax
// 0064fef8  6a00                 push 0
// 0064fefa  6828e89d00           push 0x9de828
// 0064feff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064ff07  e854ffffff           call 0x64fe60
// 0064ff0c  50                   push eax
// 0064ff0d  b9a08db800           mov ecx, 0xb88da0
// 0064ff12  e8e9400100           call 0x664000
// 0064ff17  68a0349800           push 0x9834a0
// 0064ff1c  e8084a1a00           call 0x7f4929
// 0064ff21  83c404               add esp, 4
// 0064ff24  8b0c24               mov ecx, dword ptr [esp]
// 0064ff27  b8a08db800           mov eax, 0xb88da0
// 0064ff2c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ff33  83c40c               add esp, 0xc
// 0064ff36  c3                   ret 

struct Base;
Base &get_64fe60();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64fe60(), "RotateP", 0);
    return object;
}
