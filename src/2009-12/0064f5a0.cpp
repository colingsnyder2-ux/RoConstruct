// from server: 100% by nuck16
// roc 2009-12 0064f5a0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f5a0  64a100000000         mov eax, dword ptr fs:[0]
// 0064f5a6  6aff                 push -1
// 0064f5a8  68fe209400           push 0x9420fe
// 0064f5ad  50                   push eax
// 0064f5ae  b801000000           mov eax, 1
// 0064f5b3  64892500000000       mov dword ptr fs:[0], esp
// 0064f5ba  84059879b800         test byte ptr [0xb87998], al
// 0064f5c0  7532                 jne 0x64f5f4
// 0064f5c2  09059879b800         or dword ptr [0xb87998], eax
// 0064f5c8  6a00                 push 0
// 0064f5ca  68ecd59d00           push 0x9dd5ec
// 0064f5cf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f5d7  e8d4addbff           call 0x40a3b0
// 0064f5dc  50                   push eax
// 0064f5dd  b9a078b800           mov ecx, 0xb878a0
// 0064f5e2  e8194a0100           call 0x664000
// 0064f5e7  68f0359800           push 0x9835f0
// 0064f5ec  e838531a00           call 0x7f4929
// 0064f5f1  83c404               add esp, 4
// 0064f5f4  8b0c24               mov ecx, dword ptr [esp]
// 0064f5f7  b8a078b800           mov eax, 0xb878a0
// 0064f5fc  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f603  83c40c               add esp, 0xc
// 0064f606  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "Skin", 0);
    return object;
}
