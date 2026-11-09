// from server: 45% by atomic.potato
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
    int m_field;
    void set(int*, float);
};

void SurfaceGetSet::set(int* object, float value)
{
    S_func_0066c140* p = (S_func_0066c140*)object;
    if (p)
        p = (S_func_0066c140*)((char*)p - 28);
    int* result = p->f();
    void (**call)(int*, float) = (void (**)(int*, float))((char*)result + 8);
    (*call)(result + 2, value);
}
