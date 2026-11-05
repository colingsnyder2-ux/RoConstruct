// from server: 64% by atomic.potato
extern "C" void __cdecl FactoryProduct(void *, void *, void *, void *, void *, void *);

void f(void *a, void *b, void *c, void *d, void *e)
{
    char x;
    FactoryProduct(&x, e, d, c, b, a);
}
