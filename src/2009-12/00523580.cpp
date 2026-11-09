// from server: 100% by nuck16
// roc 2009-12 00523580  unit: RBX::NetworkSettings::W4PhysicsReceiveMethod::?$EnumDesc  size: 103 bytes
//
// 00523580  64a100000000         mov eax, dword ptr fs:[0]
// 00523586  6aff                 push -1
// 00523588  68be879300           push 0x9387be
// 0052358d  50                   push eax
// 0052358e  b801000000           mov eax, 1
// 00523593  64892500000000       mov dword ptr fs:[0], esp
// 0052359a  840590f1b700         test byte ptr [0xb7f190], al
// 005235a0  7532                 jne 0x5235d4
// 005235a2  090590f1b700         or dword ptr [0xb7f190], eax
// 005235a8  6a00                 push 0
// 005235aa  6840e79c00           push 0x9ce740
// 005235af  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005235b7  e8f46deeff           call 0x40a3b0
// 005235bc  50                   push eax
// 005235bd  b998f0b700           mov ecx, 0xb7f098
// 005235c2  e8390a1400           call 0x664000
// 005235c7  68b0ff9700           push 0x97ffb0
// 005235cc  e858132d00           call 0x7f4929
// 005235d1  83c404               add esp, 4
// 005235d4  8b0c24               mov ecx, dword ptr [esp]
// 005235d7  b898f0b700           mov eax, 0xb7f098
// 005235dc  64890d00000000       mov dword ptr fs:[0], ecx
// 005235e3  83c40c               add esp, 0xc
// 005235e6  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "ServiceProvider", 0);
    return object;
}
