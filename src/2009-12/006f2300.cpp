// from server: 32% by atomic.potato
struct S_func_006cb2b0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_006cb2b0::f()
{
    return &m_x;
}

struct S {
    int m_pad0[2];
    int (__thiscall *m_f)(int*, int);
    int f(int*, int*);
};

int S::f(int* a, int* b)
{
    int* p = a ? reinterpret_cast<int*>(
        reinterpret_cast<char*>(a) - 0x1c) : 0;
    S_func_006cb2b0* q = reinterpret_cast<S_func_006cb2b0*>(p);
    int* r = q ? q->f() : 0;
    return m_f(r + 6, *b);
}
