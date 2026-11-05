// from server: 83% by atomic.potato
struct SurfaceDescriptor
{
    void f(void *, void *);
};

extern "C" void *__cdecl sub_592e10(void *, void *);
extern "C" void __stdcall sub_5a8570(SurfaceDescriptor *, void *);

void SurfaceDescriptor::f(void *a, void *b)
{
    void *v = sub_592e10(&b, a);
    sub_5a8570(this, v);
}
