// from server: 100% by nuck16
// roc 2009-12 0064fd10  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064fd10  64a100000000         mov eax, dword ptr fs:[0]
// 0064fd16  6aff                 push -1
// 0064fd18  681e239400           push 0x94231e
// 0064fd1d  50                   push eax
// 0064fd1e  b801000000           mov eax, 1
// 0064fd23  64892500000000       mov dword ptr fs:[0], esp
// 0064fd2a  8405988ab800         test byte ptr [0xb88a98], al
// 0064fd30  7532                 jne 0x64fd64
// 0064fd32  0905988ab800         or dword ptr [0xb88a98], eax
// 0064fd38  6a00                 push 0
// 0064fd3a  6800e89d00           push 0x9de800
// 0064fd3f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064fd47  e8e4feffff           call 0x64fc30
// 0064fd4c  50                   push eax
// 0064fd4d  b9a089b800           mov ecx, 0xb889a0
// 0064fd52  e8a9420100           call 0x664000
// 0064fd57  68e0349800           push 0x9834e0
// 0064fd5c  e8c84b1a00           call 0x7f4929
// 0064fd61  83c404               add esp, 4
// 0064fd64  8b0c24               mov ecx, dword ptr [esp]
// 0064fd67  b8a089b800           mov eax, 0xb889a0
// 0064fd6c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064fd73  83c40c               add esp, 0xc
// 0064fd76  c3                   ret 

struct Base;
Base &get_64fc30();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64fc30(), "Weld", 0);
    return object;
}
