// from server: 100% by nuck16
// roc 2009-12 006510c0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006510c0  64a100000000         mov eax, dword ptr fs:[0]
// 006510c6  6aff                 push -1
// 006510c8  68be289400           push 0x9428be
// 006510cd  50                   push eax
// 006510ce  b801000000           mov eax, 1
// 006510d3  64892500000000       mov dword ptr fs:[0], esp
// 006510da  840598b7b800         test byte ptr [0xb8b798], al
// 006510e0  7532                 jne 0x651114
// 006510e2  090598b7b800         or dword ptr [0xb8b798], eax
// 006510e8  6a00                 push 0
// 006510ea  68e0d09d00           push 0x9dd0e0
// 006510ef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006510f7  e8b492dbff           call 0x40a3b0
// 006510fc  50                   push eax
// 006510fd  b9a0b6b800           mov ecx, 0xb8b6a0
// 00651102  e8f92e0100           call 0x664000
// 00651107  6810329800           push 0x983210
// 0065110c  e818381a00           call 0x7f4929
// 00651111  83c404               add esp, 4
// 00651114  8b0c24               mov ecx, dword ptr [esp]
// 00651117  b8a0b6b800           mov eax, 0xb8b6a0
// 0065111c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651123  83c40c               add esp, 0xc
// 00651126  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "SpawnerService", 0);
    return object;
}
