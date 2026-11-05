// from server: 100% by nuck16
// roc 2009-12 0064fca0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064fca0  64a100000000         mov eax, dword ptr fs:[0]
// 0064fca6  6aff                 push -1
// 0064fca8  68fe229400           push 0x9422fe
// 0064fcad  50                   push eax
// 0064fcae  b801000000           mov eax, 1
// 0064fcb3  64892500000000       mov dword ptr fs:[0], esp
// 0064fcba  84059889b800         test byte ptr [0xb88998], al
// 0064fcc0  7532                 jne 0x64fcf4
// 0064fcc2  09059889b800         or dword ptr [0xb88998], eax
// 0064fcc8  6a00                 push 0
// 0064fcca  68f8e79d00           push 0x9de7f8
// 0064fccf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064fcd7  e854ffffff           call 0x64fc30
// 0064fcdc  50                   push eax
// 0064fcdd  b9a088b800           mov ecx, 0xb888a0
// 0064fce2  e819430100           call 0x664000
// 0064fce7  68f0349800           push 0x9834f0
// 0064fcec  e8384c1a00           call 0x7f4929
// 0064fcf1  83c404               add esp, 4
// 0064fcf4  8b0c24               mov ecx, dword ptr [esp]
// 0064fcf7  b8a088b800           mov eax, 0xb888a0
// 0064fcfc  64890d00000000       mov dword ptr fs:[0], ecx
// 0064fd03  83c40c               add esp, 0xc
// 0064fd06  c3                   ret 

struct Base;
Base &get_64fc30();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64fc30(), "Snap", 0);
    return object;
}
