// from server: 100% by EspClaude
// roc 2009-06 006de320  unit: RBX::MovingAssemblyStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006de320
//
// 006de320  56                   push esi
// 006de321  57                   push edi
// 006de322  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006de326  8bf1                 mov esi, ecx
// 006de328  56                   push esi
// 006de329  8bcf                 mov ecx, edi
// 006de32b  e84079ffff           call 0x6d5c70
// 006de330  8b4e08               mov ecx, dword ptr [esi + 8]
// 006de333  57                   push edi
// 006de334  e867890100           call 0x6f6ca0
// 006de339  5f                   pop edi
// 006de33a  5e                   pop esi
// 006de33b  c20400               ret 4
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
