// from server: 100% by nuck16
// roc 2009-12 00651670  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651670  64a100000000         mov eax, dword ptr fs:[0]
// 00651676  6aff                 push -1
// 00651678  685e2a9400           push 0x942a5e
// 0065167d  50                   push eax
// 0065167e  b801000000           mov eax, 1
// 00651683  64892500000000       mov dword ptr fs:[0], esp
// 0065168a  840598c4b800         test byte ptr [0xb8c498], al
// 00651690  7532                 jne 0x6516c4
// 00651692  090598c4b800         or dword ptr [0xb8c498], eax
// 00651698  6a00                 push 0
// 0065169a  684887b300           push 0xb38748
// 0065169f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006516a7  e854ffffff           call 0x651600
// 006516ac  50                   push eax
// 006516ad  b9a0c3b800           mov ecx, 0xb8c3a0
// 006516b2  e849290100           call 0x664000
// 006516b7  6840319800           push 0x983140
// 006516bc  e868321a00           call 0x7f4929
// 006516c1  83c404               add esp, 4
// 006516c4  8b0c24               mov ecx, dword ptr [esp]
// 006516c7  b8a0c3b800           mov eax, 0xb8c3a0
// 006516cc  64890d00000000       mov dword ptr fs:[0], ecx
// 006516d3  83c40c               add esp, 0xc
// 006516d6  c3                   ret 

struct Base;
Base &get_651600();
extern char string_00b38748[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_651600(), string_00b38748, 0);
    return object;
}
