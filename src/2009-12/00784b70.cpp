// from server: 100% by atomic.potato
struct P_func_0076b750
{
    void f(int);
};

struct S_func_00784b70
{
    char pad[28];
    P_func_0076b750* m_p;
    S_func_00784b70* f(int);
};

S_func_00784b70* S_func_00784b70::f(int value)
{
    m_p->f(value);
    return this;
}
