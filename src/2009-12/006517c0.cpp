// from server: 100% by nuck16
// roc 2009-12 006517c0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006517c0  64a100000000         mov eax, dword ptr fs:[0]
// 006517c6  6aff                 push -1
// 006517c8  68be2a9400           push 0x942abe
// 006517cd  50                   push eax
// 006517ce  b801000000           mov eax, 1
// 006517d3  64892500000000       mov dword ptr fs:[0], esp
// 006517da  840598c7b800         test byte ptr [0xb8c798], al
// 006517e0  7532                 jne 0x651814
// 006517e2  090598c7b800         or dword ptr [0xb8c798], eax
// 006517e8  6a00                 push 0
// 006517ea  685096b300           push 0xb39650
// 006517ef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006517f7  e8b48bdbff           call 0x40a3b0
// 006517fc  50                   push eax
// 006517fd  b9a0c6b800           mov ecx, 0xb8c6a0
// 00651802  e8f9270100           call 0x664000
// 00651807  6810319800           push 0x983110
// 0065180c  e818311a00           call 0x7f4929
// 00651811  83c404               add esp, 4
// 00651814  8b0c24               mov ecx, dword ptr [esp]
// 00651817  b8a0c6b800           mov eax, 0xb8c6a0
// 0065181c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651823  83c40c               add esp, 0xc
// 00651826  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b39650[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b39650, 0);
    return object;
}
