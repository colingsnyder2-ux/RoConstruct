// from server: 47% by atomic.potato
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

extern "C" int* __cdecl f_0066c140();

struct SurfaceGetSet
{
    int (__thiscall *m_call)(void*, int);
    int f(void*, void*);
};

int SurfaceGetSet::f(void* a, void* b)
{
    int* p = (int*)a;
    int* q;

    if (p)
        q = f_0066c140();
    else
        q = f_0066c140();

    return m_call((void*)((char*)q + 0x28), *(int*)b);
}
