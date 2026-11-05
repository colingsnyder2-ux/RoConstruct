// from server: 100% by nuck16
// roc 2009-12 005237b0  unit: RBX::NetworkSettings::W4PhysicsReceiveMethod::?$EnumDesc  size: 103 bytes
//
// 005237b0  64a100000000         mov eax, dword ptr fs:[0]
// 005237b6  6aff                 push -1
// 005237b8  685e889300           push 0x93885e
// 005237bd  50                   push eax
// 005237be  b801000000           mov eax, 1
// 005237c3  64892500000000       mov dword ptr fs:[0], esp
// 005237ca  840590f6b700         test byte ptr [0xb7f690], al
// 005237d0  7532                 jne 0x523804
// 005237d2  090590f6b700         or dword ptr [0xb7f690], eax
// 005237d8  6a00                 push 0
// 005237da  6898f79c00           push 0x9cf798
// 005237df  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005237e7  e894fdffff           call 0x523580
// 005237ec  50                   push eax
// 005237ed  b998f5b700           mov ecx, 0xb7f598
// 005237f2  e809081400           call 0x664000
// 005237f7  6860ff9700           push 0x97ff60
// 005237fc  e828112d00           call 0x7f4929
// 00523801  83c404               add esp, 4
// 00523804  8b0c24               mov ecx, dword ptr [esp]
// 00523807  b898f5b700           mov eax, 0xb7f598
// 0052380c  64890d00000000       mov dword ptr fs:[0], ecx
// 00523813  83c40c               add esp, 0xc
// 00523816  c3                   ret 

struct Base;
Base &get_523580();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_523580(), "GlobalSettings", 0);
    return object;
}
