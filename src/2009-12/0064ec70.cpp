// from server: 100% by nuck16
// roc 2009-12 0064ec70  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064ec70  64a100000000         mov eax, dword ptr fs:[0]
// 0064ec76  6aff                 push -1
// 0064ec78  685e1e9400           push 0x941e5e
// 0064ec7d  50                   push eax
// 0064ec7e  b801000000           mov eax, 1
// 0064ec83  64892500000000       mov dword ptr fs:[0], esp
// 0064ec8a  84059864b800         test byte ptr [0xb86498], al
// 0064ec90  7532                 jne 0x64ecc4
// 0064ec92  09059864b800         or dword ptr [0xb86498], eax
// 0064ec98  6a00                 push 0
// 0064ec9a  6854e1b500           push 0xb5e154
// 0064ec9f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064eca7  e804b7dbff           call 0x40a3b0
// 0064ecac  50                   push eax
// 0064ecad  b9a063b800           mov ecx, 0xb863a0
// 0064ecb2  e849530100           call 0x664000
// 0064ecb7  6840379800           push 0x983740
// 0064ecbc  e8685c1a00           call 0x7f4929
// 0064ecc1  83c404               add esp, 4
// 0064ecc4  8b0c24               mov ecx, dword ptr [esp]
// 0064ecc7  b8a063b800           mov eax, 0xb863a0
// 0064eccc  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ecd3  83c40c               add esp, 0xc
// 0064ecd6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b5e154[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b5e154, 0);
    return object;
}
