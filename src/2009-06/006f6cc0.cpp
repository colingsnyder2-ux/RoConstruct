// from server: 100% by EspClaude
// roc 2009-06 006f6cc0  unit: RBX::MechToAssemblyStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006f6cc0
//
// 006f6cc0  56                   push esi
// 006f6cc1  57                   push edi
// 006f6cc2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006f6cc6  8bf1                 mov esi, ecx
// 006f6cc8  8b4e08               mov ecx, dword ptr [esi + 8]
// 006f6ccb  57                   push edi
// 006f6ccc  e85f40feff           call 0x6dad30
// 006f6cd1  56                   push esi
// 006f6cd2  8bcf                 mov ecx, edi
// 006f6cd4  e877effdff           call 0x6d5c50
// 006f6cd9  5f                   pop edi
// 006f6cda  5e                   pop esi
// 006f6cdb  c20400               ret 4
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
