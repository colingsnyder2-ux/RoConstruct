// from server: 100% by nuck16
// roc 2009-12 0064fa00  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064fa00  64a100000000         mov eax, dword ptr fs:[0]
// 0064fa06  6aff                 push -1
// 0064fa08  683e229400           push 0x94223e
// 0064fa0d  50                   push eax
// 0064fa0e  b801000000           mov eax, 1
// 0064fa13  64892500000000       mov dword ptr fs:[0], esp
// 0064fa1a  84059883b800         test byte ptr [0xb88398], al
// 0064fa20  7532                 jne 0x64fa54
// 0064fa22  09059883b800         or dword ptr [0xb88398], eax
// 0064fa28  6a00                 push 0
// 0064fa2a  68fcb8b300           push 0xb3b8fc
// 0064fa2f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064fa37  e854ffffff           call 0x64f990
// 0064fa3c  50                   push eax
// 0064fa3d  b9a082b800           mov ecx, 0xb882a0
// 0064fa42  e8b9450100           call 0x664000
// 0064fa47  6850359800           push 0x983550
// 0064fa4c  e8d84e1a00           call 0x7f4929
// 0064fa51  83c404               add esp, 4
// 0064fa54  8b0c24               mov ecx, dword ptr [esp]
// 0064fa57  b8a082b800           mov eax, 0xb882a0
// 0064fa5c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064fa63  83c40c               add esp, 0xc
// 0064fa66  c3                   ret 

struct Base;
Base &get_64f990();
extern char string_00b3b8fc[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64f990(), string_00b3b8fc, 0);
    return object;
}
