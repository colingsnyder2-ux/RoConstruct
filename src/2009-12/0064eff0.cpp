// from server: 100% by nuck16
// roc 2009-12 0064eff0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064eff0  64a100000000         mov eax, dword ptr fs:[0]
// 0064eff6  6aff                 push -1
// 0064eff8  685e1f9400           push 0x941f5e
// 0064effd  50                   push eax
// 0064effe  b801000000           mov eax, 1
// 0064f003  64892500000000       mov dword ptr fs:[0], esp
// 0064f00a  8405986cb800         test byte ptr [0xb86c98], al
// 0064f010  7532                 jne 0x64f044
// 0064f012  0905986cb800         or dword ptr [0xb86c98], eax
// 0064f018  6a00                 push 0
// 0064f01a  680c119d00           push 0x9d110c
// 0064f01f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f027  e884b3dbff           call 0x40a3b0
// 0064f02c  50                   push eax
// 0064f02d  b9a06bb800           mov ecx, 0xb86ba0
// 0064f032  e8c94f0100           call 0x664000
// 0064f037  68c0369800           push 0x9836c0
// 0064f03c  e8e8581a00           call 0x7f4929
// 0064f041  83c404               add esp, 4
// 0064f044  8b0c24               mov ecx, dword ptr [esp]
// 0064f047  b8a06bb800           mov eax, 0xb86ba0
// 0064f04c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f053  83c40c               add esp, 0xc
// 0064f056  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "StarterPack", 0);
    return object;
}
