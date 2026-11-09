// from server: 100% by nuck16
// roc 2009-12 0057b130  unit: RBX::VBlockMesh::?$FactoryProduct  size: 103 bytes
//
// 0057b130  64a100000000         mov eax, dword ptr fs:[0]
// 0057b136  6aff                 push -1
// 0057b138  689ec19300           push 0x93c19e
// 0057b13d  50                   push eax
// 0057b13e  b801000000           mov eax, 1
// 0057b143  64892500000000       mov dword ptr fs:[0], esp
// 0057b14a  84057828b800         test byte ptr [0xb82878], al
// 0057b150  7532                 jne 0x57b184
// 0057b152  09057828b800         or dword ptr [0xb82878], eax
// 0057b158  6a00                 push 0
// 0057b15a  68e0fa9d00           push 0x9dfae0
// 0057b15f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0057b167  e844f2e8ff           call 0x40a3b0
// 0057b16c  50                   push eax
// 0057b16d  b98027b800           mov ecx, 0xb82780
// 0057b172  e8898e0e00           call 0x664000
// 0057b177  68500c9800           push 0x980c50
// 0057b17c  e8a8972700           call 0x7f4929
// 0057b181  83c404               add esp, 4
// 0057b184  8b0c24               mov ecx, dword ptr [esp]
// 0057b187  b88027b800           mov eax, 0xb82780
// 0057b18c  64890d00000000       mov dword ptr fs:[0], ecx
// 0057b193  83c40c               add esp, 0xc
// 0057b196  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "DataModelMesh", 0);
    return object;
}
