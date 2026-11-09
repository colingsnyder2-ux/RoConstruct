// from server: 46% by atomic.potato
struct S_func_0074a720 {
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

extern "C" void __cdecl f_0080a058(void *);

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
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    void f(int);
};

void S::f(int a)
{
    S *p = this;
    p->m_00 = 0xaa5c44;
    p->m_1c = 0xaa5c24;
    ((S_func_0074a720 *)p)->f();
    if (a & 1)
        f_0080a058(p);
}
