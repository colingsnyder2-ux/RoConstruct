// from server: 39% by atomic.potato
struct S_func_00750a60
{
    char pad0[436];
    int m_x;
    int* f();
};

int* S_func_00750a60::f()
{
    return &m_x;
}

struct S
{
    int f(int* a, int b, int c);
};

int S::f(int* a, int b, int c)
{
    S_func_00750a60* p;
    if (a)
        p = (S_func_00750a60*)((char*)a - 28);
    else
        p = 0;
    int* q = p->f();
    return q[b + c];
}
