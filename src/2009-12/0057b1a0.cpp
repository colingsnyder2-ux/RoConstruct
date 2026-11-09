// from server: 100% by nuck16
// roc 2009-12 0057b1a0  unit: RBX::VBlockMesh::?$FactoryProduct  size: 103 bytes
//
// 0057b1a0  64a100000000         mov eax, dword ptr fs:[0]
// 0057b1a6  6aff                 push -1
// 0057b1a8  68bec19300           push 0x93c1be
// 0057b1ad  50                   push eax
// 0057b1ae  b801000000           mov eax, 1
// 0057b1b3  64892500000000       mov dword ptr fs:[0], esp
// 0057b1ba  84057829b800         test byte ptr [0xb82978], al
// 0057b1c0  7532                 jne 0x57b1f4
// 0057b1c2  09057829b800         or dword ptr [0xb82978], eax
// 0057b1c8  6a00                 push 0
// 0057b1ca  689cd8b400           push 0xb4d89c
// 0057b1cf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0057b1d7  e854ffffff           call 0x57b130
// 0057b1dc  50                   push eax
// 0057b1dd  b98028b800           mov ecx, 0xb82880
// 0057b1e2  e8198e0e00           call 0x664000
// 0057b1e7  68400c9800           push 0x980c40
// 0057b1ec  e838972700           call 0x7f4929
// 0057b1f1  83c404               add esp, 4
// 0057b1f4  8b0c24               mov ecx, dword ptr [esp]
// 0057b1f7  b88028b800           mov eax, 0xb82880
// 0057b1fc  64890d00000000       mov dword ptr fs:[0], ecx
// 0057b203  83c40c               add esp, 0xc
// 0057b206  c3                   ret 

struct Base;
Base &get_57b130();
extern char string_00b4d89c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_57b130(), string_00b4d89c, 0);
    return object;
}
