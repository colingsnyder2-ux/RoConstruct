// from server: 100% by nuck16
// roc 2009-12 0057b390  unit: RBX::VCylinderMesh::?$FactoryProduct  size: 103 bytes
//
// 0057b390  64a100000000         mov eax, dword ptr fs:[0]
// 0057b396  6aff                 push -1
// 0057b398  68eec19300           push 0x93c1ee
// 0057b39d  50                   push eax
// 0057b39e  b801000000           mov eax, 1
// 0057b3a3  64892500000000       mov dword ptr fs:[0], esp
// 0057b3aa  8405782ab800         test byte ptr [0xb82a78], al
// 0057b3b0  7532                 jne 0x57b3e4
// 0057b3b2  0905782ab800         or dword ptr [0xb82a78], eax
// 0057b3b8  6a00                 push 0
// 0057b3ba  6878d8b400           push 0xb4d878
// 0057b3bf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0057b3c7  e8d4fdffff           call 0x57b1a0
// 0057b3cc  50                   push eax
// 0057b3cd  b98029b800           mov ecx, 0xb82980
// 0057b3d2  e8298c0e00           call 0x664000
// 0057b3d7  68300c9800           push 0x980c30
// 0057b3dc  e848952700           call 0x7f4929
// 0057b3e1  83c404               add esp, 4
// 0057b3e4  8b0c24               mov ecx, dword ptr [esp]
// 0057b3e7  b88029b800           mov eax, 0xb82980
// 0057b3ec  64890d00000000       mov dword ptr fs:[0], ecx
// 0057b3f3  83c40c               add esp, 0xc
// 0057b3f6  c3                   ret 

struct Base;
Base &get_57b1a0();
extern char string_00b4d878[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_57b1a0(), string_00b4d878, 0);
    return object;
}
