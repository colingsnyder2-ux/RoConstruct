// from server: 81% by atomic.potato
extern "C" void *__cdecl func_0054d2b0(void *);
extern "C" void __cdecl func_0076a190(void *, void *);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    void *v = func_0054d2b0((char *)p + 4);
    void *x = *(void **)v;
    func_0076a190(this, &x);
}
