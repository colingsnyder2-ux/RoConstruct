// from server: 100% by nuck16
// roc 2009-12 005235f0  unit: RBX::NetworkSettings::W4PhysicsReceiveMethod::?$EnumDesc  size: 103 bytes
//
// 005235f0  64a100000000         mov eax, dword ptr fs:[0]
// 005235f6  6aff                 push -1
// 005235f8  68de879300           push 0x9387de
// 005235fd  50                   push eax
// 005235fe  b801000000           mov eax, 1
// 00523603  64892500000000       mov dword ptr fs:[0], esp
// 0052360a  840590f2b700         test byte ptr [0xb7f290], al
// 00523610  7532                 jne 0x523644
// 00523612  090590f2b700         or dword ptr [0xb7f290], eax
// 00523618  6a00                 push 0
// 0052361a  68f0e39b00           push 0x9be3f0
// 0052361f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00523627  e8846deeff           call 0x40a3b0
// 0052362c  50                   push eax
// 0052362d  b998f1b700           mov ecx, 0xb7f198
// 00523632  e8c9091400           call 0x664000
// 00523637  68a0ff9700           push 0x97ffa0
// 0052363c  e8e8122d00           call 0x7f4929
// 00523641  83c404               add esp, 4
// 00523644  8b0c24               mov ecx, dword ptr [esp]
// 00523647  b898f1b700           mov eax, 0xb7f198
// 0052364c  64890d00000000       mov dword ptr fs:[0], ecx
// 00523653  83c40c               add esp, 0xc
// 00523656  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "NetworkPeer", 0);
    return object;
}
