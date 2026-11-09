// from server: 100% by nuck16
// roc 2009-12 0064eea0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064eea0  64a100000000         mov eax, dword ptr fs:[0]
// 0064eea6  6aff                 push -1
// 0064eea8  68fe1e9400           push 0x941efe
// 0064eead  50                   push eax
// 0064eeae  b801000000           mov eax, 1
// 0064eeb3  64892500000000       mov dword ptr fs:[0], esp
// 0064eeba  84059869b800         test byte ptr [0xb86998], al
// 0064eec0  7532                 jne 0x64eef4
// 0064eec2  09059869b800         or dword ptr [0xb86998], eax
// 0064eec8  6a00                 push 0
// 0064eeca  68f0309d00           push 0x9d30f0
// 0064eecf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064eed7  e854ffffff           call 0x64ee30
// 0064eedc  50                   push eax
// 0064eedd  b9a068b800           mov ecx, 0xb868a0
// 0064eee2  e819510100           call 0x664000
// 0064eee7  68f0369800           push 0x9836f0
// 0064eeec  e8385a1a00           call 0x7f4929
// 0064eef1  83c404               add esp, 4
// 0064eef4  8b0c24               mov ecx, dword ptr [esp]
// 0064eef7  b8a068b800           mov eax, 0xb868a0
// 0064eefc  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ef03  83c40c               add esp, 0xc
// 0064ef06  c3                   ret 

struct Base;
Base &get_64ee30();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64ee30(), "Hat", 0);
    return object;
}
