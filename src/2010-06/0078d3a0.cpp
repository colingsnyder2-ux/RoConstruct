// from server: 92% by atomic.potato
struct S_func_007637e0 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct S_func_00760c10 {
    void f(int a1);
};

struct S_func_0078d2c0 {
    void f(void *a1, void *a2);
};

struct S_func_0078d3a0 {
    char pad0[8];
    S_func_00760c10 *m_x;
    void f(S_func_0078d3a0 *a1);
};

void S_func_0078d3a0::f(S_func_0078d3a0 *a1)
{
    S_func_007637e0 *p = (S_func_007637e0 *)a1;
    p->f((int)this);
    m_x->f((int)a1);
    S_func_0078d2c0 *q = (S_func_0078d2c0 *)((char *)a1 + 8);
    q->f((void *)m_x, (void *)0x760c10);
}
