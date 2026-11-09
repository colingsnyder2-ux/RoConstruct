// from server: 100% by nuck16
// roc 2009-12 0064f450  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0064f450
//
// 0064f450  64a100000000         mov eax, dword ptr fs:[0]
// 0064f456  6aff                 push -1
// 0064f458  689e209400           push 0x94209e
// 0064f45d  50                   push eax
// 0064f45e  b801000000           mov eax, 1
// 0064f463  64892500000000       mov dword ptr fs:[0], esp
// 0064f46a  84059876b800         test byte ptr [0xb87698], al
// 0064f470  7532                 jne 0x64f4a4
// 0064f472  09059876b800         or dword ptr [0xb87698], eax
// 0064f478  6a00                 push 0
// 0064f47a  686c60b300           push 0xb3606c
// 0064f47f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f487  e824afdbff           call 0x40a3b0
// 0064f48c  50                   push eax
// 0064f48d  b9a075b800           mov ecx, 0xb875a0
// 0064f492  e8694b0100           call 0x664000
// 0064f497  6820369800           push 0x983620
// 0064f49c  e888541a00           call 0x7f4929
// 0064f4a1  83c404               add esp, 4
// 0064f4a4  8b0c24               mov ecx, dword ptr [esp]
// 0064f4a7  b8a075b800           mov eax, 0xb875a0
// 0064f4ac  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f4b3  83c40c               add esp, 0xc
// 0064f4b6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b3606c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b3606c, 0);
    return object;
}
