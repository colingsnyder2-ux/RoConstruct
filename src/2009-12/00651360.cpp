// from server: 100% by nuck16
// roc 2009-12 00651360  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651360  64a100000000         mov eax, dword ptr fs:[0]
// 00651366  6aff                 push -1
// 00651368  687e299400           push 0x94297e
// 0065136d  50                   push eax
// 0065136e  b801000000           mov eax, 1
// 00651373  64892500000000       mov dword ptr fs:[0], esp
// 0065137a  840598bdb800         test byte ptr [0xb8bd98], al
// 00651380  7532                 jne 0x6513b4
// 00651382  090598bdb800         or dword ptr [0xb8bd98], eax
// 00651388  6a00                 push 0
// 0065138a  68b409b400           push 0xb409b4
// 0065138f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651397  e81490dbff           call 0x40a3b0
// 0065139c  50                   push eax
// 0065139d  b9a0bcb800           mov ecx, 0xb8bca0
// 006513a2  e8592c0100           call 0x664000
// 006513a7  68b0319800           push 0x9831b0
// 006513ac  e878351a00           call 0x7f4929
// 006513b1  83c404               add esp, 4
// 006513b4  8b0c24               mov ecx, dword ptr [esp]
// 006513b7  b8a0bcb800           mov eax, 0xb8bca0
// 006513bc  64890d00000000       mov dword ptr fs:[0], ecx
// 006513c3  83c40c               add esp, 0xc
// 006513c6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b409b4[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b409b4, 0);
    return object;
}
