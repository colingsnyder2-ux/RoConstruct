// from server: 70% by atomic.potato
struct S
{
    void __cdecl f(void *, void *, void *, void *, void *);
};

extern "C" void __cdecl sub_004adbf0(void *, void *, void *, int, float, void *);

void __cdecl S::f(void *a, void *b, void *c, void *d, void *e)
{
    sub_004adbf0(e, d, c, 6, 0.0f, b);
}
