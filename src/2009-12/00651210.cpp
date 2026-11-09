// from server: 100% by nuck16
// roc 2009-12 00651210  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651210  64a100000000         mov eax, dword ptr fs:[0]
// 00651216  6aff                 push -1
// 00651218  681e299400           push 0x94291e
// 0065121d  50                   push eax
// 0065121e  b801000000           mov eax, 1
// 00651223  64892500000000       mov dword ptr fs:[0], esp
// 0065122a  840598bab800         test byte ptr [0xb8ba98], al
// 00651230  7532                 jne 0x651264
// 00651232  090598bab800         or dword ptr [0xb8ba98], eax
// 00651238  6a00                 push 0
// 0065123a  6818dc9d00           push 0x9ddc18
// 0065123f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651247  e86491dbff           call 0x40a3b0
// 0065124c  50                   push eax
// 0065124d  b9a0b9b800           mov ecx, 0xb8b9a0
// 00651252  e8a92d0100           call 0x664000
// 00651257  68e0319800           push 0x9831e0
// 0065125c  e8c8361a00           call 0x7f4929
// 00651261  83c404               add esp, 4
// 00651264  8b0c24               mov ecx, dword ptr [esp]
// 00651267  b8a0b9b800           mov eax, 0xb8b9a0
// 0065126c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651273  83c40c               add esp, 0xc
// 00651276  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "Teams", 0);
    return object;
}
