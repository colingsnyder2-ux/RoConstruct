// from server: 30% by atomic.potato
struct S_func_004e9330
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_004e9330::f(int a1)
{
    m_x = (int)a1;
}

struct S
{
    char pad0[8];
    S_func_004e9330* m_p;
    void f(int a1);
};

void S::f(int a1)
{
    S_func_004e9330* p = (S_func_004e9330*)a1;
    p->f((int)this);
    m_p->f(a1);
}
