// from server: 100% by EspClaude
// roc 2009-06 006fc2e0  unit: RBX::ContactStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fc2e0
//
// 006fc2e0  56                   push esi
// 006fc2e1  57                   push edi
// 006fc2e2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006fc2e6  8bf1                 mov esi, ecx
// 006fc2e8  56                   push esi
// 006fc2e9  8bcf                 mov ecx, edi
// 006fc2eb  e88099fdff           call 0x6d5c70
// 006fc2f0  8b4e08               mov ecx, dword ptr [esi + 8]
// 006fc2f3  57                   push edi
// 006fc2f4  e857f3fdff           call 0x6db650
// 006fc2f9  5f                   pop edi
// 006fc2fa  5e                   pop esi
// 006fc2fb  c20400               ret 4
// copied from an identical function in another client (function ?f@CleanStage@ns_ROCX00000b@@QAEXPAUS_func_00645830@2@@Z)

namespace ns_ROCX00000b {
struct S_func_00645830 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct NextStage {
    void f(S_func_00645830* object);
};

struct CleanStage {
    char pad0[8];
    NextStage* next;
    void f(S_func_00645830* object);
};

void CleanStage::f(S_func_00645830* object)
{
    object->f((int)this);
    next->f(object);
}
}
