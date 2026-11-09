// from server: 58% by atomic.potato
extern "C" void __cdecl RenderScene(void *, void *, void *, float);

struct S
{
    void f(void *, void *, float);
};

void S::f(void *a, void *b, float c)
{
    RenderScene(this, a, b, c);
}
