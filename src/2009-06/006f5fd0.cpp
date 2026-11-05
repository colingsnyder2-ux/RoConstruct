// from server: 100% by EspClaude
// roc 2009-06 006f5fd0  unit: RBX::EdgeStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006f5fd0
//
// 006f5fd0  56                   push esi
// 006f5fd1  57                   push edi
// 006f5fd2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006f5fd6  8bf1                 mov esi, ecx
// 006f5fd8  8b4e08               mov ecx, dword ptr [esi + 8]
// 006f5fdb  57                   push edi
// 006f5fdc  e81f630000           call 0x6fc300
// 006f5fe1  56                   push esi
// 006f5fe2  8bcf                 mov ecx, edi
// 006f5fe4  e867fcfdff           call 0x6d5c50
// 006f5fe9  5f                   pop edi
// 006f5fea  5e                   pop esi
// 006f5feb  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX00000c@@QAEXPAUS_func_00645820@2@@Z)

namespace ns_ROCX00000c {
struct S_func_00645820 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct S_func_00668850 {
    void f(S_func_00645820* a1);
};

struct S {
    char pad0[8];
    S_func_00668850* member;
    void f(S_func_00645820* a1);
};

void S::f(S_func_00645820* a1)
{
    member->f(a1);
    a1->f((int)this);
}
}
