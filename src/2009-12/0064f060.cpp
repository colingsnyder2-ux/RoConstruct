// from server: 100% by nuck16
// roc 2009-12 0064f060  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f060  64a100000000         mov eax, dword ptr fs:[0]
// 0064f066  6aff                 push -1
// 0064f068  687e1f9400           push 0x941f7e
// 0064f06d  50                   push eax
// 0064f06e  b801000000           mov eax, 1
// 0064f073  64892500000000       mov dword ptr fs:[0], esp
// 0064f07a  8405986db800         test byte ptr [0xb86d98], al
// 0064f080  7532                 jne 0x64f0b4
// 0064f082  0905986db800         or dword ptr [0xb86d98], eax
// 0064f088  6a00                 push 0
// 0064f08a  6818119d00           push 0x9d1118
// 0064f08f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f097  e814b3dbff           call 0x40a3b0
// 0064f09c  50                   push eax
// 0064f09d  b9a06cb800           mov ecx, 0xb86ca0
// 0064f0a2  e8594f0100           call 0x664000
// 0064f0a7  68b0369800           push 0x9836b0
// 0064f0ac  e878581a00           call 0x7f4929
// 0064f0b1  83c404               add esp, 4
// 0064f0b4  8b0c24               mov ecx, dword ptr [esp]
// 0064f0b7  b8a06cb800           mov eax, 0xb86ca0
// 0064f0bc  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f0c3  83c40c               add esp, 0xc
// 0064f0c6  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "Hopper", 0);
    return object;
}
