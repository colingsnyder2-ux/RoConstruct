// from server: 100% by EspClaude
// roc 2009-06 006d8c00  unit: RBX::CleanStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d8c00
//
// 006d8c00  56                   push esi
// 006d8c01  57                   push edi
// 006d8c02  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006d8c06  8bf1                 mov esi, ecx
// 006d8c08  56                   push esi
// 006d8c09  8bcf                 mov ecx, edi
// 006d8c0b  e860d0ffff           call 0x6d5c70
// 006d8c10  8b4e08               mov ecx, dword ptr [esi + 8]
// 006d8c13  57                   push edi
// 006d8c14  e8e7c70100           call 0x6f5400
// 006d8c19  5f                   pop edi
// 006d8c1a  5e                   pop esi
// 006d8c1b  c20400               ret 4
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
