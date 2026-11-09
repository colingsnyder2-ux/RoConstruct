// from server: 85% by atomic.potato
extern double g_00B5CD78;
extern "C" void __stdcall G_00977D20(double, void *, void *);

struct S
{
    void *f(void *, void *);
};

void *S::f(void *a, void *b)
{
    G_00977D20(g_00B5CD78, b, a);
    return b;
}
