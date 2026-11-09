// from server: 36% by atomic.potato
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
    int (*m_f)(int*, int);
    int f(int*, int*);
};

int S::f(int* a, int* b)
{
    int* p;
    if (a)
        p = reinterpret_cast<int*>(reinterpret_cast<char*>(a) - 0x1c);
    else
        p = 0;
    p = reinterpret_cast<int*>(reinterpret_cast<char*>(
        reinterpret_cast<S_func_006cb2b0*>(p)->f()) + 0x28);
    return m_f(reinterpret_cast<int*>(reinterpret_cast<char*>(b) + 0), *b);
}
