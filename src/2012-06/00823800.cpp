// from server: 38% by atomic.potato
struct S_func_00750a60 {
    char pad0[436];
    int m_x;
    int* f();
};

int* S_func_00750a60::f()
{
    return &m_x;
}

struct S {
    int m_vtable;
    int m_data;
    int (*m_call)(int*, int);
    int f(int*, int*);
};

int S::f(int* a, int* b)
{
    int* p = a ? (a - 7) : 0;
    int* q = S_func_00750a60().f();
    return m_call(q + 4, *b);
}
