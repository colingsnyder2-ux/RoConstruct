// from server: 100% by nuck16
// roc 2009-12 0064f3e0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f3e0  64a100000000         mov eax, dword ptr fs:[0]
// 0064f3e6  6aff                 push -1
// 0064f3e8  687e209400           push 0x94207e
// 0064f3ed  50                   push eax
// 0064f3ee  b801000000           mov eax, 1
// 0064f3f3  64892500000000       mov dword ptr fs:[0], esp
// 0064f3fa  84059875b800         test byte ptr [0xb87598], al
// 0064f400  7532                 jne 0x64f434
// 0064f402  09059875b800         or dword ptr [0xb87598], eax
// 0064f408  6a02                 push 2
// 0064f40a  68b815b400           push 0xb415b8
// 0064f40f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f417  e894afdbff           call 0x40a3b0
// 0064f41c  50                   push eax
// 0064f41d  b9a074b800           mov ecx, 0xb874a0
// 0064f422  e8d94b0100           call 0x664000
// 0064f427  6830369800           push 0x983630
// 0064f42c  e8f8541a00           call 0x7f4929
// 0064f431  83c404               add esp, 4
// 0064f434  8b0c24               mov ecx, dword ptr [esp]
// 0064f437  b8a074b800           mov eax, 0xb874a0
// 0064f43c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f443  83c40c               add esp, 0xc
// 0064f446  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b415b8[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b415b8, 2);
    return object;
}
