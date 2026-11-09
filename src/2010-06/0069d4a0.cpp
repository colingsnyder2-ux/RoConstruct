// from server: 28% by atomic.potato
struct S_func_0069d4a0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_0069d4a0::f()
{
    return &m_x;
}

struct SurfaceGetSet {
    int* f(int*, int*);
    int m_vtable;
};

int* SurfaceGetSet::f(int* a, int* b)
{
    S_func_0069d4a0* p;
    int* q;

    if (a)
        p = (S_func_0069d4a0*)((char*)a - 0x1c);
    else
        p = 0;

    q = p->f() + 0x20;
    return ((int* (__thiscall*)(int*, int))(*(int**)((char*)this + 8)))(q, *b);
}
