// from server: 100% by nuck16
// roc 2009-12 0064fb50  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064fb50  64a100000000         mov eax, dword ptr fs:[0]
// 0064fb56  6aff                 push -1
// 0064fb58  689e229400           push 0x94229e
// 0064fb5d  50                   push eax
// 0064fb5e  b801000000           mov eax, 1
// 0064fb63  64892500000000       mov dword ptr fs:[0], esp
// 0064fb6a  84059886b800         test byte ptr [0xb88698], al
// 0064fb70  7532                 jne 0x64fba4
// 0064fb72  09059886b800         or dword ptr [0xb88698], eax
// 0064fb78  6a00                 push 0
// 0064fb7a  68841ab400           push 0xb41a84
// 0064fb7f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064fb87  e8c4f1ffff           call 0x64ed50
// 0064fb8c  50                   push eax
// 0064fb8d  b9a085b800           mov ecx, 0xb885a0
// 0064fb92  e869440100           call 0x664000
// 0064fb97  6820359800           push 0x983520
// 0064fb9c  e8884d1a00           call 0x7f4929
// 0064fba1  83c404               add esp, 4
// 0064fba4  8b0c24               mov ecx, dword ptr [esp]
// 0064fba7  b8a085b800           mov eax, 0xb885a0
// 0064fbac  64890d00000000       mov dword ptr fs:[0], ecx
// 0064fbb3  83c40c               add esp, 0xc
// 0064fbb6  c3                   ret 

struct Base;
Base &get_64ed50();
extern char string_00b41a84[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64ed50(), string_00b41a84, 0);
    return object;
}
