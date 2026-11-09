// from server: 62% by atomic.potato
struct S_func_0066c140 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_0066c140::f()
{
    return &m_x;
}

struct SurfaceDescriptor {
    void f(void*, void*, void*);
};

extern "C" int* call_0066c140(S_func_0066c140*);

extern "C" void call_0075ece0(int*, void*, void*);

void SurfaceDescriptor::f(void* a, void* b, void* c)
{
    S_func_0066c140* p;
    int* q;

    if (a)
        p = (S_func_0066c140*)((char*)a - 28);
    else
        p = 0;

    q = call_0066c140(p);
    call_0075ece0(q + 8, b, c);
}
