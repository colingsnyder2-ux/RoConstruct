// from server: 100% by nuck16
// roc 2009-12 00523740  unit: RBX::NetworkSettings::W4PhysicsReceiveMethod::?$EnumDesc  size: 103 bytes
//
// 00523740  64a100000000         mov eax, dword ptr fs:[0]
// 00523746  6aff                 push -1
// 00523748  683e889300           push 0x93883e
// 0052374d  50                   push eax
// 0052374e  b801000000           mov eax, 1
// 00523753  64892500000000       mov dword ptr fs:[0], esp
// 0052375a  840590f5b700         test byte ptr [0xb7f590], al
// 00523760  7532                 jne 0x523794
// 00523762  090590f5b700         or dword ptr [0xb7f590], eax
// 00523768  6a00                 push 0
// 0052376a  688ccbb100           push 0xb1cb8c
// 0052376f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00523777  e8346ceeff           call 0x40a3b0
// 0052377c  50                   push eax
// 0052377d  b998f4b700           mov ecx, 0xb7f498
// 00523782  e879081400           call 0x664000
// 00523787  6870ff9700           push 0x97ff70
// 0052378c  e898112d00           call 0x7f4929
// 00523791  83c404               add esp, 4
// 00523794  8b0c24               mov ecx, dword ptr [esp]
// 00523797  b898f4b700           mov eax, 0xb7f498
// 0052379c  64890d00000000       mov dword ptr fs:[0], ecx
// 005237a3  83c40c               add esp, 0xc
// 005237a6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b1cb8c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b1cb8c, 0);
    return object;
}
