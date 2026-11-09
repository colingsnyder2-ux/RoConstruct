// from server: 100% by nuck16
// roc 2009-12 00650950  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650950  64a100000000         mov eax, dword ptr fs:[0]
// 00650956  6aff                 push -1
// 00650958  689e269400           push 0x94269e
// 0065095d  50                   push eax
// 0065095e  b801000000           mov eax, 1
// 00650963  64892500000000       mov dword ptr fs:[0], esp
// 0065096a  840598a6b800         test byte ptr [0xb8a698], al
// 00650970  7532                 jne 0x6509a4
// 00650972  090598a6b800         or dword ptr [0xb8a698], eax
// 00650978  6a00                 push 0
// 0065097a  68907fb500           push 0xb57f90
// 0065097f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650987  e8e4feffff           call 0x650870
// 0065098c  50                   push eax
// 0065098d  b9a0a5b800           mov ecx, 0xb8a5a0
// 00650992  e869360100           call 0x664000
// 00650997  6820339800           push 0x983320
// 0065099c  e8883f1a00           call 0x7f4929
// 006509a1  83c404               add esp, 4
// 006509a4  8b0c24               mov ecx, dword ptr [esp]
// 006509a7  b8a0a5b800           mov eax, 0xb8a5a0
// 006509ac  64890d00000000       mov dword ptr fs:[0], ecx
// 006509b3  83c40c               add esp, 0xc
// 006509b6  c3                   ret 

struct Base;
Base &get_650870();
extern char string_00b57f90[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_650870(), string_00b57f90, 0);
    return object;
}
