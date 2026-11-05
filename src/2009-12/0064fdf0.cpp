// from server: 100% by nuck16
// roc 2009-12 0064fdf0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064fdf0  64a100000000         mov eax, dword ptr fs:[0]
// 0064fdf6  6aff                 push -1
// 0064fdf8  685e239400           push 0x94235e
// 0064fdfd  50                   push eax
// 0064fdfe  b801000000           mov eax, 1
// 0064fe03  64892500000000       mov dword ptr fs:[0], esp
// 0064fe0a  8405988cb800         test byte ptr [0xb88c98], al
// 0064fe10  7532                 jne 0x64fe44
// 0064fe12  0905988cb800         or dword ptr [0xb88c98], eax
// 0064fe18  6a00                 push 0
// 0064fe1a  6810e89d00           push 0x9de810
// 0064fe1f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064fe27  e804feffff           call 0x64fc30
// 0064fe2c  50                   push eax
// 0064fe2d  b9a08bb800           mov ecx, 0xb88ba0
// 0064fe32  e8c9410100           call 0x664000
// 0064fe37  68c0349800           push 0x9834c0
// 0064fe3c  e8e84a1a00           call 0x7f4929
// 0064fe41  83c404               add esp, 4
// 0064fe44  8b0c24               mov ecx, dword ptr [esp]
// 0064fe47  b8a08bb800           mov eax, 0xb88ba0
// 0064fe4c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064fe53  83c40c               add esp, 0xc
// 0064fe56  c3                   ret 

struct Base;
Base &get_64fc30();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64fc30(), "Rotate", 0);
    return object;
}
