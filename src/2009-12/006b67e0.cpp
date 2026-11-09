// from server: 100% by nuck16
// roc 2009-12 006b67e0  unit: RBX::Soundscape::SoundService  size: 103 bytes
//
// 006b67e0  64a100000000         mov eax, dword ptr fs:[0]
// 006b67e6  6aff                 push -1
// 006b67e8  681e879400           push 0x94871e
// 006b67ed  50                   push eax
// 006b67ee  b801000000           mov eax, 1
// 006b67f3  64892500000000       mov dword ptr fs:[0], esp
// 006b67fa  8405a01eb900         test byte ptr [0xb91ea0], al
// 006b6800  7532                 jne 0x6b6834
// 006b6802  0905a01eb900         or dword ptr [0xb91ea0], eax
// 006b6808  6a00                 push 0
// 006b680a  6868a7b300           push 0xb3a768
// 006b680f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006b6817  e8943bd5ff           call 0x40a3b0
// 006b681c  50                   push eax
// 006b681d  b9a81db900           mov ecx, 0xb91da8
// 006b6822  e8d9d7faff           call 0x664000
// 006b6827  6890579800           push 0x985790
// 006b682c  e8f8e01300           call 0x7f4929
// 006b6831  83c404               add esp, 4
// 006b6834  8b0c24               mov ecx, dword ptr [esp]
// 006b6837  b8a81db900           mov eax, 0xb91da8
// 006b683c  64890d00000000       mov dword ptr fs:[0], ecx
// 006b6843  83c40c               add esp, 0xc
// 006b6846  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b3a768[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b3a768, 0);
    return object;
}
