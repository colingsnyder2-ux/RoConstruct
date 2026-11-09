// from server: 100% by nuck16
// roc 2009-12 006b6920  unit: RBX::Soundscape::W4ReverbType::?$EnumDesc  size: 103 bytes
//
// 006b6920  64a100000000         mov eax, dword ptr fs:[0]
// 006b6926  6aff                 push -1
// 006b6928  685e879400           push 0x94875e
// 006b692d  50                   push eax
// 006b692e  b801000000           mov eax, 1
// 006b6933  64892500000000       mov dword ptr fs:[0], esp
// 006b693a  8405a01fb900         test byte ptr [0xb91fa0], al
// 006b6940  7532                 jne 0x6b6974
// 006b6942  0905a01fb900         or dword ptr [0xb91fa0], eax
// 006b6948  6a00                 push 0
// 006b694a  685ca7b300           push 0xb3a75c
// 006b694f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006b6957  e884feffff           call 0x6b67e0
// 006b695c  50                   push eax
// 006b695d  b9a81eb900           mov ecx, 0xb91ea8
// 006b6962  e899d6faff           call 0x664000
// 006b6967  68a0579800           push 0x9857a0
// 006b696c  e8b8df1300           call 0x7f4929
// 006b6971  83c404               add esp, 4
// 006b6974  8b0c24               mov ecx, dword ptr [esp]
// 006b6977  b8a81eb900           mov eax, 0xb91ea8
// 006b697c  64890d00000000       mov dword ptr fs:[0], ecx
// 006b6983  83c40c               add esp, 0xc
// 006b6986  c3                   ret 

struct Base;
Base &get_6b67e0();
extern char string_00b3a75c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_6b67e0(), string_00b3a75c, 0);
    return object;
}
