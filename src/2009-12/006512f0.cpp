// from server: 100% by nuck16
// roc 2009-12 006512f0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006512f0  64a100000000         mov eax, dword ptr fs:[0]
// 006512f6  6aff                 push -1
// 006512f8  685e299400           push 0x94295e
// 006512fd  50                   push eax
// 006512fe  b801000000           mov eax, 1
// 00651303  64892500000000       mov dword ptr fs:[0], esp
// 0065130a  840598bcb800         test byte ptr [0xb8bc98], al
// 00651310  7532                 jne 0x651344
// 00651312  090598bcb800         or dword ptr [0xb8bc98], eax
// 00651318  6a00                 push 0
// 0065131a  6838479e00           push 0x9e4738
// 0065131f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651327  e88490dbff           call 0x40a3b0
// 0065132c  50                   push eax
// 0065132d  b9a0bbb800           mov ecx, 0xb8bba0
// 00651332  e8c92c0100           call 0x664000
// 00651337  68c0319800           push 0x9831c0
// 0065133c  e8e8351a00           call 0x7f4929
// 00651341  83c404               add esp, 4
// 00651344  8b0c24               mov ecx, dword ptr [esp]
// 00651347  b8a0bbb800           mov eax, 0xb8bba0
// 0065134c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651353  83c40c               add esp, 0xc
// 00651356  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "TouchTransmitter", 0);
    return object;
}
