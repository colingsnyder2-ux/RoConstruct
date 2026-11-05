// from server: 100% by nuck16
// roc 2009-12 00650fe0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650fe0  64a100000000         mov eax, dword ptr fs:[0]
// 00650fe6  6aff                 push -1
// 00650fe8  687e289400           push 0x94287e
// 00650fed  50                   push eax
// 00650fee  b801000000           mov eax, 1
// 00650ff3  64892500000000       mov dword ptr fs:[0], esp
// 00650ffa  840598b5b800         test byte ptr [0xb8b598], al
// 00651000  7532                 jne 0x651034
// 00651002  090598b5b800         or dword ptr [0xb8b598], eax
// 00651008  6a00                 push 0
// 0065100a  687846b400           push 0xb44678
// 0065100f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651017  e89493dbff           call 0x40a3b0
// 0065101c  50                   push eax
// 0065101d  b9a0b4b800           mov ecx, 0xb8b4a0
// 00651022  e8d92f0100           call 0x664000
// 00651027  6830329800           push 0x983230
// 0065102c  e8f8381a00           call 0x7f4929
// 00651031  83c404               add esp, 4
// 00651034  8b0c24               mov ecx, dword ptr [esp]
// 00651037  b8a0b4b800           mov eax, 0xb8b4a0
// 0065103c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651043  83c40c               add esp, 0xc
// 00651046  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b44678[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b44678, 0);
    return object;
}
