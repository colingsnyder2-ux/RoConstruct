// from server: 28% by atomic.potato
struct S_func_006cb2b0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_006cb2b0::f()
{
    return &m_x;
}

struct SurfaceDescriptor {
    void* f(void*, void*, void*);
};

extern "C" int* __cdecl call_006cb2b0();

void* SurfaceDescriptor::f(void* a, void* b, void* c)
{
    int* p = call_006cb2b0();
    return (void*)p;
}
