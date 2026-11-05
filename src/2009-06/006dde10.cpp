// from server: 100% by EspClaude
// roc 2009-06 006dde10  unit: RBX::StepJointsStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006dde10
//
// 006dde10  56                   push esi
// 006dde11  57                   push edi
// 006dde12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006dde16  8bf1                 mov esi, ecx
// 006dde18  8b4e08               mov ecx, dword ptr [esi + 8]
// 006dde1b  57                   push edi
// 006dde1c  e8dffcffff           call 0x6ddb00
// 006dde21  56                   push esi
// 006dde22  8bcf                 mov ecx, edi
// 006dde24  e8277effff           call 0x6d5c50
// 006dde29  5f                   pop edi
// 006dde2a  5e                   pop esi
// 006dde2b  c20400               ret 4
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
