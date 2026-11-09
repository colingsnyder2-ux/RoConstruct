// from server: 78% by atomic.potato
struct P_0071a250
{
    virtual int f();
    char pad[4];
    P_0071a250* next;
};

struct S_0071a250
{
    char pad[216];
    P_0071a250* m_p;
    void f();
};

void S_0071a250::f()
{
    P_0071a250* p = m_p;
    while (p->f() != 5)
        p = p->next;
}
