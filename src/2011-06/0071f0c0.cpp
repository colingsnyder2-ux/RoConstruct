// from server: 37% by atomic.potato
struct S_func_0066c140
{
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_0066c140::f()
{
    return &m_x;
}

struct SurfaceGetSet
{
    int* m_callback;
    int get(int* a, int* b);
};

int SurfaceGetSet::get(int* a, int* b)
{
    int* p;
    int* (*fn)(int);

    if (a)
        p = a - 7;
    else
        p = 0;

    p = ((S_func_0066c140*)p)->f() + 6;
    fn = (int* (*)(int))m_callback;
    return (int)fn(*b);
}
