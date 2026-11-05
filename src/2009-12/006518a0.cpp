// from server: 100% by nuck16
// roc 2009-12 006518a0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006518a0  64a100000000         mov eax, dword ptr fs:[0]
// 006518a6  6aff                 push -1
// 006518a8  68fe2a9400           push 0x942afe
// 006518ad  50                   push eax
// 006518ae  b801000000           mov eax, 1
// 006518b3  64892500000000       mov dword ptr fs:[0], esp
// 006518ba  840598c9b800         test byte ptr [0xb8c998], al
// 006518c0  7532                 jne 0x6518f4
// 006518c2  090598c9b800         or dword ptr [0xb8c998], eax
// 006518c8  6a00                 push 0
// 006518ca  68bcfdb500           push 0xb5fdbc
// 006518cf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006518d7  e854ffffff           call 0x651830
// 006518dc  50                   push eax
// 006518dd  b9a0c8b800           mov ecx, 0xb8c8a0
// 006518e2  e819270100           call 0x664000
// 006518e7  68f0309800           push 0x9830f0
// 006518ec  e838301a00           call 0x7f4929
// 006518f1  83c404               add esp, 4
// 006518f4  8b0c24               mov ecx, dword ptr [esp]
// 006518f7  b8a0c8b800           mov eax, 0xb8c8a0
// 006518fc  64890d00000000       mov dword ptr fs:[0], ecx
// 00651903  83c40c               add esp, 0xc
// 00651906  c3                   ret 

struct Base;
Base &get_651830();
extern char string_00b5fdbc[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_651830(), string_00b5fdbc, 0);
    return object;
}
