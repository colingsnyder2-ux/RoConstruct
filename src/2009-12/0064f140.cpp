// from server: 100% by nuck16
// roc 2009-12 0064f140  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f140  64a100000000         mov eax, dword ptr fs:[0]
// 0064f146  6aff                 push -1
// 0064f148  68be1f9400           push 0x941fbe
// 0064f14d  50                   push eax
// 0064f14e  b801000000           mov eax, 1
// 0064f153  64892500000000       mov dword ptr fs:[0], esp
// 0064f15a  8405986fb800         test byte ptr [0xb86f98], al
// 0064f160  7532                 jne 0x64f194
// 0064f162  0905986fb800         or dword ptr [0xb86f98], eax
// 0064f168  6a00                 push 0
// 0064f16a  687059b300           push 0xb35970
// 0064f16f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f177  e834b2dbff           call 0x40a3b0
// 0064f17c  50                   push eax
// 0064f17d  b9a06eb800           mov ecx, 0xb86ea0
// 0064f182  e8794e0100           call 0x664000
// 0064f187  6890369800           push 0x983690
// 0064f18c  e898571a00           call 0x7f4929
// 0064f191  83c404               add esp, 4
// 0064f194  8b0c24               mov ecx, dword ptr [esp]
// 0064f197  b8a06eb800           mov eax, 0xb86ea0
// 0064f19c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f1a3  83c40c               add esp, 0xc
// 0064f1a6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b35970[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b35970, 0);
    return object;
}
