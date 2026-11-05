// from server: 100% by nuck16
// roc 2009-12 0057b400  unit: RBX::VCylinderMesh::?$FactoryProduct  size: 103 bytes
//
// 0057b400  64a100000000         mov eax, dword ptr fs:[0]
// 0057b406  6aff                 push -1
// 0057b408  680ec29300           push 0x93c20e
// 0057b40d  50                   push eax
// 0057b40e  b801000000           mov eax, 1
// 0057b413  64892500000000       mov dword ptr fs:[0], esp
// 0057b41a  8405782bb800         test byte ptr [0xb82b78], al
// 0057b420  7532                 jne 0x57b454
// 0057b422  0905782bb800         or dword ptr [0xb82b78], eax
// 0057b428  6a00                 push 0
// 0057b42a  6888d8b400           push 0xb4d888
// 0057b42f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0057b437  e864fdffff           call 0x57b1a0
// 0057b43c  50                   push eax
// 0057b43d  b9802ab800           mov ecx, 0xb82a80
// 0057b442  e8b98b0e00           call 0x664000
// 0057b447  68200c9800           push 0x980c20
// 0057b44c  e8d8942700           call 0x7f4929
// 0057b451  83c404               add esp, 4
// 0057b454  8b0c24               mov ecx, dword ptr [esp]
// 0057b457  b8802ab800           mov eax, 0xb82a80
// 0057b45c  64890d00000000       mov dword ptr fs:[0], ecx
// 0057b463  83c40c               add esp, 0xc
// 0057b466  c3                   ret 

struct Base;
Base &get_57b1a0();
extern char string_00b4d888[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_57b1a0(), string_00b4d888, 0);
    return object;
}
