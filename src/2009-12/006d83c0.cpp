// from server: 100% by nuck16
// roc 2009-12 006d83c0  unit: RBX::Stats::Item  size: 103 bytes
//
// 006d83c0  64a100000000         mov eax, dword ptr fs:[0]
// 006d83c6  6aff                 push -1
// 006d83c8  68dea99400           push 0x94a9de
// 006d83cd  50                   push eax
// 006d83ce  b801000000           mov eax, 1
// 006d83d3  64892500000000       mov dword ptr fs:[0], esp
// 006d83da  84058830b900         test byte ptr [0xb93088], al
// 006d83e0  7532                 jne 0x6d8414
// 006d83e2  09058830b900         or dword ptr [0xb93088], eax
// 006d83e8  6a00                 push 0
// 006d83ea  686c919d00           push 0x9d916c
// 006d83ef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006d83f7  e834c6d8ff           call 0x464a30
// 006d83fc  50                   push eax
// 006d83fd  b9902fb900           mov ecx, 0xb92f90
// 006d8402  e8f9bbf8ff           call 0x664000
// 006d8407  6800629800           push 0x986200
// 006d840c  e818c51100           call 0x7f4929
// 006d8411  83c404               add esp, 4
// 006d8414  8b0c24               mov ecx, dword ptr [esp]
// 006d8417  b8902fb900           mov eax, 0xb92f90
// 006d841c  64890d00000000       mov dword ptr fs:[0], ecx
// 006d8423  83c40c               add esp, 0xc
// 006d8426  c3                   ret 

struct Base;
Base &get_464a30();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_464a30(), "ProfilingItem", 0);
    return object;
}
