// from server: 100% by nuck16
// roc 2009-12 00650480  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650480  64a100000000         mov eax, dword ptr fs:[0]
// 00650486  6aff                 push -1
// 00650488  683e259400           push 0x94253e
// 0065048d  50                   push eax
// 0065048e  b801000000           mov eax, 1
// 00650493  64892500000000       mov dword ptr fs:[0], esp
// 0065049a  8405989bb800         test byte ptr [0xb89b98], al
// 006504a0  7532                 jne 0x6504d4
// 006504a2  0905989bb800         or dword ptr [0xb89b98], eax
// 006504a8  6a00                 push 0
// 006504aa  6818729d00           push 0x9d7218
// 006504af  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006504b7  e8f49edbff           call 0x40a3b0
// 006504bc  50                   push eax
// 006504bd  b9a09ab800           mov ecx, 0xb89aa0
// 006504c2  e8393b0100           call 0x664000
// 006504c7  68d0339800           push 0x9833d0
// 006504cc  e858441a00           call 0x7f4929
// 006504d1  83c404               add esp, 4
// 006504d4  8b0c24               mov ecx, dword ptr [esp]
// 006504d7  b8a09ab800           mov eax, 0xb89aa0
// 006504dc  64890d00000000       mov dword ptr fs:[0], ecx
// 006504e3  83c40c               add esp, 0xc
// 006504e6  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "GameSettings", 0);
    return object;
}
