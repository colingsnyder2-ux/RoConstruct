// from server: 100% by nuck16
// roc 2009-12 0064edc0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064edc0  64a100000000         mov eax, dword ptr fs:[0]
// 0064edc6  6aff                 push -1
// 0064edc8  68be1e9400           push 0x941ebe
// 0064edcd  50                   push eax
// 0064edce  b801000000           mov eax, 1
// 0064edd3  64892500000000       mov dword ptr fs:[0], esp
// 0064edda  84059867b800         test byte ptr [0xb86798], al
// 0064ede0  7532                 jne 0x64ee14
// 0064ede2  09059867b800         or dword ptr [0xb86798], eax
// 0064ede8  6a00                 push 0
// 0064edea  68dc33b500           push 0xb533dc
// 0064edef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064edf7  e874feffff           call 0x64ec70
// 0064edfc  50                   push eax
// 0064edfd  b9a066b800           mov ecx, 0xb866a0
// 0064ee02  e8f9510100           call 0x664000
// 0064ee07  6810379800           push 0x983710
// 0064ee0c  e8185b1a00           call 0x7f4929
// 0064ee11  83c404               add esp, 4
// 0064ee14  8b0c24               mov ecx, dword ptr [esp]
// 0064ee17  b8a066b800           mov eax, 0xb866a0
// 0064ee1c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ee23  83c40c               add esp, 0xc
// 0064ee26  c3                   ret 

struct Base;
Base &get_64ec70();
extern char string_00b533dc[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64ec70(), string_00b533dc, 0);
    return object;
}
