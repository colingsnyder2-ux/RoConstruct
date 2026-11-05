// from server: 100% by nuck16
// roc 2009-12 0064ef80  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064ef80  64a100000000         mov eax, dword ptr fs:[0]
// 0064ef86  6aff                 push -1
// 0064ef88  683e1f9400           push 0x941f3e
// 0064ef8d  50                   push eax
// 0064ef8e  b801000000           mov eax, 1
// 0064ef93  64892500000000       mov dword ptr fs:[0], esp
// 0064ef9a  8405986bb800         test byte ptr [0xb86b98], al
// 0064efa0  7532                 jne 0x64efd4
// 0064efa2  0905986bb800         or dword ptr [0xb86b98], eax
// 0064efa8  6a00                 push 0
// 0064efaa  6800119d00           push 0x9d1100
// 0064efaf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064efb7  e854ffffff           call 0x64ef10
// 0064efbc  50                   push eax
// 0064efbd  b9a06ab800           mov ecx, 0xb86aa0
// 0064efc2  e839500100           call 0x664000
// 0064efc7  68d0369800           push 0x9836d0
// 0064efcc  e858591a00           call 0x7f4929
// 0064efd1  83c404               add esp, 4
// 0064efd4  8b0c24               mov ecx, dword ptr [esp]
// 0064efd7  b8a06ab800           mov eax, 0xb86aa0
// 0064efdc  64890d00000000       mov dword ptr fs:[0], ecx
// 0064efe3  83c40c               add esp, 0xc
// 0064efe6  c3                   ret 

struct Base;
Base &get_64ef10();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64ef10(), "HopperBin", 0);
    return object;
}
