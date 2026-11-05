// from server: 39% by atomic.potato
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

extern "C" int* __cdecl function_0066c140();

extern "C" void __cdecl function_0075ece0(int*, void*, void*);

void SurfaceDescriptor::f(void* p1, void* p2, void* p3)
{
    int* p = (int*)p1;
    int* q = p ? (int*)((char*)p - 28) : 0;
    int* r = function_0066c140();
    function_0075ece0(r + 6, p2, p3);
}
