// from server: 48% by atomic.potato
struct S_func_006cb2b0
{
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_006cb2b0::f()
{
    return &m_x;
}

struct SurfaceGetSet
{
    int m_pad0;
    int m_pad1;
    int m_callback;
    void f(int*, float*);
};

void SurfaceGetSet::f(int* value, float* source)
{
    S_func_006cb2b0* object = (S_func_006cb2b0*)(value ? value - 7 : 0);
    int* result = object->f();
    int* value2 = value ? value - 7 : 0;
    float number = *source;
    int* target = result + 4;
    ((void (__thiscall *)(float*, int*))m_callback)(&number, target);
}
