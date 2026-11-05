// from server: 100% by nuck16
// roc 2009-12 0064fd80  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064fd80  64a100000000         mov eax, dword ptr fs:[0]
// 0064fd86  6aff                 push -1
// 0064fd88  683e239400           push 0x94233e
// 0064fd8d  50                   push eax
// 0064fd8e  b801000000           mov eax, 1
// 0064fd93  64892500000000       mov dword ptr fs:[0], esp
// 0064fd9a  8405988bb800         test byte ptr [0xb88b98], al
// 0064fda0  7532                 jne 0x64fdd4
// 0064fda2  0905988bb800         or dword ptr [0xb88b98], eax
// 0064fda8  6a00                 push 0
// 0064fdaa  6808e89d00           push 0x9de808
// 0064fdaf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064fdb7  e874feffff           call 0x64fc30
// 0064fdbc  50                   push eax
// 0064fdbd  b9a08ab800           mov ecx, 0xb88aa0
// 0064fdc2  e839420100           call 0x664000
// 0064fdc7  68d0349800           push 0x9834d0
// 0064fdcc  e8584b1a00           call 0x7f4929
// 0064fdd1  83c404               add esp, 4
// 0064fdd4  8b0c24               mov ecx, dword ptr [esp]
// 0064fdd7  b8a08ab800           mov eax, 0xb88aa0
// 0064fddc  64890d00000000       mov dword ptr fs:[0], ecx
// 0064fde3  83c40c               add esp, 0xc
// 0064fde6  c3                   ret 

struct Base;
Base &get_64fc30();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64fc30(), "Glue", 0);
    return object;
}
