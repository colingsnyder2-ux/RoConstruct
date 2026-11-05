// from server: 100% by EspClaude
// roc 2009-06 006dddf0  unit: RBX::StepJointsStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006dddf0
//
// 006dddf0  56                   push esi
// 006dddf1  57                   push edi
// 006dddf2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006dddf6  8bf1                 mov esi, ecx
// 006dddf8  56                   push esi
// 006dddf9  8bcf                 mov ecx, edi
// 006dddfb  e8707effff           call 0x6d5c70
// 006dde00  8b4e08               mov ecx, dword ptr [esi + 8]
// 006dde03  57                   push edi
// 006dde04  e8d7fcffff           call 0x6ddae0
// 006dde09  5f                   pop edi
// 006dde0a  5e                   pop esi
// 006dde0b  c20400               ret 4
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
