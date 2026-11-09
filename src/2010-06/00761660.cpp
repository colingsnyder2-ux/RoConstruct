// from server: 100% by atomic.potato
struct S_func_007637e0 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct S {
    void f(S_func_007637e0 *a1);
};

void S::f(S_func_007637e0 *a1)
{
    a1->f((int)this);
}
