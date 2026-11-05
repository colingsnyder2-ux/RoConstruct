// from server: 100% by nuck16
// roc 2009-12 006504f0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006504f0  64a100000000         mov eax, dword ptr fs:[0]
// 006504f6  6aff                 push -1
// 006504f8  685e259400           push 0x94255e
// 006504fd  50                   push eax
// 006504fe  b801000000           mov eax, 1
// 00650503  64892500000000       mov dword ptr fs:[0], esp
// 0065050a  8405989cb800         test byte ptr [0xb89c98], al
// 00650510  7532                 jne 0x650544
// 00650512  0905989cb800         or dword ptr [0xb89c98], eax
// 00650518  6a00                 push 0
// 0065051a  68bc66b500           push 0xb566bc
// 0065051f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650527  e8849edbff           call 0x40a3b0
// 0065052c  50                   push eax
// 0065052d  b9a09bb800           mov ecx, 0xb89ba0
// 00650532  e8c93a0100           call 0x664000
// 00650537  68c0339800           push 0x9833c0
// 0065053c  e8e8431a00           call 0x7f4929
// 00650541  83c404               add esp, 4
// 00650544  8b0c24               mov ecx, dword ptr [esp]
// 00650547  b8a09bb800           mov eax, 0xb89ba0
// 0065054c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650553  83c40c               add esp, 0xc
// 00650556  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b566bc[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b566bc, 0);
    return object;
}
