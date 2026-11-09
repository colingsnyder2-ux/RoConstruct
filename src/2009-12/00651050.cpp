// from server: 100% by nuck16
// roc 2009-12 00651050  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651050  64a100000000         mov eax, dword ptr fs:[0]
// 00651056  6aff                 push -1
// 00651058  689e289400           push 0x94289e
// 0065105d  50                   push eax
// 0065105e  b801000000           mov eax, 1
// 00651063  64892500000000       mov dword ptr fs:[0], esp
// 0065106a  840598b6b800         test byte ptr [0xb8b698], al
// 00651070  7532                 jne 0x6510a4
// 00651072  090598b6b800         or dword ptr [0xb8b698], eax
// 00651078  6a00                 push 0
// 0065107a  68347ab400           push 0xb47a34
// 0065107f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651087  e874e2ffff           call 0x64f300
// 0065108c  50                   push eax
// 0065108d  b9a0b5b800           mov ecx, 0xb8b5a0
// 00651092  e8692f0100           call 0x664000
// 00651097  6820329800           push 0x983220
// 0065109c  e888381a00           call 0x7f4929
// 006510a1  83c404               add esp, 4
// 006510a4  8b0c24               mov ecx, dword ptr [esp]
// 006510a7  b8a0b5b800           mov eax, 0xb8b5a0
// 006510ac  64890d00000000       mov dword ptr fs:[0], ecx
// 006510b3  83c40c               add esp, 0xc
// 006510b6  c3                   ret 

struct Base;
Base &get_64f300();
extern char string_00b47a34[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64f300(), string_00b47a34, 0);
    return object;
}
