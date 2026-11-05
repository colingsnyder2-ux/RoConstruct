// from server: 100% by EspClaude
// roc 2009-06 006de340  unit: RBX::MovingAssemblyStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006de340
//
// 006de340  56                   push esi
// 006de341  57                   push edi
// 006de342  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006de346  8bf1                 mov esi, ecx
// 006de348  8b4e08               mov ecx, dword ptr [esi + 8]
// 006de34b  57                   push edi
// 006de34c  e86f890100           call 0x6f6cc0
// 006de351  56                   push esi
// 006de352  8bcf                 mov ecx, edi
// 006de354  e8e778ffff           call 0x6d5c40
// 006de359  5f                   pop edi
// 006de35a  5e                   pop esi
// 006de35b  c20400               ret 4
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
