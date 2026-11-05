// from server: 19% by atomic.potato
struct S_func_007edbd0
{
    char pad0[40];
    int m_x;
    void f(int a1);
};

void S_func_007edbd0::f(int a1)
{
    m_x = a1;
}

struct ManualGlueJoint
{
    void f(int a1);
};

void ManualGlueJoint::f(int a1)
{
    S_func_007edbd0 *p = *(S_func_007edbd0 **)this;
    int v = p->m_x;
    p->f(v);
    p->f(a1);
}
