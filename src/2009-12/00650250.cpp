// from server: 100% by nuck16
// roc 2009-12 00650250  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650250  64a100000000         mov eax, dword ptr fs:[0]
// 00650256  6aff                 push -1
// 00650258  689e249400           push 0x94249e
// 0065025d  50                   push eax
// 0065025e  b801000000           mov eax, 1
// 00650263  64892500000000       mov dword ptr fs:[0], esp
// 0065026a  84059896b800         test byte ptr [0xb89698], al
// 00650270  7532                 jne 0x6502a4
// 00650272  09059896b800         or dword ptr [0xb89698], eax
// 00650278  6a00                 push 0
// 0065027a  68c01b9d00           push 0x9d1bc0
// 0065027f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650287  e884ecffff           call 0x64ef10
// 0065028c  50                   push eax
// 0065028d  b9a095b800           mov ecx, 0xb895a0
// 00650292  e8693d0100           call 0x664000
// 00650297  6820349800           push 0x983420
// 0065029c  e888461a00           call 0x7f4929
// 006502a1  83c404               add esp, 4
// 006502a4  8b0c24               mov ecx, dword ptr [esp]
// 006502a7  b8a095b800           mov eax, 0xb895a0
// 006502ac  64890d00000000       mov dword ptr fs:[0], ecx
// 006502b3  83c40c               add esp, 0xc
// 006502b6  c3                   ret 

struct Base;
Base &get_64ef10();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64ef10(), "Tool", 0);
    return object;
}
