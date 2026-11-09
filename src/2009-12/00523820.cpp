// from server: 100% by nuck16
// roc 2009-12 00523820  unit: RBX::NetworkSettings::W4PhysicsReceiveMethod::?$EnumDesc  size: 103 bytes
//
// 00523820  64a100000000         mov eax, dword ptr fs:[0]
// 00523826  6aff                 push -1
// 00523828  687e889300           push 0x93887e
// 0052382d  50                   push eax
// 0052382e  b801000000           mov eax, 1
// 00523833  64892500000000       mov dword ptr fs:[0], esp
// 0052383a  840590f7b700         test byte ptr [0xb7f790], al
// 00523840  7532                 jne 0x523874
// 00523842  090590f7b700         or dword ptr [0xb7f790], eax
// 00523848  6a00                 push 0
// 0052384a  6870bf9b00           push 0x9bbf70
// 0052384f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00523857  e8546beeff           call 0x40a3b0
// 0052385c  50                   push eax
// 0052385d  b998f6b700           mov ecx, 0xb7f698
// 00523862  e899071400           call 0x664000
// 00523867  6850ff9700           push 0x97ff50
// 0052386c  e8b8102d00           call 0x7f4929
// 00523871  83c404               add esp, 4
// 00523874  8b0c24               mov ecx, dword ptr [esp]
// 00523877  b898f6b700           mov eax, 0xb7f698
// 0052387c  64890d00000000       mov dword ptr fs:[0], ecx
// 00523883  83c40c               add esp, 0xc
// 00523886  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "NetworkSettings", 0);
    return object;
}
