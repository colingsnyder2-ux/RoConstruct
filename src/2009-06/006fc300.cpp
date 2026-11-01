// from server: 100% by EspClaude
// roc 2009-06 006fc300  unit: RBX::ContactStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fc300
//
// 006fc300  56                   push esi
// 006fc301  57                   push edi
// 006fc302  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006fc306  8bf1                 mov esi, ecx
// 006fc308  8b4e08               mov ecx, dword ptr [esi + 8]
// 006fc30b  57                   push edi
// 006fc30c  e84ff3fdff           call 0x6db660
// 006fc311  56                   push esi
// 006fc312  8bcf                 mov ecx, edi
// 006fc314  e83799fdff           call 0x6d5c50
// 006fc319  5f                   pop edi
// 006fc31a  5e                   pop esi
// 006fc31b  c20400               ret 4
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
