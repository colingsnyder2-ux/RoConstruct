// from server: 100% by nuck16
// roc 2009-12 00523890  unit: RBX::NetworkSettings::W4PhysicsReceiveMethod::?$EnumDesc  size: 103 bytes
//
// 00523890  64a100000000         mov eax, dword ptr fs:[0]
// 00523896  6aff                 push -1
// 00523898  689e889300           push 0x93889e
// 0052389d  50                   push eax
// 0052389e  b801000000           mov eax, 1
// 005238a3  64892500000000       mov dword ptr fs:[0], esp
// 005238aa  840590f8b700         test byte ptr [0xb7f890], al
// 005238b0  7532                 jne 0x5238e4
// 005238b2  090590f8b700         or dword ptr [0xb7f890], eax
// 005238b8  6a00                 push 0
// 005238ba  68aca0b100           push 0xb1a0ac
// 005238bf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005238c7  e824fdffff           call 0x5235f0
// 005238cc  50                   push eax
// 005238cd  b998f7b700           mov ecx, 0xb7f798
// 005238d2  e829071400           call 0x664000
// 005238d7  6840ff9700           push 0x97ff40
// 005238dc  e848102d00           call 0x7f4929
// 005238e1  83c404               add esp, 4
// 005238e4  8b0c24               mov ecx, dword ptr [esp]
// 005238e7  b898f7b700           mov eax, 0xb7f798
// 005238ec  64890d00000000       mov dword ptr fs:[0], ecx
// 005238f3  83c40c               add esp, 0xc
// 005238f6  c3                   ret 

struct Base;
Base &get_5235f0();
extern char string_00b1a0ac[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_5235f0(), string_00b1a0ac, 0);
    return object;
}
