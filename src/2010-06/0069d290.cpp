// from server: 38% by atomic.potato
struct S_func_00636ea0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_00636ea0::f()
{
    return &m_x;
}

struct SurfaceGetSet {
    int pad0;
    int pad4;
    int (*callback)(float);
    void get(float*);
};

void SurfaceGetSet::get(float* value)
{
    S_func_00636ea0* p = value ? (S_func_00636ea0*)((char*)value - 0x1c) : 0;
    int* x = p ? p->f() : 0;
    callback(*value);
}
