// from server: 100% by nuck16
// roc 2009-12 00523660  unit: RBX::NetworkSettings::W4PhysicsReceiveMethod::?$EnumDesc  size: 103 bytes
//
// 00523660  64a100000000         mov eax, dword ptr fs:[0]
// 00523666  6aff                 push -1
// 00523668  68fe879300           push 0x9387fe
// 0052366d  50                   push eax
// 0052366e  b801000000           mov eax, 1
// 00523673  64892500000000       mov dword ptr fs:[0], esp
// 0052367a  840590f3b700         test byte ptr [0xb7f390], al
// 00523680  7532                 jne 0x5236b4
// 00523682  090590f3b700         or dword ptr [0xb7f390], eax
// 00523688  6a00                 push 0
// 0052368a  6880d09b00           push 0x9bd080
// 0052368f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00523697  e8146deeff           call 0x40a3b0
// 0052369c  50                   push eax
// 0052369d  b998f2b700           mov ecx, 0xb7f298
// 005236a2  e859091400           call 0x664000
// 005236a7  6890ff9700           push 0x97ff90
// 005236ac  e878122d00           call 0x7f4929
// 005236b1  83c404               add esp, 4
// 005236b4  8b0c24               mov ecx, dword ptr [esp]
// 005236b7  b898f2b700           mov eax, 0xb7f298
// 005236bc  64890d00000000       mov dword ptr fs:[0], ecx
// 005236c3  83c40c               add esp, 0xc
// 005236c6  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "NetworkReplicator", 0);
    return object;
}
