// from server: 25% by atomic.potato
struct S_func_007b2f20
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007b2f20::f(int a1)
{
    m_x = a1;
}

struct S_func_007b9980
{
    void f(S_func_007b2f20* a1);
};

void S_func_007b9980::f(S_func_007b2f20* a1)
{
    a1->f(0);
}

struct ContactStage
{
    char pad0[8];
    S_func_007b9980* m_stage;
    void f(S_func_007b2f20* a1);
};

void ContactStage::f(S_func_007b2f20* a1)
{
    a1->f((int)this);
    m_stage->f(a1);
}
