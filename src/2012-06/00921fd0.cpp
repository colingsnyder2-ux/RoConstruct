// from server: 100% by Xemicl
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
