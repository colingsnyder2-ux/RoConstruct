// from server: 100% by nuck16
// roc 2009-12 00650560  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650560  64a100000000         mov eax, dword ptr fs:[0]
// 00650566  6aff                 push -1
// 00650568  687e259400           push 0x94257e
// 0065056d  50                   push eax
// 0065056e  b801000000           mov eax, 1
// 00650573  64892500000000       mov dword ptr fs:[0], esp
// 0065057a  8405989db800         test byte ptr [0xb89d98], al
// 00650580  7532                 jne 0x6505b4
// 00650582  0905989db800         or dword ptr [0xb89d98], eax
// 00650588  6a00                 push 0
// 0065058a  68301fb500           push 0xb51f30
// 0065058f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650597  e8149edbff           call 0x40a3b0
// 0065059c  50                   push eax
// 0065059d  b9a09cb800           mov ecx, 0xb89ca0
// 006505a2  e8593a0100           call 0x664000
// 006505a7  68b0339800           push 0x9833b0
// 006505ac  e878431a00           call 0x7f4929
// 006505b1  83c404               add esp, 4
// 006505b4  8b0c24               mov ecx, dword ptr [esp]
// 006505b7  b8a09cb800           mov eax, 0xb89ca0
// 006505bc  64890d00000000       mov dword ptr fs:[0], ecx
// 006505c3  83c40c               add esp, 0xc
// 006505c6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b51f30[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b51f30, 0);
    return object;
}
