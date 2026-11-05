// from server: 27% by atomic.potato
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
    int m_value;
    void f(S_func_004e9330 *a1);
};

void S::f(S_func_004e9330 *a1)
{
    a1->f((int)this);
    m_value = (int)a1;
}
