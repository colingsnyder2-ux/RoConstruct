// from server: 100% by nuck16
// roc 2009-12 0064f220  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f220  64a100000000         mov eax, dword ptr fs:[0]
// 0064f226  6aff                 push -1
// 0064f228  68fe1f9400           push 0x941ffe
// 0064f22d  50                   push eax
// 0064f22e  b801000000           mov eax, 1
// 0064f233  64892500000000       mov dword ptr fs:[0], esp
// 0064f23a  84059871b800         test byte ptr [0xb87198], al
// 0064f240  7532                 jne 0x64f274
// 0064f242  09059871b800         or dword ptr [0xb87198], eax
// 0064f248  6a00                 push 0
// 0064f24a  6800c79d00           push 0x9dc700
// 0064f24f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f257  e854b1dbff           call 0x40a3b0
// 0064f25c  50                   push eax
// 0064f25d  b9a070b800           mov ecx, 0xb870a0
// 0064f262  e8994d0100           call 0x664000
// 0064f267  6870369800           push 0x983670
// 0064f26c  e8b8561a00           call 0x7f4929
// 0064f271  83c404               add esp, 4
// 0064f274  8b0c24               mov ecx, dword ptr [esp]
// 0064f277  b8a070b800           mov eax, 0xb870a0
// 0064f27c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f283  83c40c               add esp, 0xc
// 0064f286  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "Backpack", 0);
    return object;
}
