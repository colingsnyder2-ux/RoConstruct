// from server: 45% by atomic.potato
struct S_func_007637e0
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007637e0::f(int a1)
{
    m_x = a1;
}

extern "C" void f_0078b6e0(int, int);

struct S
{
    void f(int);
};

void S::f(int a1)
{
    S_func_007637e0* p = (S_func_007637e0*)a1;
    p->f((int)this);
    f_0078b6e0(*(int*)((char*)this + 8), a1);
}
