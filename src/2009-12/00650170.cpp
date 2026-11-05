// from server: 100% by nuck16
// roc 2009-12 00650170  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650170  64a100000000         mov eax, dword ptr fs:[0]
// 00650176  6aff                 push -1
// 00650178  685e249400           push 0x94245e
// 0065017d  50                   push eax
// 0065017e  b801000000           mov eax, 1
// 00650183  64892500000000       mov dword ptr fs:[0], esp
// 0065018a  84059894b800         test byte ptr [0xb89498], al
// 00650190  7532                 jne 0x6501c4
// 00650192  09059894b800         or dword ptr [0xb89498], eax
// 00650198  6a00                 push 0
// 0065019a  68002a9e00           push 0x9e2a00
// 0065019f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006501a7  e884faffff           call 0x64fc30
// 006501ac  50                   push eax
// 006501ad  b9a093b800           mov ecx, 0xb893a0
// 006501b2  e8493e0100           call 0x664000
// 006501b7  6840349800           push 0x983440
// 006501bc  e868471a00           call 0x7f4929
// 006501c1  83c404               add esp, 4
// 006501c4  8b0c24               mov ecx, dword ptr [esp]
// 006501c7  b8a093b800           mov eax, 0xb893a0
// 006501cc  64890d00000000       mov dword ptr fs:[0], ecx
// 006501d3  83c40c               add esp, 0xc
// 006501d6  c3                   ret 

struct Base;
Base &get_64fc30();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64fc30(), "VelocityMotor", 0);
    return object;
}
