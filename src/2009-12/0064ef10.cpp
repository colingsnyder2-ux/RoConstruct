// from server: 100% by nuck16
// roc 2009-12 0064ef10  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064ef10  64a100000000         mov eax, dword ptr fs:[0]
// 0064ef16  6aff                 push -1
// 0064ef18  681e1f9400           push 0x941f1e
// 0064ef1d  50                   push eax
// 0064ef1e  b801000000           mov eax, 1
// 0064ef23  64892500000000       mov dword ptr fs:[0], esp
// 0064ef2a  8405986ab800         test byte ptr [0xb86a98], al
// 0064ef30  7532                 jne 0x64ef64
// 0064ef32  0905986ab800         or dword ptr [0xb86a98], eax
// 0064ef38  6a00                 push 0
// 0064ef3a  68f0109d00           push 0x9d10f0
// 0064ef3f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064ef47  e864b4dbff           call 0x40a3b0
// 0064ef4c  50                   push eax
// 0064ef4d  b9a069b800           mov ecx, 0xb869a0
// 0064ef52  e8a9500100           call 0x664000
// 0064ef57  68e0369800           push 0x9836e0
// 0064ef5c  e8c8591a00           call 0x7f4929
// 0064ef61  83c404               add esp, 4
// 0064ef64  8b0c24               mov ecx, dword ptr [esp]
// 0064ef67  b8a069b800           mov eax, 0xb869a0
// 0064ef6c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ef73  83c40c               add esp, 0xc
// 0064ef76  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "BackpackItem", 0);
    return object;
}
