// from server: 100% by nuck16
// roc 2009-12 006502c0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006502c0  64a100000000         mov eax, dword ptr fs:[0]
// 006502c6  6aff                 push -1
// 006502c8  68be249400           push 0x9424be
// 006502cd  50                   push eax
// 006502ce  b801000000           mov eax, 1
// 006502d3  64892500000000       mov dword ptr fs:[0], esp
// 006502da  84059897b800         test byte ptr [0xb89798], al
// 006502e0  7532                 jne 0x650314
// 006502e2  09059897b800         or dword ptr [0xb89798], eax
// 006502e8  6a00                 push 0
// 006502ea  6810319e00           push 0x9e3110
// 006502ef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006502f7  e854ffffff           call 0x650250
// 006502fc  50                   push eax
// 006502fd  b9a096b800           mov ecx, 0xb896a0
// 00650302  e8f93c0100           call 0x664000
// 00650307  6810349800           push 0x983410
// 0065030c  e818461a00           call 0x7f4929
// 00650311  83c404               add esp, 4
// 00650314  8b0c24               mov ecx, dword ptr [esp]
// 00650317  b8a096b800           mov eax, 0xb896a0
// 0065031c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650323  83c40c               add esp, 0xc
// 00650326  c3                   ret 

struct Base;
Base &get_650250();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_650250(), "Flag", 0);
    return object;
}
