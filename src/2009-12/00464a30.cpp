// from server: 100% by nuck16
// roc 2009-12 00464a30  unit: RBX::AdornG3D  size: 103 bytes
//
// 00464a30  64a100000000         mov eax, dword ptr fs:[0]
// 00464a36  6aff                 push -1
// 00464a38  687ece9200           push 0x92ce7e
// 00464a3d  50                   push eax
// 00464a3e  b801000000           mov eax, 1
// 00464a43  64892500000000       mov dword ptr fs:[0], esp
// 00464a4a  8405e8bab700         test byte ptr [0xb7bae8], al
// 00464a50  7532                 jne 0x464a84
// 00464a52  0905e8bab700         or dword ptr [0xb7bae8], eax
// 00464a58  6a00                 push 0
// 00464a5a  68ecffb300           push 0xb3ffec
// 00464a5f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00464a67  e84459faff           call 0x40a3b0
// 00464a6c  50                   push eax
// 00464a6d  b9f0b9b700           mov ecx, 0xb7b9f0
// 00464a72  e889f51f00           call 0x664000
// 00464a77  6800eb9700           push 0x97eb00
// 00464a7c  e8a8fe3800           call 0x7f4929
// 00464a81  83c404               add esp, 4
// 00464a84  8b0c24               mov ecx, dword ptr [esp]
// 00464a87  b8f0b9b700           mov eax, 0xb7b9f0
// 00464a8c  64890d00000000       mov dword ptr fs:[0], ecx
// 00464a93  83c40c               add esp, 0xc
// 00464a96  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b3ffec[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b3ffec, 0);
    return object;
}
