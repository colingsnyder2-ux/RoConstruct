// from server: 55% by atomic.potato
struct S_func_006cb2b0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_006cb2b0::f()
{
    return &m_x;
}

struct SurfaceGetSet {
    int* m_callback;
    int m_value;
    int (*m_call)(int*);

    int f(int* a, int* b);
};

int SurfaceGetSet::f(int* a, int* b)
{
    int* p = a ? a - 7 : 0;
    S_func_006cb2b0* s = (S_func_006cb2b0*)p;
    int* v = s->f();
    return ((int (*)(int*, int))m_call)(v, *b);
}
