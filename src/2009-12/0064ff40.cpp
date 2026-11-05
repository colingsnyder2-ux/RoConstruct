// from server: 100% by nuck16
// roc 2009-12 0064ff40  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064ff40  64a100000000         mov eax, dword ptr fs:[0]
// 0064ff46  6aff                 push -1
// 0064ff48  68be239400           push 0x9423be
// 0064ff4d  50                   push eax
// 0064ff4e  b801000000           mov eax, 1
// 0064ff53  64892500000000       mov dword ptr fs:[0], esp
// 0064ff5a  8405988fb800         test byte ptr [0xb88f98], al
// 0064ff60  7532                 jne 0x64ff94
// 0064ff62  0905988fb800         or dword ptr [0xb88f98], eax
// 0064ff68  6a00                 push 0
// 0064ff6a  6830e89d00           push 0x9de830
// 0064ff6f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064ff77  e8e4feffff           call 0x64fe60
// 0064ff7c  50                   push eax
// 0064ff7d  b9a08eb800           mov ecx, 0xb88ea0
// 0064ff82  e879400100           call 0x664000
// 0064ff87  6890349800           push 0x983490
// 0064ff8c  e898491a00           call 0x7f4929
// 0064ff91  83c404               add esp, 4
// 0064ff94  8b0c24               mov ecx, dword ptr [esp]
// 0064ff97  b8a08eb800           mov eax, 0xb88ea0
// 0064ff9c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ffa3  83c40c               add esp, 0xc
// 0064ffa6  c3                   ret 

struct Base;
Base &get_64fe60();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64fe60(), "RotateV", 0);
    return object;
}
