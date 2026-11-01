// from server: 100% by EspClaude
// roc 2009-06 006f6ca0  unit: RBX::MechToAssemblyStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006f6ca0
//
// 006f6ca0  56                   push esi
// 006f6ca1  57                   push edi
// 006f6ca2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006f6ca6  8bf1                 mov esi, ecx
// 006f6ca8  56                   push esi
// 006f6ca9  8bcf                 mov ecx, edi
// 006f6cab  e8c0effdff           call 0x6d5c70
// 006f6cb0  8b4e08               mov ecx, dword ptr [esi + 8]
// 006f6cb3  57                   push edi
// 006f6cb4  e85740feff           call 0x6dad10
// 006f6cb9  5f                   pop edi
// 006f6cba  5e                   pop esi
// 006f6cbb  c20400               ret 4
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
