// from server: 35% by atomic.potato
extern "C" int* __cdecl f();

struct SurfaceDescriptor
{
    int* m_ptr;
    void f(int*, int*);
};

extern "C" void g(int*, int*);

void SurfaceDescriptor::f(int* p, int* a)
{
    int* x = p ? ::f() : 0;
    g(x + 6, a);
}
