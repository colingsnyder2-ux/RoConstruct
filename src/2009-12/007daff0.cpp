// from server: 88% by atomic.potato
struct S_func_007b2f20 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct S_func_007b8f00 {
    void f(int a1);
};

struct S_func_007daf10 {
    void f(int a1);
};

struct S {
    char pad0[8];
    S_func_007b8f00* m_p;
    void f(int a1);
};

void S::f(int a1)
{
    S_func_007b2f20* p = (S_func_007b2f20*)a1;
    p->f((int)this);
    m_p->f(a1);
    S_func_007daf10* q = (S_func_007daf10*)(a1 + 8);
    q->f((int)m_p);
}
