// from server: 68% by atomic.potato
struct S_func_00750a60 {
    char pad0[436];
    int m_x;
    int* f();
};

int* S_func_00750a60::f()
{
    return &m_x;
}

struct SurfaceGetSet {
    int field0;
    int field1;
    void f(int*, float*);
};

void SurfaceGetSet::f(int* p, float* value)
{
    S_func_00750a60* obj;
    if (p)
        obj = (S_func_00750a60*)((char*)p - 28);
    else
        obj = 0;

    int* x = obj->f();
    ((void (__thiscall*)(S_func_00750a60*, int*, float))(*(int**)((char*)this + 8)))(obj, x + 6, *value);
}
