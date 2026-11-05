// from server: 100% by nuck16
// roc 2009-12 0064f530  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f530  64a100000000         mov eax, dword ptr fs:[0]
// 0064f536  6aff                 push -1
// 0064f538  68de209400           push 0x9420de
// 0064f53d  50                   push eax
// 0064f53e  b801000000           mov eax, 1
// 0064f543  64892500000000       mov dword ptr fs:[0], esp
// 0064f54a  84059878b800         test byte ptr [0xb87898], al
// 0064f550  7532                 jne 0x64f584
// 0064f552  09059878b800         or dword ptr [0xb87898], eax
// 0064f558  6a00                 push 0
// 0064f55a  68f4d59d00           push 0x9dd5f4
// 0064f55f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f567  e844aedbff           call 0x40a3b0
// 0064f56c  50                   push eax
// 0064f56d  b9a077b800           mov ecx, 0xb877a0
// 0064f572  e8894a0100           call 0x664000
// 0064f577  6800369800           push 0x983600
// 0064f57c  e8a8531a00           call 0x7f4929
// 0064f581  83c404               add esp, 4
// 0064f584  8b0c24               mov ecx, dword ptr [esp]
// 0064f587  b8a077b800           mov eax, 0xb877a0
// 0064f58c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f593  83c40c               add esp, 0xc
// 0064f596  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "BodyColors", 0);
    return object;
}
