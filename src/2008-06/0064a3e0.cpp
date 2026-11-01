// from server: 100% by king_originala
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
