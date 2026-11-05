// from server: 96% by atomic.potato
struct S
{
    void __cdecl f(void *);
};

extern "C" void __cdecl f_007a92d0(void *, int);
extern "C" void __cdecl f_0080a058(void *);

void __cdecl S::f(void *p)
{
    if (p)
    {
        f_007a92d0(p, *((int *)p + 3));
        f_0080a058(p);
    }
}
