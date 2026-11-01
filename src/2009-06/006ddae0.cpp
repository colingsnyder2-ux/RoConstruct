// from server: 100% by EspClaude
// roc 2009-06 006ddae0  unit: RBX::TreeStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006ddae0
//
// 006ddae0  56                   push esi
// 006ddae1  57                   push edi
// 006ddae2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006ddae6  8bf1                 mov esi, ecx
// 006ddae8  56                   push esi
// 006ddae9  8bcf                 mov ecx, edi
// 006ddaeb  e88081ffff           call 0x6d5c70
// 006ddaf0  8b4e08               mov ecx, dword ptr [esi + 8]
// 006ddaf3  57                   push edi
// 006ddaf4  e8f78e0100           call 0x6f69f0
// 006ddaf9  5f                   pop edi
// 006ddafa  5e                   pop esi
// 006ddafb  c20400               ret 4
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
