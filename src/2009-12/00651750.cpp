// from server: 100% by nuck16
// roc 2009-12 00651750  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00651750  64a100000000         mov eax, dword ptr fs:[0]
// 00651756  6aff                 push -1
// 00651758  689e2a9400           push 0x942a9e
// 0065175d  50                   push eax
// 0065175e  b801000000           mov eax, 1
// 00651763  64892500000000       mov dword ptr fs:[0], esp
// 0065176a  840598c6b800         test byte ptr [0xb8c698], al
// 00651770  7532                 jne 0x6517a4
// 00651772  090598c6b800         or dword ptr [0xb8c698], eax
// 00651778  6a00                 push 0
// 0065177a  68982bb400           push 0xb42b98
// 0065177f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651787  e8248cdbff           call 0x40a3b0
// 0065178c  50                   push eax
// 0065178d  b9a0c5b800           mov ecx, 0xb8c5a0
// 00651792  e869280100           call 0x664000
// 00651797  6820319800           push 0x983120
// 0065179c  e888311a00           call 0x7f4929
// 006517a1  83c404               add esp, 4
// 006517a4  8b0c24               mov ecx, dword ptr [esp]
// 006517a7  b8a0c5b800           mov eax, 0xb8c5a0
// 006517ac  64890d00000000       mov dword ptr fs:[0], ecx
// 006517b3  83c40c               add esp, 0xc
// 006517b6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b42b98[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b42b98, 0);
    return object;
}
