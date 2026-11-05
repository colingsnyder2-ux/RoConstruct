// from server: 100% by nuck16
// roc 2009-12 00651b40  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651b40  64a100000000         mov eax, dword ptr fs:[0]
// 00651b46  6aff                 push -1
// 00651b48  68be2b9400           push 0x942bbe
// 00651b4d  50                   push eax
// 00651b4e  b801000000           mov eax, 1
// 00651b53  64892500000000       mov dword ptr fs:[0], esp
// 00651b5a  840598cfb800         test byte ptr [0xb8cf98], al
// 00651b60  7532                 jne 0x651b94
// 00651b62  090598cfb800         or dword ptr [0xb8cf98], eax
// 00651b68  6a00                 push 0
// 00651b6a  68f0afb500           push 0xb5aff0
// 00651b6f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651b77  e894fdffff           call 0x651910
// 00651b7c  50                   push eax
// 00651b7d  b9a0ceb800           mov ecx, 0xb8cea0
// 00651b82  e879240100           call 0x664000
// 00651b87  6890309800           push 0x983090
// 00651b8c  e8982d1a00           call 0x7f4929
// 00651b91  83c404               add esp, 4
// 00651b94  8b0c24               mov ecx, dword ptr [esp]
// 00651b97  b8a0ceb800           mov eax, 0xb8cea0
// 00651b9c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651ba3  83c40c               add esp, 0xc
// 00651ba6  c3                   ret 

struct Base;
Base &get_651910();
extern char string_00b5aff0[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_651910(), string_00b5aff0, 0);
    return object;
}
