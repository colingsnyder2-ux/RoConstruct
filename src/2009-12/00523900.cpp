// from server: 100% by nuck16
// roc 2009-12 00523900  unit: RBX::NetworkSettings::W4PhysicsReceiveMethod::?$EnumDesc  size: 103 bytes
//
// 00523900  64a100000000         mov eax, dword ptr fs:[0]
// 00523906  6aff                 push -1
// 00523908  68be889300           push 0x9388be
// 0052390d  50                   push eax
// 0052390e  b801000000           mov eax, 1
// 00523913  64892500000000       mov dword ptr fs:[0], esp
// 0052391a  840590f9b700         test byte ptr [0xb7f990], al
// 00523920  7532                 jne 0x523954
// 00523922  090590f9b700         or dword ptr [0xb7f990], eax
// 00523928  6a00                 push 0
// 0052392a  68d0bdb100           push 0xb1bdd0
// 0052392f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00523937  e8b4fcffff           call 0x5235f0
// 0052393c  50                   push eax
// 0052393d  b998f8b700           mov ecx, 0xb7f898
// 00523942  e8b9061400           call 0x664000
// 00523947  6830ff9700           push 0x97ff30
// 0052394c  e8d80f2d00           call 0x7f4929
// 00523951  83c404               add esp, 4
// 00523954  8b0c24               mov ecx, dword ptr [esp]
// 00523957  b898f8b700           mov eax, 0xb7f898
// 0052395c  64890d00000000       mov dword ptr fs:[0], ecx
// 00523963  83c40c               add esp, 0xc
// 00523966  c3                   ret 

struct Base;
Base &get_5235f0();
extern char string_00b1bdd0[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_5235f0(), string_00b1bdd0, 0);
    return object;
}
