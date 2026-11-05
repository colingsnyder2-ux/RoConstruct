// from server: 90% by atomic.potato
struct P_00910550
{
    void f(int, int, float);
};

struct S_005dca30
{
    char pad[8];
    P_00910550* m_p;
    void f(int, int, float);
};

void S_005dca30::f(int a, int b, float c)
{
    m_p->f(a, b, c);
}
