// from server: 100% by nuck16
// roc 2009-12 0064ece0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064ece0  64a100000000         mov eax, dword ptr fs:[0]
// 0064ece6  6aff                 push -1
// 0064ece8  687e1e9400           push 0x941e7e
// 0064eced  50                   push eax
// 0064ecee  b801000000           mov eax, 1
// 0064ecf3  64892500000000       mov dword ptr fs:[0], esp
// 0064ecfa  84059865b800         test byte ptr [0xb86598], al
// 0064ed00  7532                 jne 0x64ed34
// 0064ed02  09059865b800         or dword ptr [0xb86598], eax
// 0064ed08  6a00                 push 0
// 0064ed0a  6810789e00           push 0x9e7810
// 0064ed0f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064ed17  e894b6dbff           call 0x40a3b0
// 0064ed1c  50                   push eax
// 0064ed1d  b9a064b800           mov ecx, 0xb864a0
// 0064ed22  e8d9520100           call 0x664000
// 0064ed27  6830379800           push 0x983730
// 0064ed2c  e8f85b1a00           call 0x7f4929
// 0064ed31  83c404               add esp, 4
// 0064ed34  8b0c24               mov ecx, dword ptr [esp]
// 0064ed37  b8a064b800           mov eax, 0xb864a0
// 0064ed3c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ed43  83c40c               add esp, 0xc
// 0064ed46  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "PVInstance", 0);
    return object;
}
