// from server: 85% by atomic.potato
struct S_func_004e9330 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct S_func_007b41b0 {
    void f(int a1);
};

struct S_func_007efc60 {
    void f(int a1, int a2);
};

struct S_MechToAssemblyStage {
    char pad0[8];
    S_func_007b41b0* m_p8;
    void f(int a1);
};

void S_MechToAssemblyStage::f(int a1)
{
    S_func_004e9330* p = (S_func_004e9330*)a1;
    p->f((int)this);
    m_p8->f(a1);
    S_func_007efc60* q = (S_func_007efc60*)(a1 + 8);
    q->f((int)m_p8, (int)m_p8);
}
