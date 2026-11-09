// from server: 100% by nuck16
// roc 2009-12 0064f4c0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f4c0  64a100000000         mov eax, dword ptr fs:[0]
// 0064f4c6  6aff                 push -1
// 0064f4c8  68be209400           push 0x9420be
// 0064f4cd  50                   push eax
// 0064f4ce  b801000000           mov eax, 1
// 0064f4d3  64892500000000       mov dword ptr fs:[0], esp
// 0064f4da  84059877b800         test byte ptr [0xb87798], al
// 0064f4e0  7532                 jne 0x64f514
// 0064f4e2  09059877b800         or dword ptr [0xb87798], eax
// 0064f4e8  6a00                 push 0
// 0064f4ea  68d0d59d00           push 0x9dd5d0
// 0064f4ef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f4f7  e8b4aedbff           call 0x40a3b0
// 0064f4fc  50                   push eax
// 0064f4fd  b9a076b800           mov ecx, 0xb876a0
// 0064f502  e8f94a0100           call 0x664000
// 0064f507  6810369800           push 0x983610
// 0064f50c  e818541a00           call 0x7f4929
// 0064f511  83c404               add esp, 4
// 0064f514  8b0c24               mov ecx, dword ptr [esp]
// 0064f517  b8a076b800           mov eax, 0xb876a0
// 0064f51c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f523  83c40c               add esp, 0xc
// 0064f526  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "ShirtGraphic", 0);
    return object;
}
