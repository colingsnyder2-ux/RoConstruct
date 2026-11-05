// from server: 30% by atomic.potato
struct S_func_004e9330
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_004e9330::f(int a1)
{
    m_x = a1;
}

struct S
{
    char pad0[8];
    int m_value;
    void f(S_func_004e9330* a1);
};

void S::f(S_func_004e9330* a1)
{
    a1->f((int)this);
    ((S_func_004e9330*)m_value)->f((int)this);
}
