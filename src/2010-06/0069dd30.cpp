// from server: 44% by atomic.potato
struct S_func_00636ea0
{
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_00636ea0::f()
{
    return &m_x;
}

struct SurfaceDescriptor
{
    void* f(void*, void*, void*);
};

int* call_00636ea0();

void* call_00718ba0(int*, int*);

void* SurfaceDescriptor::f(void* a, void* b, void* c)
{
    int* p = a ? (int*)((char*)a - 28) : 0;
    int* q = call_00636ea0();
    q = (int*)((char*)q + 16);
    return call_00718ba0((int*)b, (int*)c);
}
