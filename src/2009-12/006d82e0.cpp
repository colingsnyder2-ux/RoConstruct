// from server: 100% by nuck16
// roc 2009-12 006d82e0  unit: RBX::Stats::Item  size: 103 bytes
//
// 006d82e0  64a100000000         mov eax, dword ptr fs:[0]
// 006d82e6  6aff                 push -1
// 006d82e8  689ea99400           push 0x94a99e
// 006d82ed  50                   push eax
// 006d82ee  b801000000           mov eax, 1
// 006d82f3  64892500000000       mov dword ptr fs:[0], esp
// 006d82fa  8405882eb900         test byte ptr [0xb92e88], al
// 006d8300  7532                 jne 0x6d8334
// 006d8302  0905882eb900         or dword ptr [0xb92e88], eax
// 006d8308  6a00                 push 0
// 006d830a  6838919d00           push 0x9d9138
// 006d830f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006d8317  e814c7d8ff           call 0x464a30
// 006d831c  50                   push eax
// 006d831d  b9902db900           mov ecx, 0xb92d90
// 006d8322  e8d9bcf8ff           call 0x664000
// 006d8327  6820629800           push 0x986220
// 006d832c  e8f8c51100           call 0x7f4929
// 006d8331  83c404               add esp, 4
// 006d8334  8b0c24               mov ecx, dword ptr [esp]
// 006d8337  b8902db900           mov eax, 0xb92d90
// 006d833c  64890d00000000       mov dword ptr fs:[0], ecx
// 006d8343  83c40c               add esp, 0xc
// 006d8346  c3                   ret 

struct Base;
Base &get_464a30();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_464a30(), "RunningAverageItemInt", 0);
    return object;
}
