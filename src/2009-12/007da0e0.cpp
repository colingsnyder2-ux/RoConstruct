// from server: 25% by atomic.potato
struct S_func_007b2f20
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007b2f20::f(int a1)
{
    m_x = (int)a1;
}

struct EdgeStage
{
    char pad0[8];
    S_func_007b2f20* m_stage;
    void f(int a1);
};

void EdgeStage::f(int a1)
{
    S_func_007b2f20 local;
    local.f(a1);
    m_stage->f(a1);
}
