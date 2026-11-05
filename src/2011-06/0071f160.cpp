// from server: 72% by atomic.potato
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

extern "C" int* __cdecl f_0066c140(int*);

struct SurfaceGetSet
{
    int m_pad0;
    int m_pad1;
    int (__thiscall *m_function)(int*, int);

    int f(int* value, int* argument);
};

int SurfaceGetSet::f(int* value, int* argument)
{
    int* object;
    int* result;

    if (value)
        object = (int*)((char*)value - 28);
    else
        object = 0;

    result = f_0066c140(object);
    object = (int*)((char*)result + 32);

    return m_function(object, *argument);
}
