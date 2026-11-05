// from server: 100% by nuck16
// roc 2009-12 005236d0  unit: RBX::NetworkSettings::W4PhysicsReceiveMethod::?$EnumDesc  size: 103 bytes
//
// 005236d0  64a100000000         mov eax, dword ptr fs:[0]
// 005236d6  6aff                 push -1
// 005236d8  681e889300           push 0x93881e
// 005236dd  50                   push eax
// 005236de  b801000000           mov eax, 1
// 005236e3  64892500000000       mov dword ptr fs:[0], esp
// 005236ea  840590f4b700         test byte ptr [0xb7f490], al
// 005236f0  7532                 jne 0x523724
// 005236f2  090590f4b700         or dword ptr [0xb7f490], eax
// 005236f8  6a00                 push 0
// 005236fa  68c8e89b00           push 0x9be8c8
// 005236ff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00523707  e8446ceeff           call 0x40a350
// 0052370c  50                   push eax
// 0052370d  b998f3b700           mov ecx, 0xb7f398
// 00523712  e8e9081400           call 0x664000
// 00523717  6880ff9700           push 0x97ff80
// 0052371c  e808122d00           call 0x7f4929
// 00523721  83c404               add esp, 4
// 00523724  8b0c24               mov ecx, dword ptr [esp]
// 00523727  b898f3b700           mov eax, 0xb7f398
// 0052372c  64890d00000000       mov dword ptr fs:[0], ecx
// 00523733  83c40c               add esp, 0xc
// 00523736  c3                   ret 

struct Base;
Base &get_40a350();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a350(), "NetworkMarker", 0);
    return object;
}
