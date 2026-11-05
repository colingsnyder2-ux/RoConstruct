// from server: 100% by nuck16
// roc 2009-12 0064f610  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f610  64a100000000         mov eax, dword ptr fs:[0]
// 0064f616  6aff                 push -1
// 0064f618  681e219400           push 0x94211e
// 0064f61d  50                   push eax
// 0064f61e  b801000000           mov eax, 1
// 0064f623  64892500000000       mov dword ptr fs:[0], esp
// 0064f62a  8405987ab800         test byte ptr [0xb87a98], al
// 0064f630  7532                 jne 0x64f664
// 0064f632  0905987ab800         or dword ptr [0xb87a98], eax
// 0064f638  6a00                 push 0
// 0064f63a  68b453b300           push 0xb353b4
// 0064f63f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f647  e894f6ffff           call 0x64ece0
// 0064f64c  50                   push eax
// 0064f64d  b9a079b800           mov ecx, 0xb879a0
// 0064f652  e8a9490100           call 0x664000
// 0064f657  68e0359800           push 0x9835e0
// 0064f65c  e8c8521a00           call 0x7f4929
// 0064f661  83c404               add esp, 4
// 0064f664  8b0c24               mov ecx, dword ptr [esp]
// 0064f667  b8a079b800           mov eax, 0xb879a0
// 0064f66c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f673  83c40c               add esp, 0xc
// 0064f676  c3                   ret 

struct Base;
Base &get_64ece0();
extern char string_00b353b4[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64ece0(), string_00b353b4, 0);
    return object;
}
