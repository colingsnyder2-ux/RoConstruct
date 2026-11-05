// from server: 48% by atomic.potato
struct P_func_00798330
{
    void f(int, int);
};

struct S_func_00654350
{
    char pad[172];
    P_func_00798330* m_p;
    void f(int);
};

void S_func_00654350::f(int a)
{
    m_p->f(a, 0);
}
