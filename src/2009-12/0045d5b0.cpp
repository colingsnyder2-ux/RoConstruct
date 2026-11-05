// from server: 100% by nuck16
// roc 2009-12 0045d5b0  unit: RBX::VInstance::?$NonFactoryProduct  size: 103 bytes
//
// 0045d5b0  64a100000000         mov eax, dword ptr fs:[0]
// 0045d5b6  6aff                 push -1
// 0045d5b8  687ec59200           push 0x92c57e
// 0045d5bd  50                   push eax
// 0045d5be  b801000000           mov eax, 1
// 0045d5c3  64892500000000       mov dword ptr fs:[0], esp
// 0045d5ca  840540b9b700         test byte ptr [0xb7b940], al
// 0045d5d0  7532                 jne 0x45d604
// 0045d5d2  090540b9b700         or dword ptr [0xb7b940], eax
// 0045d5d8  6a00                 push 0
// 0045d5da  68e4ffb300           push 0xb3ffe4
// 0045d5df  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0045d5e7  e8c4cdfaff           call 0x40a3b0
// 0045d5ec  50                   push eax
// 0045d5ed  b948b8b700           mov ecx, 0xb7b848
// 0045d5f2  e8096a2000           call 0x664000
// 0045d5f7  68b0ea9700           push 0x97eab0
// 0045d5fc  e828733900           call 0x7f4929
// 0045d601  83c404               add esp, 4
// 0045d604  8b0c24               mov ecx, dword ptr [esp]
// 0045d607  b848b8b700           mov eax, 0xb7b848
// 0045d60c  64890d00000000       mov dword ptr fs:[0], ecx
// 0045d613  83c40c               add esp, 0xc
// 0045d616  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b3ffe4[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b3ffe4, 0);
    return object;
}
