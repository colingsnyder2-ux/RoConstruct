// from server: 56% by atomic.potato
struct S_func_0074a720
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void f();
};

void S_func_0074a720::f()
{
}

struct S
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    S *f(int);
};

S *S::f(int a)
{
    S_func_0074a720 *p = (S_func_0074a720 *)this;
    p->m_00 = 0xabcf1c;
    p->m_1c = 0xabcefc;
    p->f();
    if (a & 1)
        delete this;
    return this;
}
