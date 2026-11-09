// from server: 35% by atomic.potato
struct S_func_00636ea0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_00636ea0::f()
{
    return &m_x;
}

struct S {
    int f(int*, int, int);
};

int S::f(int* p, int a, int b)
{
    S_func_00636ea0* q;
    if (p)
        q = (S_func_00636ea0*)((char*)p - 28);
    else
        q = 0;
    int* r = q->f();
    int* x = (int*)((char*)r + 40);
    return x[b];
}
