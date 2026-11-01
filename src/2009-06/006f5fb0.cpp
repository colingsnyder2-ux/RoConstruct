// from server: 100% by EspClaude
// roc 2009-06 006f5fb0  unit: RBX::EdgeStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006f5fb0
//
// 006f5fb0  56                   push esi
// 006f5fb1  57                   push edi
// 006f5fb2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006f5fb6  8bf1                 mov esi, ecx
// 006f5fb8  56                   push esi
// 006f5fb9  8bcf                 mov ecx, edi
// 006f5fbb  e8b0fcfdff           call 0x6d5c70
// 006f5fc0  8b4e08               mov ecx, dword ptr [esi + 8]
// 006f5fc3  57                   push edi
// 006f5fc4  e817630000           call 0x6fc2e0
// 006f5fc9  5f                   pop edi
// 006f5fca  5e                   pop esi
// 006f5fcb  c20400               ret 4
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
